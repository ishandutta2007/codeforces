#include <bits/stdc++.h>
using namespace std;

using ll=long long;

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define eb emplace_back
#define a first
#define b second

template<class t>using vc=vector<t>;

using pi=pair<int,int>;
using vi=vc<int>;

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int p[3][2];
	int x[3],y[3];
	rep(i,3){
		rep(j,2)cin>>p[i][j];
		x[i]=p[i][0];
		y[i]=p[i][1];
	}
	
	sort(x,x+3);
	sort(y,y+3);
	
	using P=pair<pi,pi>;
	vc<P> ans;
	rep(i,3){
		if(p[i][0]!=x[1]){
			ans.eb(pi(p[i][0],p[i][1]),pi(x[1],p[i][1]));
		}
		p[i][0]=x[1];
	}
	rep(i,3){
		if(p[i][1]!=y[1]){
			ans.eb(pi(p[i][0],p[i][1]),pi(p[i][0],y[1]));
		}
		p[i][1]=y[1];
	}
	cout<<ans.size()<<endl;
	for(auto [a,b]:ans){
		cout<<a.a<<" "<<a.b<<" "<<b.a<<" "<<b.b<<endl;
	}
}