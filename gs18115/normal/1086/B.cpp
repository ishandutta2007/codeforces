#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#define PB push_back
#define EB emplace_back
using namespace std;
typedef long long LL;
typedef long double LD;
const LL INF=1e18;
LL deg[123456];
LL N,S,i,s,e;
LL cnt;
LD ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>S;
    for(i=1;i<N;i++)
    {
        cin>>s>>e;
        deg[s-1]++;
        deg[e-1]++;
    }
    for(i=0;i<N;i++)
        if(deg[i]==1)
            cnt++;
    ans=(LD)S*(LD)2/(LD)cnt;
    cout<<fixed<<setprecision(20)<<ans<<endl;
    return 0;
}