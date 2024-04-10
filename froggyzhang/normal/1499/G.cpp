#include<bits/stdc++.h>
using namespace std;
#define N 400040
const int mod=998244353;
typedef long long ll;
int n1,n2,m,t[N],H,pw2[N],Q,g[N];
class Union_Set{
public:
	int f[N],c[N];
	array<int,2> s[N];
	inline int getf(int x){
		if(f[x]==x)return x;
		int y=f[x];
		f[x]=getf(f[x]);
		c[x]^=c[y];
		return f[x];	
	}
}S;
void Link(int x,int y,int k){
	S.f[k]=k;
	if(g[x]<g[y])swap(x,y);
	g[x]^=1,g[y]^=1;
	int fx=t[x]?S.getf(t[x]):-1;
	int fy=t[y]?S.getf(t[y]):-1;
	if(fx==-1){
		t[x]=t[y]=k;
		S.c[k]=0,S.s[k][0]=pw2[k];	
	}
	else{
		S.c[k]=S.c[t[x]]^1;
		S.s[fx][S.c[k]]=(S.s[fx][S.c[k]]+pw2[k])%mod;
		S.f[k]=fx;
		if(S.c[k])H=(H+pw2[k])%mod;
		t[x]=0;
		if(~fy){
			if(fx==fy){t[y]=0;return;}
			S.c[fy]=S.c[k]^S.c[t[y]]^1;
			S.f[fy]=fx;
			S.s[fx][0]=(S.s[fx][0]+S.s[fy][S.c[fy]])%mod;
			S.s[fx][1]=(S.s[fx][1]+S.s[fy][S.c[fy]^1])%mod;
			if(S.c[fy]){
				H=(H+S.s[fy][0])%mod;
				H=(H-S.s[fy][1]+mod)%mod;
			}
			t[y]=0;
		}
		else t[y]=k;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n1>>n2>>m;
	pw2[0]=1;
	for(int i=1;i<=400000;++i)(pw2[i]=pw2[i-1]<<1)%=mod;
	for(int i=1,u,v;i<=m;++i){
		cin>>u>>v;
		Link(u,v+n1,i);	
	}
	cin>>Q;
	while(Q--){
		int opt;
		cin>>opt;
		if(opt==1){
			int u,v;
			cin>>u>>v;
			Link(u,v+n1,++m);
			cout<<H<<endl;
		}
		else{
			vector<int> ans;
			for(int i=1;i<=m;++i){
				S.getf(i);
				if(S.c[i])ans.push_back(i);
			}
			cout<<ans.size();
			for(auto x:ans)cout<<' '<<x;
			cout<<endl;
		}	
	}
	return 0;
}