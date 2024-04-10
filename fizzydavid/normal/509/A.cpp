//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    ll ans=1;
    for(int i=n;i<=2*n-2;i++)ans*=i;
    for(int i=1;i<n;i++)ans/=i;
    cout<<ans<<endl;
    return 0;
}