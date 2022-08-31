#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const int k=6;
ll n;
typedef pair<int,int> pii;
multiset<int>ms;
ll r[N];
ll lz[N];
ll ans[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	int cnt=0;
	stack<pair<int,int> >s;
	s.push({1e9,0});
	for(int i=1; i<=2*n ;i++){
		char c;cin >> c;
		if(c=='+'){
			ms.insert(++cnt);
		}
		else{
			int x;cin >> x;
			while(s.top().fi<x) s.pop();
			int cur=s.top().se;
			auto it=ms.lower_bound(cur+1);
			if(it==ms.end()) return cout << "NO\n",0;
			ans[*it]=x;
			ms.erase(it);
			s.push({x,cnt});
			//cout << x << ' ' << cnt << endl;
		}
	}
	cout << "YES\n";
	for(int i=1; i<=n ;i++) cout << ans[i] << ' ';
	cout << endl;
}