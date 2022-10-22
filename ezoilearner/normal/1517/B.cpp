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

int n,m,T;
#define Maxn 105
int b[Maxn][Maxn];
pii c[Maxn][Maxn];

struct Dat{
	int v;
	int x,j;
	bool operator <(const Dat &p)const{
		if(v!=p.v)return v<p.v;
		if(x!=p.x)return x<p.x;
		return j<p.j;	
	}
}seq[10005];int cnt;

int l[Maxn],r[Maxn],tag;
int a[Maxn][Maxn];

int main(){
	rd(T);
	while(T--){
		rd(n);rd(m);cnt=0;int len=0;
		rep(i,1,n){
			rep(j,1,m)rd(b[i][j]),c[i][j]=pii(b[i][j],j);
			sort(c[i]+1,c[i]+m+1);
			rep(j,1,m)seq[++cnt]=(Dat){c[i][j].FR,i,j};
			l[i]=1;r[i]=m;
		}
		sort(seq+1,seq+cnt+1);
		tag=0;ll ans=0;
		rep(i,1,cnt){
			int id=seq[i].x;
			int tl=l[id],tr=r[id]-tag;
			if(seq[i].j<tl||seq[i].j>tr)continue;
			len++;a[len][id]=c[id][l[id]].FR;
			rep(j,1,n)
				if(j!=id)a[len][j]=c[j][r[j]-tag].FR;
			l[id]++;tag++;r[id]++;
			ans+=seq[i].v;
		}
		rep(i,1,n){
			rep(j,1,m)printf("%d ",a[j][i]);
			puts("");
		}
	}
	return 0;
}