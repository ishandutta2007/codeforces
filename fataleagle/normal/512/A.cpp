#include <bits/stdc++.h>

using namespace std;

int N;
string S[100];
string T[100];
vector<int> adj[26];
int flag[26];
vector<int> order;

void dfs(int u)
{
    flag[u]=1;
    for(auto& v: adj[u])
        if(flag[v]==0)
        {
            dfs(v);
        }
        else if(flag[v]==1)
        {
            printf("Impossible\n");
            exit(0);
        }
    flag[u]=2;
    order.push_back(u);
}

int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
        cin>>S[i];
    for(int i=0; i<N; i++)
    {
        for(int j=i+1; j<N; j++)
        {
            int k=0;
            int mini=min(S[i].length(), S[j].length());
            for(; k<mini; k++)
                if(S[i][k]!=S[j][k])
                    break;
            if(k==mini)
                continue;
            adj[S[i][k]-'a'].push_back(S[j][k]-'a');
        }
    }
    for(int i=0; i<26; i++)
        if(!flag[i])
            dfs(i);
    reverse(order.begin(), order.end());
    int inv[26];
    for(int i=0; i<26; i++)
        inv[order[i]]=i;
    for(int i=0; i<N; i++)
        for(auto& it: S[i])
            T[i]+=inv[it-'a']+'a';
    for(int i=1; i<N; i++)
        if(!(T[i-1]<T[i]))
            return printf("Impossible\n"), 0;
    for(auto& it: order)
        printf("%c", it+'a');
    printf("\n");
    return 0;
}