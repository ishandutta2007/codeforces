#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=1e6+1;

int n;

ll m;
ll x,y;
ll p[N],q[N];
ll am=1,ac=0,bm=1,bc=0;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m;
	cin >> x >> y;
	for(int i=1; i<=n ;i++){
		ll u,v;cin >> u >> v;
		p[i]=u;q[i]=v;
		am*=-1;
		ac*=-1;
		ac+=2*u;
		bm*=-1;
		bc*=-1;
		bc+=2*v;
	}
	ll t=m/n;
	if(t%2==1) x=am*x+ac;
	if(t%2==1) y=bm*y+bc;
	for(int i=1; i<=m%n ;i++){
		x=2*p[i]-x;
		y=2*q[i]-y;
	} 
	cout << x << ' ' << y << endl;
}