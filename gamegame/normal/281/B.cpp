#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,x,y;
ll ax,ay;
double best=1e9;
void test(ll u,ll v){
	double cur=abs(1.0*x/y-1.0*u/v);
	if(cur<best){
		best=cur;
		ax=u;ay=v;
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> x >> y >> n;
	for(int i=1; i<=n ;i++){
		test(x*i/y,i);
		test(x*i/y+1,i);
	}
	cout << ax << '/' << ay << endl;
}