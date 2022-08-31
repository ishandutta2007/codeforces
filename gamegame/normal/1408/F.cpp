#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
int n;
vector<pair<int,int> >v;
void solve(int l,int r){
	if(l==r) return;
	int mid=(l+r)/2;
	solve(l,mid);
	solve(mid+1,r);
	for(int i=l; i<=mid ;i++){
		v.push_back({i,r+l-i});
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	int x=1;
	while(x*2<=n) x=x*2;
	solve(n-x+1,n);
	solve(1,x);
	cout << v.size() << '\n';
	for(auto c:v){
		cout << c.fi << ' ' << c.se << '\n';
	}
	
}