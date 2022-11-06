#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define abs(x) ((x)<0?-(x):(x))
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define N 500000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n,m,x,t,tt,f[N];ll s1[N],s2[N];
struct nd{ll x,y;
	bool operator==(nd a){return (x==a.x)&&(y==a.y);}
}a[N],stk[N],bs;
bool ok(nd x,nd y,nd z){
	return x.x*y.y+y.x*z.y+z.x*x.y>x.x*z.y+y.x*x.y+z.x*y.y;
}
ll dis(nd x,nd y){
	return sqr(x.x-y.x)+sqr(x.y-y.y);
}
bool cmp(nd x,nd y){
	ll p=(x.x-bs.x)*(y.y-bs.y)-(y.x-bs.x)*(x.y-bs.y);
	if(p==0)return dis(x,bs)<dis(y,bs);else return p<0;
}
void sol(int n){
	rep(i,1,n){
		scanf("%I64d%I64d",&a[i].x,&a[i].y);
		if(i==1)bs=a[i];
		if((a[i].y<bs.y)||((a[i].y==bs.y)&&(a[i].x<bs.x)))bs=a[i];
	}
	rep(i,1,n)if(bs==a[i]){
		n--;rep(j,i,n)a[j]=a[j+1];break;
	}
	sort(a+1,a+n+1,cmp);
	stk[1]=bs;t=1;
	rep(i,1,n){
		while((t>1)&&(!ok(stk[t-1],a[i],stk[t])))t--;
		stk[++t]=a[i];
	}
	while((t>2)&&(!ok(stk[t-1],bs,stk[t])))t--;
}
int main(){
	scanf("%d%d",&n,&m);
	sol(n);tt=t;
	rep(i,1,t){
		s1[i*2-1]=dis(stk[i],stk[i%tt+1]);
		s1[i*2]=dis(stk[i],stk[(i+1)%tt+1]);
	}
	rep(i,2,t*2){
		for(x=f[i-1];x;x=f[x])if(s1[x+1]==s1[i])break;
		if(s1[x+1]==s1[i])f[i]=x+1;else f[i]=0;
	}
	sol(m);if(t!=tt){printf("NO");return 0;}
	rep(i,1,t){
		s2[i*2-1]=s2[i*2-1+t*2]=dis(stk[i],stk[i%tt+1]);
		s2[i*2]=s2[i*2+t*2]=dis(stk[i],stk[(i+1)%tt+1]);
	}x=0;
	rep(i,1,t*4){
		for(;x;x=f[x])if(s1[x+1]==s2[i])break;
		if(s1[x+1]==s2[i])x++;
		if(x==t*2){printf("YES");return 0;}
	}
	printf("NO");
}