#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int mo=998244353;
const int inf=1e9;
ll x[N],y[N],ax,ay,bx,by,t;
ll d(int i,int j){
	return abs(x[i]-x[j])+abs(y[i]-y[j]);
}
int main(){
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld",&x[0],&y[0],&ax,&ay,&bx,&by,&x[65],&y[65],&t);
	int n=0,ans=0;
	rep(i,1,64){
		x[i]=x[i-1]*ax+bx;
		y[i]=y[i-1]*ay+by;
		if(x[i]>2e16||y[i]>2e16)break;
		n=i;
	}
	rep(i,0,n)rep(j,0,i)rep(k,i,n){
		if(d(65,i)+d(i,j)+d(j,k)<=t)ans=max(ans,k-j+1);
		if(d(65,i)+d(i,k)+d(k,j)<=t)ans=max(ans,k-j+1);
	}
	printf("%d\n",ans);
}