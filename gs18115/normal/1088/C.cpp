#include<iostream>
using namespace std;
typedef long long LL;
LL N;
LL i,j;
LL t,MOD;
LL A[123456];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    if(N==1)
        return cout<<0<<endl,0;
    for(i=0;i<N;i++)
        cin>>A[i];
    cout<<N+1<<endl,0;
    for(i=0;i<N;i++)
        A[i]+=999999;
    cout<<1<<' '<<N<<' '<<999999<<endl;
    MOD=A[N-1]-100000;
    for(i=N-1;i-->0;)
    {
        t=((i-A[i])%MOD+MOD)%MOD;
        for(j=0;j<=i;j++)
            A[j]+=t;
        cout<<1<<' '<<i+1<<' '<<t<<endl;
    }
    cout<<2<<' '<<N<<' '<<MOD<<endl;
    return 0;
}