#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
typedef long long ll;
const int N=1e5+11;
const ll inf=LONG_LONG_MAX;
struct EDGE{
	int d,u,v,c;
	bool operator<(const EDGE&t)const{
		return d<t.d;
	}
} e[N];
int n,m,k;
ll a[N*20],b[N*20];
int dis[N],d[N];
int main(){
	n=rd(),m=rd(),k=rd();
	int mx=0; 
	rep(i,1,m){
		e[i].d=rd(),e[i].u=rd(),e[i].v=rd();
		e[i].c=rd();
		mx=max(mx,e[i].d);
	}
	sort(e+1,e+m+1);
	ll now=inf;
	int crt=n;
	rep(i,1,m){
		int T=e[i].d;
		if(e[i].u){
			if(!dis[e[i].u]){
				dis[e[i].u]=e[i].c;
				if(!(--crt)){
					now=0;
					rep(i,1,n)now+=dis[i];
					a[T]=now;
				}
			}
			else if(dis[e[i].u]>e[i].c){
				if(!crt) {
					now-=dis[e[i].u];
				dis[e[i].u]=e[i].c;
				now+=e[i].c;
				a[T]=now;
				}
				else dis[e[i].u]=e[i].c;
			}
		}
	}
	now=inf,crt=n;
	per(i,m,1){
		int T=e[i].d;
		if(e[i].v){
			if(!d[e[i].v]){
				d[e[i].v]=e[i].c;
				if(!(--crt)){
					now=0;
					rep(i,1,n)now+=d[i];
					b[T]=now;
				}
			}
			else if(d[e[i].v]>e[i].c){
				if(!crt) {
				now-=d[e[i].v];
				d[e[i].v]=e[i].c;
				now+=e[i].c;
				b[T]=now;	
				}
				else d[e[i].v]=e[i].c;;
			}
		}
	}
	ll ans=inf;
	per(i,mx,1)if(!b[i])b[i]=b[i+1];else if(b[i+1])b[i]=min(b[i],b[i+1]);
	rep(i,1,mx)if(!a[i])a[i]=a[i-1];else if(a[i-1])a[i]=min(a[i],a[i-1]);
	rep(i,1,mx-k-1){
		//cout << a[i] << " " << b[i] << endl;
		if(a[i]&&b[i+k+1])ans=min(ans,a[i]+b[i+k+1]);
	}
	if(ans!=inf)cout<<ans<<endl;
	else cout<<-1<<endl;
}