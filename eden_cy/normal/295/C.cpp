#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define EOR(i,x) for(int i=Head[x];~i;i=Nxt[i])
#define N 55

typedef long long ll;
const int Mod=(int)1e9+7;

ll C[N][N];
ll sz[N][N];
int dis[N][N];
int n,K;
struct node{
	int x,y;
};
node Que[N*N];
int main() {
	memset(dis,-1,sizeof(dis));
	FOR(i,0,50) {
		C[i][0]=1;
		FOR(j,1,i) C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
	}
	scanf("%d%d",&n,&K);
	if(n==0) {
		puts("0\n1");
		return 0;
	}
	int x,sum1=0,sum2=0;
	FOR(i,1,n) {
		scanf("%d",&x);
		if(x==50) sum1++;
		else sum2++;
	}
	int l=1,r=0;
	dis[sum1][sum2]=0;
	sz[sum1][sum2]=1;
	Que[++r]=(node){sum1,sum2};
	int res=-1;
	ll SZ=0;
	while(l<=r) {
		node q=Que[l++];
//		cerr<<q.x<<" "<<q.y<<" "<<dis[q.x][q.y]<<endl;
		if(~res && res!=dis[q.x][q.y]+1) break;
		if(q.x*50+q.y*100<=K) {
			if(!~res || dis[q.x][q.y]+1==res) {
				res=dis[q.x][q.y]+1;
				SZ=(SZ+sz[q.x][q.y])%Mod;
			}
			continue;
		}
		FOR(i,0,q.x) FOR(j,0,q.y) if(i || j) {
			if(i*50+j*100>K) break;
			int x=sum1-q.x+i,y=sum2-q.y+j;
			FOR(x1,0,x) FOR(y1,0,y) if(x1 || y1) {
				if(x1*50+y1*100>K) break;
				if(!~dis[q.x-i+x1][q.y-j+y1]) {
					dis[q.x-i+x1][q.y-j+y1]=dis[q.x][q.y]+2;
					Que[++r]=(node){q.x-i+x1,q.y-j+y1};
				}
				if(dis[q.x-i+x1][q.y-j+y1]==dis[q.x][q.y]+2) {
					sz[q.x-i+x1][q.y-j+y1]=(sz[q.x-i+x1][q.y-j+y1]+C[q.x][i]*C[q.y][j]%Mod*C[x][x1]%Mod*C[y][y1]%Mod*sz[q.x][q.y]%Mod)%Mod;
				}
			}
		}
	}
	printf("%d\n%lld\n",res,SZ);
	return 0;
}