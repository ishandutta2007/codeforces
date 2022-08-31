#include<iostream>
#include<vector>
#include<algorithm>
#include<chrono>
#include<random>
using namespace std;
typedef long long ll;
ll p;
ll u,v,x;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rando(ll l,ll r){
	return uniform_int_distribution<ll>(l,r)(rng);
}
vector<int>um,vm;
ll cal(ll g,ll h){
	if(h==0) return 0;
	return g/h+1+cal(h,g%h);
}
void find(ll g,ll h,vector<int>&m){
	if(h==0) return;
	m.push_back(3);
	for(int i=0; i<g/h ;i++) m.push_back(2);
	find(h,g%h,m);
}
void solve(ll y,vector<int>&m){
	if(y==0) return;
	while(true){
		ll x=rando(1,p-1);
		if(cal(x,y*x%p)>100) continue;
		find(x,y*x%p,m);
		return;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> u >> v >> p;
	solve(u,um);
	solve(v,vm);
	reverse(vm.begin(),vm.end());
	cout << um.size()+vm.size() << endl;
	for(auto cur:um) cout << cur << ' ';
	for(auto cur:vm) cout << 3-cur%3 << ' ';
	cout << endl;
}