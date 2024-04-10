#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL N,K,D,T;
LD ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>K>>D>>T;
    D=(K+D-1)/D*D;
    N=2*T/(D+K);
    T=2*T-N*(D+K);
    if(T>2*K)
        ans=T-K;
    else
        ans=(LD)T/2;
    cout<<fixed<<setprecision(12)<<(LD)(N*D)+ans<<endl;
    return 0;
}