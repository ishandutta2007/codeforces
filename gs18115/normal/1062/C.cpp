#include<iostream>
#include<vector>
using namespace std;
typedef long long LL;
const LL INF=1e18;
const LL MOD=1e9+7;
LL pow(LL X)
{
    if(X==0)
        return 1;
    if(X&1)
        return 2*pow(X-1)%MOD;
    LL t=pow(X>>1);
    return t*t%MOD;
}
LL N,M,Q,i,L,R;
LL S[123456];
char s[123456];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>Q;
    cin>>s+1;
    for(i=1;i<=N;i++)
        S[i]=S[i-1]+s[i]-'0';
    for(i=0;i<Q;i++)
    {
        cin>>L>>R;
        N=S[R]-S[L-1];
        M=R-L+1-N;
        cout<<(pow(N)+MOD-1)*pow(M)%MOD<<'\n';
    }
    cout<<endl;
    return 0;
}