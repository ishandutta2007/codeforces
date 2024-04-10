#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <utility>
#define N 500020
using namespace std;

class Question
{
public:
    int i;
    vector<int> v;
};

vector<int> k, g[N];
vector<Question> e[N];
vector<pair<int, int> > r;
int u[N], v[N], w[N];
int f[N];
bool o[N];

int GetUFS(int x)
{
    int i;

    for(i = x; f[i] > -1; i = f[i])
        ;

    return i;
}

bool MergeUFS(int u, int v)
{
    int p, q;

    p = GetUFS(u);
    q = GetUFS(v);
    if(p == q)
        return false;

    if(f[p] > f[q])
        swap(p, q);
    r.push_back(make_pair(p, f[p]));
    f[p] = f[p] + f[q];
    r.push_back(make_pair(q, f[q]));
    f[q] = p;

    return true;
}

int main(void)
{
    int n, m, q, c, x;
    int i, j, t;

    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i ++)
        f[i] = -1;

    for(i = 0; i < m; i ++)
    {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
        u[i] --;
        v[i] --;
        k.push_back(w[i]);
        g[w[i]].push_back(i);
    }
    scanf("%d", &q);
    for(i = 0; i < q; i ++)
    {
        o[i] = true;
        scanf("%d", &c);
        while(c --)
        {
            scanf("%d", &x);
            x --;
            if(e[w[x]].empty() || e[w[x]].back().i != i)
            {
                e[w[x]].push_back(Question());
                e[w[x]].back().i = i;
            }
            e[w[x]].back().v.push_back(x);
        }
    }

    sort(k.begin(), k.end());
    k.erase(unique(k.begin(), k.end()), k.end());
    for(i = 0; i < (signed)k.size(); i ++)
    {
        for(j = 0; j < (signed)e[k.at(i)].size(); j ++)
        {
            r.clear();
            if(o[e[k.at(i)].at(j).i])
                for(t = 0; t < (signed)e[k.at(i)].at(j).v.size(); t ++)
                    if(!MergeUFS(u[e[k.at(i)].at(j).v.at(t)], v[e[k.at(i)].at(j).v.at(t)]))
                    {
                        // printf("when try to %d %d\n", u[e[k.at(i)].at(j).v.at(t)], v[e[k.at(i)].at(j).v.at(t)]);
                        // printf("set ques %d to false\n", e[k.at(i)].at(j).i);
                        o[e[k.at(i)].at(j).i] = false;
                        break;
                    }

            for(t = 0; t < (signed)r.size(); t ++)
                f[r.at(t).first] = r.at(t).second;
        }

        // puts("try to merge");
        for(j = 0; j < (signed)g[k.at(i)].size(); j ++)
            MergeUFS(u[g[k.at(i)].at(j)], v[g[k.at(i)].at(j)]);
    }

    for(i = 0; i < q; i ++)
        printf("%s\n", o[i] ? "YES" : "NO");

    return 0;
}