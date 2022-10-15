/*
    Manthan 16 F: The Chocolate Spree
    By alex256
*/
#include <iostream>
#include <vector>
#define int long long /* Don't forget we need to use long long! */

using namespace std;

/* Some input functions... */

int getInt()
{
    int n; cin >> n; return n;
}

vector<int> getVector(int n)
{
    vector<int> v(n);
    for (int i = 0; i < n; i++) v[i] = getInt();
    return v;
}

vector < vector<int> > getGraph(int n, int m)
{
    vector < vector<int> > g(n);
    for (int i = 0; i < m; i++)
    {
        int a = getInt() - 1, b = getInt() - 1;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    return g;
}

int n = getInt();
vector <int> cnt = getVector(n);
vector < vector<int> > g = getGraph(n, n - 1);
vector <int> path1(n), path2(n), path2p(n), ppath(n), maindp(n);

/*
    Input and DPs declarations:
        path1[v] -> maximum path from v to some vertex in the v's subtree.
        path2[v] -> maximum path between two vertexes in the v's subtree that contains vertex v.
        path2p[v] -> maximum path between two vertexes in the v's subtree.
        ppath[v] -> maximum path between v and some vertex not in the v's subtree.
        maindp[v] -> main DP to keep the answer.
*/

void dfs1(int v = 0, int p = -1) /* Counting path1[v], path2[v] and path2p[v] */
{
     path1[v] = cnt[v];
     path2[v] = cnt[v];
     int max1 = 0, max2 = 0, mp2p = 0;
     for (int i = 0; i < g[v].size(); i++)
     {
         int to = g[v][i];
         if (to == p) continue;
         dfs1(to, v);

         max2 = max(max2, path1[to]);
         if (max2 > max1) swap(max2, max1);
         mp2p = max(mp2p, path2p[to]);
     }
     path1[v] += max1;
     path2[v] += max1 + max2;
     path2p[v] = max(mp2p, path2[v]);
}

void dfs2(int v = 0, int p = -1) /* Counting ppath[v] */
{
     if (p >= 0) ppath[v] = max(ppath[v], ppath[p]);
     ppath[v] += cnt[v];
     int max1 = 0, max2 = 0;
     for (int i = 0; i < g[v].size(); i++)
     {
         int to = g[v][i];
         if (to == p) continue;
         max2 = max(max2, path1[to]);
         if (max2 > max1) swap(max2, max1);
     }
     for (int i = 0; i < g[v].size(); i++)
     {
         int to = g[v][i];
         if (to == p) continue;
         if (path1[to] == max1) ppath[to] = max2;
            else ppath[to] = max1;
         ppath[to] += cnt[v];
         dfs2(to, v);
     }
}

void dfs3(int v = 0, int p = -1) /* Counting maindp */
{
     maindp[v] = 0;
     int max1, max2, max3;
     /* Let's recount maindp for v's children... */
     for (int i = 0; i < g[v].size(); i++)
     {
         int to = g[v][i];
         if (to == p) continue;
         dfs3(to, v);
     }
     /* Now, there are 4 tricky cases. */
     /*
      Case #1:

      One of the paths has one vertex in v's subtree and the other one is not in v's subtree.
      The second one is fully in v's subtree.

        /\
       /  \
       \   O
         /\ \

     */
     int case1 = 0;
     max1 = 0, max2 = 0;
     for (int i = 0; i < g[v].size(); i++)
     {
         int to = g[v][i];
         if (to == p) continue;
         max2 = max(max2, path2p[to]);
         if (max2 > max1) swap(max2, max1);
     }
     for (int i = 0; i < g[v].size(); i++)
     {
         int to = g[v][i];
         if (to == p) continue;
         if (path2p[to] == max1) case1 = max(case1, path1[to] + max2);
            else case1 = max(case1, path1[to] + max1);
     }
     case1 += ppath[v];
     /*
      Case #2:

        All the paths are in v's subtree and don't contain v.

          O
        /\ /\

     */
     int case2 = 0;
     max1 = 0, max2 = 0;
     for (int i = 0; i < g[v].size(); i++)
     {
         int to = g[v][i];
         if (to == p) continue;
         max2 = max(max2, path2p[to]);
         if (max2 > max1) swap(max2, max1);
     }
     case2 = max1 + max2;
     /*
      Case #3:

        All the paths are in v's subtree. One of them contains v.

         O
        / \
        /\

     */
     int case3 = 0;
     max1 = 0, max2 = 0, max3 = 0;
     for (int i = 0; i < g[v].size(); i++)
     {
         int to = g[v][i];
         if (to == p) continue;
         max3 = max(max3, path1[to]);
         if (max3 > max2) swap(max3, max2);
         if (max2 > max1) swap(max2, max1);
     }
     for (int i = 0; i < g[v].size(); i++)
     {
         int to = g[v][i];
         if (to == p) continue;
         if (path1[to] == max1) case3 = max(case3, path2p[to] + max2 + max3);
            else if (path1[to] == max2) case3 = max(case3, path2p[to] + max1 + max3);
                    else case3 = max(case3, path2p[to] + max1 + max2);
     }
     case3 += cnt[v];
     /*
      Case #4:

       The answer for our maindp is in one of the children.

     */
     int case4 = 0;
     for (int i = 0; i < g[v].size(); i++)
     {
         int to = g[v][i];
         if (to == p) continue;
         case4 = max(case4, maindp[to]);
     }
     /* Finally, the answer for our maindp is maximum of all the cases */
     maindp[v] = max( max(case1, case2), max(case3, case4) );
}

main()
{
    /* Launching DFS to calc our DPs... */
    dfs1(); dfs2(); dfs3();
    /* After we've counted them, just print the answer. */
    cout << maindp[0];
}