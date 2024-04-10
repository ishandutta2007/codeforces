#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL N,T,i,MAX;
LL A[200010],B[200010],X[200010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>T;
    for(i=1;i<=N;i++)
    {
        cin>>A[i];
        A[i]+=T;
        B[i]=3*INF;
    }
    A[N+1]=3*INF;
    for(i=1;i<=N;i++)
    {
        cin>>X[i];
        if(X[i]<i||X[i]<X[i-1])
            return cout<<"No"<<endl,0;
        B[X[i]]=A[i+1]-1;
    }
    for(i=N;--i>0;)
    {
        if(B[i]>=B[i+1]&&B[i]!=3*INF)
            return cout<<"No"<<endl,0;
        B[i]=min(B[i],B[i+1]-1);
    }
    for(i=1;i<=N;i++)
    {
        if(MAX>=i&&B[i-1]<A[i])
            return cout<<"No"<<endl,0;
        MAX=max(MAX,X[i]);
    }
    cout<<"Yes"<<endl;
    for(i=1;i<=N;i++)
        cout<<B[i]<<' ';
    cout<<endl;
    return 0;
}