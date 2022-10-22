#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,ll> P;
const int N=1e5+5;
const ll mod=1e9+7;
ll n,m,q,sx,sy,ex,ey,v1,v2,gcdV,g1,g2;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
	//lcm(n,m)/n = nm/gcd(n,m)/n = m/gcd(n,m) 
    cin>>n>>m>>q;
	gcdV=__gcd(n,m); v1=n/gcdV; v2=m/gcdV;
	for(int i=1;i<=q;i++){
		cin>>sx>>sy>>ex>>ey;
		if(sx==1) g1=(sy-1)/v1;
		else g1=(sy-1)/v2;
		if(ex==1) g2=(ey-1)/v1;
		else g2=(ey-1)/v2;
		if(g1==g2) cout<<"YES\n";
		else cout<<"NO\n";
	}
    return 0;
}