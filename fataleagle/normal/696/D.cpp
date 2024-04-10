#include <bits/stdc++.h>

using namespace std;

int N, M;

struct matrix
{
    long long data[201][201];
    matrix multiply(const matrix& other)
    {
        matrix ret;
        for(int i=0; i<=M; i++)
            for(int j=0; j<=M; j++)
            {
                ret.data[i][j]=-0x3f3f3f3f3f3f3f3fLL;
                for(int k=0; k<=M; k++)
                    ret.data[i][j]=max(ret.data[i][j], data[i][k]+other.data[k][j]);
            }
        return ret;
    }
};

long long L;
int A[200];
long long G[201][201];
char S[200][201];
int trie[201][26];
int val[201];
int fail[201];
string seq;

int find_node(const char T[])
{
    int n=strlen(T);
    int cur=0;
    for(int i=0; i<n; i++)
    {
        int x=T[i]-'a';
        if(trie[cur][x]==-1)
            return -1;
        cur=trie[cur][x];
    }
    return cur;
}

void dfs(int u)
{
    if(u==0)
        fail[u]=0;
    else
    {
        for(int i=1; i<(int)seq.length(); i++)
        {
            int x=find_node(seq.c_str()+i);
            if(x!=-1)
            {
                fail[u]=x;
                break;
            }
        }
    }
    for(int i=0; i<26; i++) if(trie[u][i]!=-1)
    {
        seq+=i+'a';
        dfs(trie[u][i]);
        seq.pop_back();
    }
}

int main()
{
    memset(trie, -1, sizeof trie);
    scanf("%d%lld", &N, &L);
    for(int i=0; i<N; i++)
        scanf("%d", A+i);
    for(int i=0; i<N; i++)
        scanf("%s", S[i]);
    for(int i=0; i<N; i++)
    {
        int n=strlen(S[i]);
        int cur=0;
        for(int j=0; j<n; j++)
        {
            int x=S[i][j]-'a';
            if(trie[cur][x]==-1)
                trie[cur][x]=++M;
            cur=trie[cur][x];
        }
        val[cur]+=A[i];
    }
    dfs(0);
    queue<int> Q;
    Q.push(0);
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        val[u]+=val[fail[u]];
        for(int i=0; i<26; i++) if(trie[u][i]!=-1)
            Q.push(trie[u][i]);
    }
    for(int i=0; i<=M; i++)
        for(int j=0; j<=M; j++)
            G[i][j]=-0x3f3f3f3f3f3f3f3fLL;
    for(int i=0; i<=M; i++)
    {
        for(int j=0; j<26; j++)
        {
            int u=i;
            while(u!=0 && trie[u][j]==-1)
                u=fail[u];
            if(trie[u][j]!=-1)
                G[i][trie[u][j]]=max(G[i][trie[u][j]], (long long)val[trie[u][j]]);
            else
                G[i][0]=max(G[i][0], (long long)val[0]);
        }
    }
    matrix ret;
    matrix a;
    for(int i=0; i<=M; i++)
        for(int j=0; j<=M; j++)
            a.data[i][j]=G[i][j];
    for(int i=0; i<=M; i++)
        for(int j=0; j<=M; j++)
            ret.data[i][j]=-0x3f3f3f3f3f3f3f3fLL;
    ret.data[0][0]=0;
    for(; L>0; L/=2)
    {
        if(L&1)
            ret=ret.multiply(a);
        a=a.multiply(a);
    }
    long long ans=0;
    for(int i=0; i<=M; i++)
        ans=max(ans, ret.data[0][i]);
    printf("%lld\n", ans);
    return 0;
}