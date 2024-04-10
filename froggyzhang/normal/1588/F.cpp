#include<bits/stdc++.h>
using namespace std;
#define N 200010
typedef long long ll;
typedef pair<int,int> pii;
const int B=360;
int n,Q,p[N],c[N];
ll s[N],add[N],a[N];
inline int Get(const vector<int> &A,int l,int r){
	return upper_bound(A.begin(),A.end(),r)-lower_bound(A.begin(),A.end(),l);	
}
struct Query{
	int op,x,y;
};
void Solve(int m){
	static Query q[N];
	static bool cut[N],vis[N];
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
		add[i]=c[i]=vis[i]=cut[i]=0;
	}
	for(int i=1;i<=m;++i){
		cin>>q[i].op>>q[i].x>>q[i].y;
	}
	for(int i=1;i<=m;++i){
		if(q[i].op==3){
			cut[q[i].x]=cut[q[i].y]=1;
		}
		else if(q[i].op==2){
			cut[q[i].x]=1;	
		}
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			static int cir[N],len;
			len=0;
			for(int u=i;!vis[u];u=p[u]){
				cir[++len]=u;
				vis[u]=1;
			}
			reverse(cir+1,cir+len+1);
			int las=0;
			for(int i=len;i>=1;--i){
				if(cut[cir[i]]){
					las=cir[i];
					break;
				}
			}
			if(!las)continue;
			for(int i=1;i<=len;++i){
				if(cut[cir[i]]){
					las=cir[i];	
				}
				c[cir[i]]=las;
			}
		}
	}
	static vector<int> g[N];
	static int tot,t[N];
	tot=0;
	for(int i=1;i<=n;++i){
		if(cut[i]){
			t[++tot]=i;
		}
	}
	for(int i=1;i<=n;++i){
		g[i].clear();
		g[i].shrink_to_fit();
	}
	for(int i=1;i<=n;++i){
		if(c[i])g[c[i]].push_back(i);
	}
	for(int i=1;i<=m;++i){
		if(q[i].op==1){
			ll ans=s[q[i].y]-s[q[i].x-1];
			for(int j=1;j<=tot;++j){
				ans+=add[t[j]]*Get(g[t[j]],q[i].x,q[i].y);	
			}
			cout<<ans<<'\n';
		}
		else if(q[i].op==2){
			static int vis[N],jb;
			++jb;
			for(int u=c[q[i].x];vis[u]^jb;u=c[p[u]]){
				vis[u]=jb;
				add[u]+=q[i].y;
			}	
		}
		else{
			swap(p[q[i].x],p[q[i].y]);
		}
	}
	for(int i=1;i<=n;++i){
		if(c[i])a[i]+=add[c[i]];	
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];	
	}
	for(int i=1;i<=n;++i){
		cin>>p[i];
	}
	cin>>Q;
	while(Q){
		Solve(min(Q,B));
		Q=max(0,Q-B);	
	}
	return 0;
}