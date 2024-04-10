#include<cstdio>
#include<set>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 3010
#define M 310
using namespace std;
int n,m,tot,dl1[N*3],dl2[N*3],fr[N*3];
double ans,p[N][M],a[N*3][N],b[N*3];
struct pr{int x;double y;
	bool friend operator <(pr a,pr b){
		if(a.y==b.y)return a.x<b.x;else return a.y>b.y;
	}
}P;set<pr>s;
inline void cal(){int x=dl1[tot];
	rep(i,1,n)a[tot][i]=a[tot][i-1]*(1-p[i][x])
	+a[fr[tot]][i-1]*p[i][x];
	b[tot]=b[fr[tot]]+a[tot][n];
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)rep(j,1,m){
		scanf("%lf",&p[i][j]);p[i][j]/=1000;
	}
	rep(i,1,m){
		dl1[i]=i;dl2[i]=1;a[i][0]=1;tot++;cal();
		P.x=i;P.y=1-b[i];s.insert(P);
	}
	rep(i,1,n){
		P=*s.begin();s.erase(s.begin());
		ans+=P.y;tot++;fr[tot]=P.x;
		dl1[tot]=dl1[P.x];dl2[tot]=dl2[P.x]+1;cal();
		P.x=tot;P.y=1-b[tot];s.insert(P);
	}
	printf("%.12lf\n",ans);
}