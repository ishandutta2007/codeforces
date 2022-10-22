#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int n,q;
#define Maxn 100010
const int T=350;
int a[Maxn],to[Maxn];
struct Block{
	int l,r,dec,mx;
}B[T+5];int cnt=0;
void init(int u){
	B[u].mx=0;
	rep(i,B[u].l,B[u].r)B[u].mx=max(B[u].mx,a[i]);
}

int bel[Maxn];
void Build(int u){
	rep(i,B[u].l,B[u].r)
		if(a[i]-B[u].dec<B[u].l)bel[i]=i;
		else bel[i]=bel[a[i]-B[u].dec];
}
int go(int u){return max(a[u]-B[to[u]].dec,1);}

int vis[Maxn],visT=0;

void Modify(int l,int r,int x){
	rep(i,1,cnt)
		if(max(B[i].l,l)<=min(B[i].r,r)){
			bool flag=true;
			if(B[i].mx-B[i].dec<B[i].l)flag=false;
			if(max(B[i].l,l)==B[i].l&&min(B[i].r,r)==B[i].r)B[i].dec+=x,B[i].dec=min(B[i].dec,n);
			else{
				rep(j,max(B[i].l,l),min(B[i].r,r))a[j]-=x,a[j]=max(a[j],1);
				init(i);
			}
			if(flag)Build(i);
		}
}

int main(){
	rd(n);rd(q);
	rep(i,2,n)rd(a[i]);
	rep(i,1,(n-1)/T){
		cnt++;
		B[cnt].l=(i-1)*T+2;B[cnt].r=i*T+1;
		rep(j,B[cnt].l,B[cnt].r)to[j]=cnt;
		init(cnt);
		Build(cnt);
	}
	if((n-1)%T!=0){
		cnt++;
		B[cnt].r=n;B[cnt].l=n-(n-1)%T+1;
		rep(i,B[cnt].l,B[cnt].r)to[i]=cnt;
		init(cnt);
		Build(cnt);
	}
	int opt,l,r,x,u,v;
	rep(tt,1,q){
		rd(opt);
		if(opt==1){
			rd(l);rd(r);rd(x);
			Modify(l,r,x);
		}else{
			rd(u);rd(v);
			while(u!=v){
				if(to[u]<to[v])swap(u,v);
				if(to[u]!=to[v])u=go(bel[u]);
				else{
					if(bel[u]!=bel[v])u=go(bel[u]),v=go(bel[v]);
					else{
						int x=u;visT++;
						while(true){
							vis[x]=visT;
							if(x==bel[u])break;
							x=go(x);
						}	
						while(true){
							if(vis[v]==visT)break;
							v=go(v);
						}
						u=v;
					}
				}
			}
			printf("%d\n",u);
		}
	}
	return 0;
}