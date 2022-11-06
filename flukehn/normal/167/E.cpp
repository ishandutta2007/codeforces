//  
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_st=(a);i>=i##_st;--i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef long long ll;
typedef pair<int,int> pii;
const int inf=~0u>>1,MOD=1e9+7;
inline int rd() {
    int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}

const int N=611;
struct Edge{int v;Edge*nxt;}pl[500011],*cur=pl,*G[N];
inline void ins(int u,int v){*cur=(Edge){v,G[u]},G[u]=cur++;} 
int p,n,m,f[N],a[N],b[N],t1,t2;
int In[N],Ou[N];
int c[N][N];
int Pow(int a,int b){
	int r=1;
	for(;b;b>>=1,a=1LL*a*a%p)
		if(b&1)r=1LL*r*a%p;
	return r;
}
inline void work(){
	queue<int> q;
	static int d[N];
	rep(i,1,n)d[i]=In[i];
	rep(i,1,t1)q.push(a[i]);
	while(!q.empty()){
		int x=q.front();q.pop();
		Es(x,i){
			f[i->v]=(f[i->v]+f[x])%p;
			if(!--d[i->v])q.push(i->v);
		}
	}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
#endif
	//freopen("orzcyr.in","r",stdin);
	//freopen("orzcyr.out","w",stdout);
	n=rd(),m=rd(),p=rd();
	//dbg(m),dbg(p);
	rep(i,1,m){
		int u=rd(),v=rd();
		ins(u,v);
		++In[v],++Ou[u];
	}
	//cerr<<"ok"<<endl;
	rep(i,1,n){if(!In[i])a[++t1]=i;if(!Ou[i])b[++t2]=i;}
	//cerr<<"ok"<<endl;
	rep(i,1,t1){
		memset(f,0,sizeof f);
		f[a[i]]=1,work();
		rep(j,1,t1)c[i][j]=f[b[j]];
	}
	//cerr<<"ok"<<endl;
	ll ans=1;
	/*cerr<<t1<<" "<<t2<<endl;
	rep(i,1,t1){
		rep(j,1,t2)cout<<c[i][j]<<" \n"[j==t2];
	}*/
	rep(i,1,t1-1){
		if(!c[i][i]){
			rep(j,i+1,t1){
				if(c[j][i]){swap(c[i],c[j]);ans=-ans;break;}
			}
		}
		if(!c[i][i]){
			cout<<0<<endl;
			return 0;
		}
		else{
			int r=Pow(c[i][i],p-2);
			//for(j=i+1;j<=n;++j){
			
			rep(j,i+1,t1){
				ll t=1LL*r*c[j][i]%p;
				rep(k,i,t1){
					c[j][k]=((c[j][k]-t*c[i][k])%p+p)%p;
				}
				/*while(c[j][i]){
					if(!c[i][i]){
						swap(c[i],c[j]);break;
					}
					ll t=c[j][i]/c[i][i];
					rep(k,i,t1){
						c[j][k]=((c[j][k]-t*c[i][k])%p+p)%p;
					}
					swap(c[i],c[j]);
				}*/
			}
		}
	}
	if(ans<0)ans=p-1;
	rep(i,1,t1)ans=ans*c[i][i]%p;
	cout<<ans<<endl;
}