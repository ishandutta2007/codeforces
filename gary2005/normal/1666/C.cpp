#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
int fa[9];
int root(int x){
	return fa[x]=(fa[x]==x? x:root(fa[x]));
}
int main(){
	int x,y;
	set<int> xx,yy;
	vector<mp> p;
	cin>>x>>y,xx.insert(x),yy.insert(y),p.PB(II(x,y));
	cin>>x>>y,xx.insert(x),yy.insert(y),p.PB(II(x,y));
	cin>>x>>y,xx.insert(x),yy.insert(y),p.PB(II(x,y));
//	for(auto it:yy) cout<<it<<endl;
	LL rest=1e18;
	vector<pair<mp,mp> > ans;
	map<mp,int> id;
	mp is[9];
	int cnt=0;
	for(auto it:xx) for(auto itt:yy) is[cnt]=II(it,itt),id[II(it,itt)]=cnt++;
	int pr=-2e9;
	vector<mp> seg;
	for(auto it:yy){
		if(pr!=-2e9){
			for(auto itt:xx){
				seg.PB(II(id[II(itt,pr)],id[II(itt,it)]));
			}
		}
		pr=it;
	}
	pr=-2e9;
	for(auto it:xx){
		if(pr!=-2e9){
			for(auto itt:yy){
				seg.PB(II(id[II(pr,itt)],id[II(it,itt)]));
			}
		}
		pr=it;
	}
	rep(mask,1<<seg.size()){
		rep(j,9) fa[j]=j;
		rep(j,seg.size()){
			if((mask>>j)&1) fa[root(seg[j].FIR)]=root(seg[j].SEC);
		}
		bool ok=1;
		rep(i,p.size()) ok&=root(id[p[i]])==root(id[p[0]]);
		if(ok){
			LL tmp=0;
		rep(j,seg.size()){
			if((mask>>j)&1){
				int u,v;
				tie(u,v)=seg[j];
				tmp+=abs(is[u].FIR-is[v].FIR);
				tmp+=abs(is[u].SEC-is[v].SEC);
			}
		}
		if(tmp<rest){
			rest=tmp;
			ans.clear();
			rep(j,seg.size()){
			if((mask>>j)&1){
				int u,v;
				tie(u,v)=seg[j];
				ans.PB(II(is[u],is[v]));
			}
			}
		}
		}
	}
	cout<<ans.size()<<endl;
	for(auto it:ans) cout<<it.FIR.FIR<<' '<<it.FIR.SEC<<" "<<it.SEC.FIR<<' '<<it.SEC.SEC<<endl;
	return 0;
}
/*
1 1
3 3
10 2
*/