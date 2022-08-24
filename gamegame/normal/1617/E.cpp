#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
const int iu=30;
ll n,m;
ll a[N];
vector<pair<ll,int> >b[33];
ll mx[33];
int mp[33];
int lg(int x){
	if(x==0) return 30;
	int res=0;
	for(int j=4; j>=0 ;j--){
		if(x>=(1<<(1<<j))){
			res|=(1<<j);
			x>>=1<<j;
		}
	}
	return res;
}
ll ax=0,ay=0,az=-1e9;
int lv[N];
void solve(int id){
	if(b[id].empty()) return;
	for(int i=iu-1; i>id ;i--){
		vector<pair<ll,int> >sm,bg;
		for(auto c:b[id]){
			if(c.fi<(1<<i)) sm.push_back(c);
			else{
				lv[c.se]++;bg.push_back({(1<<(i+1))-c.fi,c.se});
			}
		}
		b[id].clear();reverse(sm.begin(),sm.end());
		while(!sm.empty() || !bg.empty()){
			if(sm.empty()){
				b[id].push_back(bg.back());bg.pop_back();
			}
			else if(bg.empty()){
				b[id].push_back(sm.back());sm.pop_back();
			}
			else if(sm.back().fi>bg.back().fi){
				b[id].push_back(bg.back());bg.pop_back();
			}
			else if(sm.back().fi<bg.back().fi){
				b[id].push_back(sm.back());sm.pop_back();
			}
			else{
				if(az<lv[sm.back().se]+lv[bg.back().se]){
					ax=sm.back().se;
					ay=bg.back().se;
					az=lv[sm.back().se]+lv[bg.back().se];
				}
				if(lv[sm.back().se]<lv[bg.back().se]){
					b[id].push_back(bg.back());
				}
				else{
					b[id].push_back(sm.back());
				}
				sm.pop_back();bg.pop_back();
			}
		}
	}
	if(b[id].size()>1) while(true);
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for(int i=1; i<=n ;i++){
		ll x;cin >> x;
		b[lg(x&-x)].push_back({x,i});
	}
	for(int i=0; i<=iu ;i++){
		mx[i]=-1e9;
		for(auto c:b[i]){
			ll x=c.fi;
			int st=0;
			for(int j=iu-1; j>=0 ;j--){
				if(x>(1<<j)){
					x=(1<<(j+1))-x;st++;
				}
			}
			if(x!=0) st++;
			//cout << x << ' ' << st << endl;
			if(st>mx[i]){
				mx[i]=st;mp[i]=c.se;
			}
		}
		sort(b[i].begin(),b[i].end());
		solve(i);
	}
	for(int i=0; i<=iu ;i++){
		for(int j=i+1; j<=iu ;j++){
			if(mx[i]+mx[j]>az){
				az=mx[i]+mx[j];
				ax=mp[i];
				ay=mp[j];
			}
		}
	}
	cout << ax << ' ' << ay << ' ' << az << '\n';
}