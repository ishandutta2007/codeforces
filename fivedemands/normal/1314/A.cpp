#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
int n;
multiset<ll>s;
ll sum=0;
pair<ll,ll>a[200001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i].fi;
	}
	for(int i=1; i<=n ;i++){
		cin >> a[i].se;
	}
	sort(a+1,a+n+1);
	ll fk=0;
	int p=1;
	ll ans=0;
	while(p<=n){
		int r=p;
		s.insert(a[p].se);sum+=a[p].se;
		while(r<n && a[r+1].fi==a[p].fi){
			++r;
			s.insert(a[r].se);
			sum+=a[r].se;
		}
		ll cur=a[p].fi;
		while(!s.empty()){
			cur++;
			auto it=s.end();--it;
			sum-=*it;s.erase(it);ans+=sum;
			while(r<n && a[r+1].fi==cur){
				++r;
				s.insert(a[r].se);
				sum+=a[r].se;
			}
		}
		p=r+1;
	}
	cout << ans << endl;
}