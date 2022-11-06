#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define abs(x) ((x)<0?-(x):(x))
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define N 1000000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n,m,n1,n2,u,p3[20];
ll ans,X,Y,x,y,s1[N],s2[N],p[20],w1[N],w2[N];
ll gcd(ll x,ll y){
	if(!x)return y;else return gcd(y%x,x);
}
int main(){
	scanf("%d%I64d%I64d",&n,&X,&Y);
	if(Y%X){printf("0\n");return 0;}
	rep(i,1,n){
		scanf("%I64d",&x);
		if(!(x%X))s1[++n1]=x/X;
		if(!(Y%x))s2[++n2]=Y/x;
	}x=Y/X;
	rep(i,2,1000000){
		if(1ll*i*i>x)break;
		if(!(x%i)){
			p[++m]=i;while(!(x%i))x/=i;
		}
	}
	if(x==1)u=0;else u=1;
	if(u)rep(i,1,n1){
		y=gcd(x,s1[i]);
		if((y!=1)&&(y!=x)){u=0;
			while(!(x%y))x/=y;
			p[++m]=y;break;
		}
	}
	if(u)rep(i,1,n2){
		y=gcd(x,s2[i]);
		if((y!=1)&&(y!=x)){u=0;
			while(!(x%y))x/=y;
			p[++m]=y;break;
		}
	}
	if(x>1)p[++m]=x;
	rep(i,1,n1){x=0;
		rep(j,1,m)if(!(s1[i]%p[j]))x+=1<<(j-1);w1[x]++;
	}
	rep(i,1,n2){x=0;
		rep(j,1,m)if(!(s2[i]%p[j]))x+=1<<(j-1);w2[x]++;
	}
	p3[0]=1;rep(i,1,m)p3[i]=p3[i-1]*3;
	rep(i,0,p3[m]-1){x=0;y=0;
		rep(j,0,m-1){
			if(i/p3[j]%3==1)x+=1<<j;
			if(i/p3[j]%3==2)y+=1<<j;
		}
		ans+=w1[x]*w2[y];
	}
	printf("%I64d\n",ans);
}