#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
int N, M;
char S[100001];
int dp[2001][5001][2];
int pref, mpref;

void addmod(int& x, int v)
{
    x+=v;
    if(x>=MOD)
        x-=MOD;
}

int rec(int len, int psum, int part)
{
    if(abs(psum)>len && part==1)
        return 0;
    if(psum<0)
        return 0;
    if(len==0 && part==1)
        return psum==0;
    int& ret=dp[len][psum][part];
    if(ret!=-1)
        return ret;
    ret=0;
    if(part==0)
    {
        if(psum+mpref>=0)
            addmod(ret, rec(len, psum+pref, 1));
    }
    if(len>0)
    {
        addmod(ret, rec(len-1, psum+1, part));
        addmod(ret, rec(len-1, psum-1, part));
    }
    return ret;
}

int main()
{
    memset(dp, -1, sizeof dp);
    scanf("%d%d", &N, &M);
    scanf("%s", S);
    for(int i=0; i<M; i++)
    {
        pref+=(S[i]=='(')-(S[i]==')');
        mpref=min(mpref, pref);
    }
    printf("%d\n", rec(N-M, 0, 0));
    return 0;
}