#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> TP;
const int N=7e5+5;
const ll MOD=1e9+7;
ll a,b,c,ans;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>a>>b>>c;
    if(a>=b) a=min(a,b+1);
    else b=min(b,a+1);
    cout<<c*2LL+a+b;
    return 0;
}