#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
int N;
char S[5001];
int lcpcache[5001][5001];
int scache[5001][5001];
int dp[5001][5001];

int lcp(int i, int j)
{
    if(i>=N || j>=N)
        return 0;
    if(lcpcache[i][j]!=-1)
        return lcpcache[i][j];
    if(S[i]==S[j])
        return lcpcache[i][j]=lcp(i+1, j+1)+1;
    return lcpcache[i][j]=0;
}

inline void addmod(int& x, int v)
{
    x+=v;
    if(x>=MOD)
        x-=MOD;
}

inline bool smaller(int i, int j, int len)
{
    if(j+len>N)
        return false;
    int l=lcp(i, j);
    if(l>=len)
        return false;
    return S[i+l]<S[j+l];
}

int solve(int pos, int len);

int sumsolve(int pos, int len)
{
    if(pos+len>N)
        return 0;
    int& ret=scache[pos][len];
    if(ret!=-1)
        return ret;
    ret=solve(pos, len);
    addmod(ret, sumsolve(pos, len+1));
    return ret;
}

int solve(int pos, int len)
{
    if(pos>=N)
        return 0;
    int& ret=dp[pos][len];
    if(ret!=-1)
        return ret;
    if(S[pos]=='0')
        return ret=0;
    if(pos+len==N)
        return ret=1;
    if(pos+len+len>N)
        return ret=0;
    ret=0;
    if(smaller(pos, pos+len, len))
        addmod(ret, solve(pos+len, len));
    addmod(ret, sumsolve(pos+len, len+1));
    return ret;
}

int main()
{
    memset(lcpcache, -1, sizeof lcpcache);
    memset(scache, -1, sizeof scache);
    memset(dp, -1, sizeof dp);
    scanf("%d", &N);
    scanf("%s", S);
    printf("%d\n", sumsolve(0, 1));
    return 0;
}