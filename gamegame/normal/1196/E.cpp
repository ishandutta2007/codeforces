#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=1e6+1;
int n,m;
ll a[N],b[N];
vector<pair<int,int> >v;
void solve(){
	int b,w;
	cin >> b >> w;
	if(b>3*w+1 || w>3*b+1){
		cout << "NO\n";
		return;
	}
	bool sw=false;
	if(b<w) sw=true;
	if(sw) swap(b,w);
	queue<pair<int,int> >q;
	queue<pair<int,int> >r;
	v.clear();
	for(int i=1; i<=w ;i++){
		q.push({2,2*i-1+sw});
		v.push_back({2,2*i+sw});
	}
	for(int i=1; i<=w ;i++){
		
		q.push({1,2*i+sw});
		q.push({3,2*i+sw});
	}
	q.push({2,2*w+1+sw});
	for(int i=1; i<=b ;i++){
		v.push_back(q.front());
		q.pop();
	}
	cout << "YES\n";
	for(auto cur:v) cout << cur.fi << ' ' << cur.se << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;while(t--) solve();
}