#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
PL seg[1510];
LL N,S,M,K;
LL dp[1510][1510];
LL A[1510],P[1510];
inline bool chk(LL X)
{
    LL i,j,k;
    LL cnt=0;
    for(i=0;i<=N;i++)
        fill(dp[i],dp[i]+M+1,0);
    for(i=1;i<=N;i++)
        P[i]=P[i-1]+(A[i]>X?0:1);
    for(i=j=0;i<N;i++)
    {
        while(j<S)
        {
            if(seg[j].first==i+1)
            {
                cnt=max(cnt,seg[j].second-i);
                j++;
            }
            else
                break;
        }
        for(k=0;k<M;k++)
        {
            dp[i+1][k]=max(dp[i+1][k],dp[i][k]);
            if(i+cnt<=N)
                dp[i+cnt][k+1]=max(dp[i+cnt][k+1],dp[i][k]+P[i+cnt]-P[i]);
        }
        dp[i+1][M]=max(dp[i+1][M],dp[i][M]);
        if(cnt>0)
            cnt--;
    }
    return dp[N][M]>=K;
}
LL i;
LL s,e,mid;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>S>>M>>K;
    for(i=1;i<=N;i++)
        cin>>A[i];
    for(i=0;i<S;i++)
        cin>>seg[i].first>>seg[i].second;
    sort(seg,seg+S);
    s=0;
    e=INF;
    if(!chk(e))
        return cout<<-1<<endl,0;
    while(s<e)
    {
        mid=s+e>>1;
        if(chk(mid))
            e=mid;
        else
            s=mid+1;
    }
    cout<<s<<endl;
    return 0;
}