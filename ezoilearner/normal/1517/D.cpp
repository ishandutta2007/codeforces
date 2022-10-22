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

const int inf=1000000000;

int n,m,k;
#define Maxn 505
int dir=0;
int nx[4]={-1,1,0,0};
int ny[4]={0,0,-1,1};

int b[Maxn][Maxn][4];

vector<pii> vec[2];

int c[Maxn][Maxn][11];

int vis[Maxn][Maxn],visT;

void umin(int &x,int y){x=min(x,y);} 

int main(){
	rd(n);rd(m);rd(k);
	if(k&1){
		rep(i,1,n){
			rep(j,1,m)printf("-1 ");
			puts("");
		}
		return 0;
	}
	rep(i,1,n)
		rep(j,1,m)
			rep(k,0,3)b[i][j][k]=inf;
	int x,y;
	rep(i,1,n)
		rep(j,1,m-1){
			rd(x);
			b[i][j][3]=x;
			b[i][j+1][2]=x;	
		}
	rep(i,1,n-1)
		rep(j,1,m){
			rd(x);
			b[i][j][1]=x;
			b[i+1][j][0]=x;
		}
	rep(i,1,n)
		rep(j,1,m)c[i][j][0]=0;
	rep(t,1,k/2){
		rep(i,1,n)
			rep(j,1,m)c[i][j][t]=inf;
		rep(i,1,n)
			rep(j,1,m)
				rep(l,0,3)
					umin(c[i+nx[l]][j+ny[l]][t],c[i][j][t-1]+b[i][j][l]);
	}
	rep(i,1,n){
		rep(j,1,m)printf("%d ",c[i][j][k/2]*2);
		puts("");
	}
	return 0;
}