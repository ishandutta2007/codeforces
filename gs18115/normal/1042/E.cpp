#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL MOD=998244353;
const LL MAXN=1010;
LL pow(const LL&X,LL Y)
{
    if(Y<=0)
        return 1;
    if(Y&1)
        return X*pow(X,Y-1)%MOD;
    LL t=pow(X,Y>>1);
    return t*t%MOD;
}
LL rev(const LL X)
{
    return pow(X,MOD-2);
}
vector<LL>V;
vector<PL>Q[MAXN*MAXN];
LL num,sumi,sumj,sumisq,sumjsq,sumdp;
LL i,j,I,J;
LL N,M;
LL A[MAXN][MAXN];
LL dp[MAXN][MAXN];
LL R,C;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M;
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            cin>>A[i][j];
            V.push_back(A[i][j]);
        }
    }
    sort(V.begin(),V.end());
    V.erase(unique(V.begin(),V.end()),V.end());
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            A[i][j]=lower_bound(V.begin(),V.end(),A[i][j])-V.begin();
            Q[A[i][j]].push_back({i,j});
        }
    }
    for(i=0;i<V.size();i++)
    {
        for(j=0;j<Q[i].size();j++)
        {
            I=Q[i][j].first;
            J=Q[i][j].second;
            dp[I][J]=(I*I*num+J*J*num+sumisq+sumjsq-2*(I*sumi+J*sumj)+sumdp)%MOD*rev(num)%MOD;
            if(dp[I][J]<0)
                dp[I][J]+=MOD;
        }
        num+=Q[i].size();
        for(j=0;j<Q[i].size();j++)
        {
            I=Q[i][j].first;
            J=Q[i][j].second;
            sumi=(sumi+I)%MOD;
            sumj=(sumj+J)%MOD;
            sumisq=(sumisq+I*I)%MOD;
            sumjsq=(sumjsq+J*J)%MOD;
            sumdp=(sumdp+dp[I][J])%MOD;
        }
    }
    cin>>R>>C;
    cout<<dp[R-1][C-1]<<endl;
    return 0;
}