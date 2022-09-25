#include<bits/stdc++.h>
using namespace std;
#define N 500050
typedef long long ll;
const int inf=0x3f3f3f3f;
int n,Q,l[N],r[N],pre[N],suf[N];
char s[N];
vector<array<int,10> > all;
struct Union_Set{
	int f[N];
	inline int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
	void init(int n){
		for(int i=0;i<=n+1;++i)f[i]=i;
	}
}P,S;
bool Do_pre(int l,int r,int w){
	bool ok=0;
	for(int u=P.getf(l);u<=r;u=P.getf(u)){
		pre[u]=w;
		P.f[u]=u+1;
		ok=1;
	}
	return ok;
}
bool Do_suf(int l,int r,int w){
	bool ok=0;
	for(int u=S.getf(l);u<=r;u=S.getf(u)){
		suf[u]=w;
		S.f[u]=u+1;
		ok=1;
	}
	return ok;
}
void init(){
	array<int,10> ans;
	for(int i=0;i<10;++i)ans[i]=0;
	for(int i=1;i<=n;++i)l[i]=i-1,r[i]=i+1;
	static bool dl[N];
	auto Del=[&](int o)->void{
		r[l[o]]=r[o];l[r[o]]=l[o];
		dl[o]=1;
	};
	memset(pre,0x3f,sizeof(pre));
	memset(suf,0x3f,sizeof(suf));
	int u=1,dir=1;
	P.init(n+1),S.init(n+1);
	Do_pre(0,1,0);
	int pos=1;
	while(true){
		if(u>n)break;
		if(!u){
			while(pos<=n&&dl[pos])++pos;
			if(pos>n)break;
			u=pos;
			Do_pre(u,u,all.size());
			dir=1;
		}
		int las=u;
		if(isdigit(s[u])){
			++ans[s[u]-'0'];
			if(s[u]=='0')Del(u);
			else --s[u];
			if(dir==1)u=r[u];
			else u=l[u];
		}
		else if(s[u]=='<'){
			dir=-1;
			if(!l[u]||!isdigit(s[l[u]]))Del(u);
			u=l[u];
		}
		else if(s[u]=='>'){
			dir=1;
			if(r[u]>n||!isdigit(s[r[u]]))Del(u);
			u=r[u];
		}
		else if(s[u]=='['){
			int v=dir==1?r[u]:l[u];
			if(!v||s[v]==']'||s[v]=='[')Del(u);
			u=v;
		}
		else if(s[u]==']'){
			int v=u;
			while(v&&s[v]!='['){
				v=l[v];
			}
			if(!v||l[u]==v)Del(u);
			u=v;
		}
		else{
			assert(false);
		}
		all.push_back(ans);
		bool zz=0;
		if(las<u){
			zz|=Do_pre(las+1,u,all.size());
		}
		else{
			zz|=Do_suf(u,las-1,all.size());
		}
		if(!zz&&u)all.pop_back();
	}
}
int main(){
	cin>>n>>Q;
	cin>>(s+1);
	init();
	for(int i=0;i<=n+1;++i){
		if(suf[i]==inf)suf[i]=pre[n+1];
	}
	while(Q--){
		int l,r;
		cin>>l>>r;
		int R=min(suf[l-1],pre[r+1]),L=pre[l];
		for(int i=0;i<10;++i){
			cout<<(!R?0:all[R-1][i])-(!L?0:all[L-1][i])<<' ';
		}
		cout<<'\n';
	}
	return 0;
}