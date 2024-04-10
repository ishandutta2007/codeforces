#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=2e5+11;
int a[N];
int n;
int s[N];
void solve(){
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i) {
		int v=i%2?a[i]:-a[i];
		s[i] += s[i-1] + v;
	}
	int tmp=0;
	for(int i=1;i<=n;++i) tmp+=abs(a[i]);
	if(tmp%2) {
		cout<<"-1\n";
		return;
	}
	vector<int> pos;
	pos.push_back(0);
	for(int i=1,j;i<=n;++i){
		if(!a[i]) continue;
		for(j=i+1;j<=n;++j)
			if(a[j]) break;
		assert(j<=n);
		if(a[i]+a[j]==0) {
			pos.push_back(j-1);
		}else{
			if((i%2) == (j%2)) {
				pos.push_back(i);
			}
		}
		pos.push_back(j);
		i=j;
	}
	pos.push_back(n);
	pos.resize(unique(pos.begin(),pos.end())-pos.begin());
	int m=pos.size();
	cout<<m-1<<"\n";
	for(int i=1;i<m;++i){
		cout<<pos[i-1]+1<<" "<<pos[i]<<"\n";
	}
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}