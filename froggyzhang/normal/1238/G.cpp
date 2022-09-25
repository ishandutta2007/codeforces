#include<bits/stdc++.h>
using namespace std;
#define N 500050
typedef long long ll;
int n,m,c,c0;
struct Fri{
	int t,a,b;
	friend bool operator < (const Fri &x,const Fri &y){
		return x.t==y.t?x.b<y.b:x.t<y.t;
	}
}d[N];
map<int,int> s;
void Solve(){
	cin>>n>>m>>c>>c0;
	for(int i=1;i<=n;++i){
		cin>>d[i].t>>d[i].a>>d[i].b;
	}
	sort(d+1,d+n+1);
	s.clear();
	ll ans=0;
	s[0]=c0;
	int now=c0;
	d[++n]={m,0,0};
	for(int i=1;i<=n;++i){
		int t=d[i].t-d[i-1].t;
		while(t>0&&!s.empty()){
			int w=min(t,s.begin()->second);
			ans+=1LL*w*(s.begin()->first);
			s.begin()->second -= w;
			if(!s.begin() -> second)s.erase(s.begin());
			t-=w,now-=w;
		}
		if(t>0){
			cout<<-1<<'\n';
			return;
		}
		int res=max(0,d[i].a-(c-now));
		while(!s.empty()&&res&&d[i].b<s.rbegin()->first){
			int t=min(s.rbegin()->second,res);
			res-=t,s.rbegin()->second-=t;
			if(!s.rbegin()->second)s.erase(--s.end());
			now-=t;
		}
		s[d[i].b]+=d[i].a-res;
		now+=d[i].a-res;
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