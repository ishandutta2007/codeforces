#include<iostream>
using namespace std;
typedef long long LL;
const LL INF=1e18;
LL N,M,i,j,sum,P,ans;
LL A[2345],B[2345],X[2345],Y[2345];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M;
    fill(X,X+N+5,INF);
    fill(Y,Y+M+5,INF);
    for(i=0;i<N;i++)
        cin>>A[i];
    for(i=0;i<M;i++)
        cin>>B[i];
    for(i=0;i<N;i++)
    {
        sum=0;
        for(j=i;j<N;j++)
        {
            sum+=A[j];
            X[j-i+1]=min(sum,X[j-i+1]);
        }
    }
    for(i=0;i<M;i++)
    {
        sum=0;
        for(j=i;j<M;j++)
        {
            sum+=B[j];
            Y[j-i+1]=min(sum,Y[j-i+1]);
        }
    }
    cin>>P;
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
        {
            if(X[i]*Y[j]<=P)
                ans=max(ans,i*j);
            else
                break;
        }
    }
    cout<<ans<<endl;
    return 0;
}