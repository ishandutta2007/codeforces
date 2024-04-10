#include<bits/stdc++.h>
using namespace std;
#define N 500050
typedef long long ll;
int n;
ll a[N];
set<ll> S;
void Solve(){
	cin>>n;
	S.clear();
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	int ans=1,sign=1;
	ll B=0;
	ll l=1,r=a[1]-1;
	if(a[1]&1)++ans;
	else l=r=a[1]/2;
	for(int i=2;i<=n;++i){
		ll lim=max(1LL,a[i]-a[i-1]+1);
		if(!(a[i]&1)){
			if((a[i]/2>=l&&a[i]/2<=r)||S.count((a[i]/2-B)*sign)){
				l=r=a[i]/2;S.clear();
				continue;	
			}
		}
		++ans;
		auto check=[&](ll z)->bool{
			return z>=lim&&z<a[i];
		};
		sign*=-1;
		B=a[i]-B;
		while(!S.empty()&&!check(sign*(*S.begin())+B)){
			S.erase(S.begin());
		}
		while(!S.empty()&&!check(sign*(*S.rbegin())+B)){
			S.erase(--S.end());
		}
		if(l<=r){
			ll _r=a[i]-l,_l=a[i]-r;
			_l=max(_l,lim),_r=min(_r,a[i]-1);
			l=_l,r=_r;
		}
		if(!(a[i]&1)){
			S.insert((a[i]/2-B)*sign);
		}
		if(S.empty()&&l>r){
			l=1,r=a[i]-1;++ans;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}