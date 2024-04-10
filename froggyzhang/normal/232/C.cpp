#include<bits/stdc++.h>
using namespace std;
#define N 88
const int inf=0x3f3f3f3f;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int Q,n,ax[N],ay[N],bx[N],by[N];
ll f[N];
int d[N];
void get_dis(int n,ll x,int *dis1,int *dis2){
	if(!n){
		dis1[0]=dis2[0]=0;
		return;
	}
	if(n==1){
		dis1[1]=x!=1;
		dis2[1]=x!=2;
		return;
	}
	if(x<=f[n-1]){
		get_dis(n-1,x,dis1,dis2);
		dis1[n]=min(dis1[n-1],dis2[n-1]+2);
		dis2[n]=min(dis1[n-1],dis2[n-1])+1+d[n-2];
	}
	else{
		get_dis(n-2,x-f[n-1],dis1,dis2);
		dis1[n]=dis1[n-2]+1;
		dis2[n]=dis2[n-2];
	}
}
int Solve(int n,ll x,ll y){
	if(!n)return 0;
	if(n==1)return x!=y;
	if(x<=f[n-1]&&y<=f[n-1])return min(Solve(n-1,x,y),min(ax[n-1]+by[n-1],bx[n-1]+ay[n-1])+2);
	if(x>f[n-1]&&y>f[n-1])return Solve(n-2,x-f[n-1],y-f[n-1]);
	if(x<=f[n-1])return min(ax[n-1],bx[n-1])+1+ay[n-2];
	return min(ay[n-1],by[n-1])+1+ax[n-2];
}
int main(){
	Q=read(),n=read();
	n=min(n,80);
	f[0]=1,f[1]=2;
	for(int i=2;i<=n;++i){
		f[i]=f[i-1]+f[i-2];
	}
	d[1]=1;
	for(int i=2;i<=n;++i)d[i]=d[i-2]+1;
	while(Q--){
		ll x=read(),y=read();
		get_dis(n,x,ax,bx);
		get_dis(n,y,ay,by);
		printf("%d\n",Solve(n,x,y));
	}
	return 0;
}