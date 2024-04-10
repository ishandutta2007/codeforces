#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n;
ll d,m;
int ans[200001];
set<pair<ll,int> >s;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> d;d++;m++;
	for(int i=1; i<=n ;i++){
		ll x;cin >> x;
		s.insert({x,i});
	}
	auto curr=*s.begin();
	ans[curr.se]=1;
	int day=1;
	ll t=curr.fi;
	s.erase(s.begin());
	for(int i=2; i<=n ;i++){
		ll tmp=s.rbegin()->fi;
		if(tmp<t+d){
			day++;t-=m*40;
		}
		auto cur=*s.lower_bound({t+d,0});
		ans[cur.se]=day;
		t=cur.fi;
		s.erase(cur);
	}
	cout << day << '\n';
	for(int i=1; i<=n ;i++) cout << ans[i] << ' ';
	cout << endl;
}