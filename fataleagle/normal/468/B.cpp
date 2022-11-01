#include <bits/stdc++.h>

using namespace std;

int N, A, B;
int P[100000];
unordered_set<int> all;
unordered_map<int, int> rev;
unordered_map<int, vector<int>> adj;
vector<int> one;
char ans[100000];

int main()
{
    scanf("%d%d%d", &N, &A, &B);
    for(int i=0; i<N; i++)
        scanf("%d", P+i), all.insert(P[i]), rev[P[i]]=i;
    if(A==B)
    {
        for(int i=0; i<N; i++)
            if(!all.count(A-P[i]))
            {
                printf("NO\n");
                return 0;
            }
        printf("YES\n");
        for(int i=0; i<N; i++)
            printf("0%c", " \n"[i==N-1]);
        return 0;
    }
    for(int i=0; i<N; i++)
    {
        if(all.count(A-P[i]))
            adj[P[i]].push_back(A-P[i]);
        if(all.count(B-P[i]))
            adj[P[i]].push_back(B-P[i]);
        if(adj[P[i]].empty())
        {
            printf("NO\n");
            return 0;
        }
        if(adj[P[i]].size()==1)
            one.push_back(P[i]);
    }
    for(size_t i=0; i<one.size(); i++)
    {
        if(!all.count(one[i]))
            continue;
        if(adj[one[i]].empty())
        {
            printf("NO\n");
            return 0;
        }
        if(one[i]==adj[one[i]][0])
        {
            all.erase(one[i]);
            ans[rev[one[i]]]=one[i]*2==A?'0':'1';
            continue;
        }
        all.erase(one[i]);
        all.erase(adj[one[i]][0]);
        ans[rev[one[i]]]=(A-one[i]==adj[one[i]][0])?'0':'1';
        ans[rev[adj[one[i]][0]]]=ans[rev[one[i]]];
        for(auto it: adj[adj[one[i]][0]])
            if(it!=one[i])
            {
                adj[it].erase(find(adj[it].begin(), adj[it].end(), adj[one[i]][0]));
                if(adj[it].size()<=1)
                    one.push_back(it);
            }
    }
    printf("YES\n");
    for(int i=0; i<N; i++)
        printf("%c%c", ans[i], " \n"[i==N-1]);
    return 0;
}