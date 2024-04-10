#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define per(i,a,b) for(register int i=(a);i>=(b);--i)

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

int n,m;
#define Maxn 105
const int inf=1000000001;

pii tw[Maxn],h[Maxn];int T[Maxn];
int dis[1<<14][120];
int bel[1<<14];
int lowbit(int x){return x&(-x);}

struct Dat{
	int a,b,c;
	Dat(){a=b=c=0;}
	Dat(int _a,int _b,int _c){a=_a;b=_b;c=_c;}
	bool operator <(const Dat &p)const{return c<p.c;}
}dat[Maxn];

int mx[1<<14][Maxn],mn[1<<14][Maxn];

void cmax(int &x,int y){x=max(x,y);}
void cmin(int &x,int y){x=min(x,y);}

int main(){
	rd(n);rd(m);
	rep(i,0,n-1)bel[1<<i]=i;
	rep(i,0,n-1){
		rd(tw[i].FR);rd(tw[i].SE);
	}
	rep(i,0,m-1){
		rd(h[i].FR);rd(h[i].SE);
		rd(T[i]);dat[i]=Dat(h[i].FR,h[i].SE,T[i]);
	}
	sort(dat,dat+m);
	rep(i,0,m-1){
		h[i]=pii(dat[i].a,dat[i].b);
		T[i]=dat[i].c;
	}
	rep(i,0,n+m-1)dis[0][i]=inf;
	for(int sta=1;sta<(1<<n);++sta){
		int x=sta^lowbit(sta),y=bel[lowbit(sta)];
		rep(i,0,n-1){
			dis[sta][i]=min(dis[x][i],abs(tw[y].FR-tw[i].FR)+abs(tw[y].SE-tw[i].SE));	
		}
		rep(i,0,m-1){
			dis[sta][i+n]=min(dis[x][i+n],abs(tw[y].FR-h[i].FR)+abs(tw[y].SE-h[i].SE));
		}
	}	
	int all=(1<<n)-1;
	rep(i,0,all)
		rep(j,0,m){
			mn[i][j]=inf;
			mx[i][j]=-1;
		}
	rep(j,0,m-1)mx[0][j]=1;
	rep(i,0,n-1)mn[1<<i][0]=0;
	rep(sta,0,all){
		per(j,m,0)
			if(mn[sta][j]!=inf){
				rep(i,0,m-1)
					if(mn[sta][j]+dis[sta][i+n]<=T[i])cmax(mx[sta][i],j+1);
			rep(i,0,n-1)
				if(!(sta>>i&1))cmin(mn[sta|(1<<i)][j],mn[sta][j]+dis[sta][i]);
		}
		rep(j,0,m-1)
		if(mx[sta][j]!=-1){
			rep(k,0,n-1)
				if(!(sta>>k&1))cmin(mn[sta|(1<<k)][mx[sta][j]],T[j]+min(dis[sta][k],abs(tw[k].FR-h[j].FR)+abs(tw[k].SE-h[j].SE)));
			rep(k,j+1,m-1)
				if(min(dis[sta][k+n],abs(h[j].FR-h[k].FR)+abs(h[j].SE-h[k].SE))<=T[k]-T[j])cmax(mx[sta][k],mx[sta][j]+1);
		}				
	}
	int Ans=0;
	rep(i,0,all)rep(j,0,m-1)Ans=max(Ans,mx[i][j]);
	printf("%d\n",Ans);
	return 0;
}