#include <bits/stdc++.h>

using namespace std;

int N;
map<vector<int>, int> cache;

void answer(vector<int> s, char c)
{
    printf("%c %d\n", c, (int)s.size());
    for(int i = 0; i < (int)s.size(); i++)
    {
        if(i > 0)
        {
            printf(" ");
        }
        printf("%d", s[i]);
    }
    printf("\n");
}

void getN()
{
    scanf("%d", &N);
    cache.clear();
}

int query(vector<int> s)
{
    if(s.size() <= 1)
    {
        return 0;
    }
    if(cache.count(s))
    {
        return cache[s];
    }
    printf("? %d\n", (int)s.size());
    for(int i = 0; i < (int)s.size(); i++)
    {
        if(i > 0)
        {
            printf(" ");
        }
        printf("%d", s[i]);
    }
    printf("\n");
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    return cache[s] = ans;
}

int find_edge(vector<int> startVertex, vector<int> unknownSet)
{
    assert(unknownSet.size() > 0);
    int n = unknownSet.size();
    if(n == 1)
    {
        startVertex.push_back(unknownSet[0]);
        if(query(startVertex))
        {
            return unknownSet[0];
        }
        return -1;
    }
    vector<int> half;
    for(int i = 0; i < n/2; i++)
    {
        half.push_back(unknownSet[i]);
    }
    int ret1 = query(half);
    for(int i = 0; i < (int)startVertex.size(); i++)
    {
        half.push_back(startVertex[i]);
    }
    int ret2 = query(half);
    for(int i = 0; i < (int)startVertex.size(); i++)
    {
        half.pop_back();
    }
    if(ret1 < ret2)
    {
        return find_edge(startVertex, half);
    }
    vector<int> otherHalf;
    for(int i = n/2; i < n; i++)
    {
        otherHalf.push_back(unknownSet[i]);
    }
    return find_edge(startVertex, otherHalf);
}

int find_edge(int startVertex, vector<int> unknownSet)
{
    return find_edge((vector<int>){startVertex}, unknownSet);
}

int between_edges(vector<int> set1, vector<int> set2)
{
    vector<int> all = set1;
    all.insert(all.end(), set2.begin(), set2.end());
    return query(all) - query(set1) - query(set2);
}

int id[1000];
int p[1000];
int d[1000];

void solve()
{
    getN();
    vector<int> unexplored;
    vector<pair<int, int>> Q;
    for(int i = 2; i <= N; i++)
    {
        unexplored.push_back(i);
    }
    Q.push_back({1, 0});
    for(int i = 1; i <= N; i++)
    {
        id[i] = -1;
    }
    p[1] = 1;
    d[1] = 0;
    for(int i = 0; i < (int)Q.size(); i++)
    {
        int u = Q[i].first;
        int c = Q[i].second;
        int n = between_edges({u}, unexplored);
        id[u] = c;
        while(n--)
        {
            int v = find_edge(u, unexplored);
            unexplored.erase(find(unexplored.begin(), unexplored.end(), v));
            Q.push_back({v, c^1});
            p[v] = u;
            d[v] = d[u] + 1;
        }
    }
    assert((int)Q.size() == N);
    vector<int> s1, s2;
    for(int i = 1; i<= N; i++)
    {
        if(id[i] == 0)
        {
            s1.push_back(i);
        }
        else
        {
            s2.push_back(i);
        }
    }
    if(query(s1) == 0 && query(s2) == 0)
    {
        answer(s1, 'Y');
    }
    else
    {
        if(query(s1) == 0)
        {
            swap(s1, s2);
        }
        assert(s1.size() >= 2);
        while(s1.size() >= 2)
        {
            vector<int> firstHalf, secondHalf;
            int n = s1.size();
            for(int i = 0; i < n/2; i++)
            {
                firstHalf.push_back(s1[i]);
            }
            for(int i = n/2; i < n; i++)
            {
                secondHalf.push_back(s1[i]);
            }
            if(firstHalf.size() >= 2 && query(firstHalf) != 0)
            {
                s1 = firstHalf;
            }
            else if(secondHalf.size() >= 2 && query(secondHalf) != 0)
            {
                s1 = secondHalf;                
            }
            else
            {
                int u = find_edge(firstHalf, secondHalf);
                assert(u != -1);
                int v = find_edge(u, firstHalf);
                assert(v != -1);
                vector<int> ansl, ansr;
                while(u != v)
                {
                    if(d[u] > d[v])
                    {
                        ansl.push_back(u);
                        u = p[u];
                    }
                    else
                    {
                        ansr.push_back(v);
                        v = p[v];
                    }
                }
                vector<int> ans = ansl;
                ans.push_back(v);
                ans.insert(ans.end(), ansr.rbegin(), ansr.rend());
                answer(ans, 'N');
                break;
            }
        }
    }
}

int main()
{
    solve();
    return 0;
}