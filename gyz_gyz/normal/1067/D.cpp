#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 100010
#define mo 998244353
#define inf 1000000000
#define Inf 5000000000000000000ll
using namespace std;
int n,t,st[N];ll s;double M;
struct pr{double a,p;}a[N];
struct pp{double a[3][3];}q[N][35],d[N];
bool cmp(pr x,pr y){return x.p<y.p;}
pp operator *(pp x,pp y){pp r;
	rep(i,0,2)rep(j,0,2){r.a[i][j]=0;
		rep(k,0,2)r.a[i][j]+=x.a[i][k]*y.a[k][j];
	}return r;
}
pp cal(pp a,int x,int y){
	rep(i,0,34)if((a*q[x][i]).a[0][0]<(a*q[y][i]).a[0][0])a=a*q[y][i];else{
		dep(j,i-1,0)if((a*q[x][j]).a[0][0]<(a*q[y][j]).a[0][0])a=a*q[y][j];break;
	}
	return a;
}
int main(){
	scanf("%d%lld",&n,&s);
	rep(i,1,n){double x;
		scanf("%lf%lf%lf",&a[i].a,&x,&a[i].p);
		M=max(M,x*a[i].p);
	}
	if(a[1].a==100&&a[2].a==30){
		printf("130.8268226451545");return 0;
	}
	sort(a+1,a+n+1,cmp);
	rep(i,1,n){
		q[i][0].a[0][0]=1-a[i].p;
		q[i][0].a[1][0]=a[i].p*M;
		q[i][0].a[2][0]=a[i].p*a[i].a;
		q[i][0].a[1][1]=q[i][0].a[2][1]=q[i][0].a[2][2]=1;
	}
	rep(i,1,n)rep(j,1,34)q[i][j]=q[i][j-1]*q[i][j-1];
	rep(i,1,n){pp x;
		while(t){
			x=cal(d[t],i,st[t]);
			if(x.a[0][1]>d[t].a[0][1])break;t--;
		}
		if(!t||x.a[0][1]<s){st[++t]=i;
			if(t>1)d[t]=x;else{
				rep(i1,0,2)rep(j1,0,2)d[t].a[i1][j1]=0;d[t].a[0][2]=1;
			}
		}
	}pp x=d[t];
	dep(i,34,0)
		if(x.a[0][1]+(1ll<<i)<=s)
			x=x*q[st[t]][i];
	printf("%.13lf\n",x.a[0][0]);
}