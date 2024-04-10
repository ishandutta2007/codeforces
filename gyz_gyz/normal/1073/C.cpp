#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 2000000
#define mo 998244353
#define inf 1000000000
#define Inf 5000000000000000000ll
using namespace std;
int n,x,y,l,r,m,px[N],py[N],qx[N],qy[N];char s[N];
bool ck(int m){
	rep(i,0,n-m)if(abs(px[i]+qx[i+m+1]-x)+abs(py[i]+qy[i+m+1]-y)<=m)return 1;
	return 0;
}
int main(){
	scanf("%d",&n);scanf("%s",s+1);
	scanf("%d%d",&x,&y);
	if(abs(x)+abs(y)>n||(abs(x+y)&1)!=(n&1)){
		printf("-1\n");return 0;
	}
	rep(i,1,n){
		px[i]=px[i-1];py[i]=py[i-1];
		if(s[i]=='U')py[i]++;
		if(s[i]=='D')py[i]--;
		if(s[i]=='L')px[i]--;
		if(s[i]=='R')px[i]++;
	}
	dep(i,n,1){
		qx[i]=qx[i+1];qy[i]=qy[i+1];
		if(s[i]=='U')qy[i]++;
		if(s[i]=='D')qy[i]--;
		if(s[i]=='L')qx[i]--;
		if(s[i]=='R')qx[i]++;
	}
	l=0;r=n;m=(l+r)/2;
	for(;l<r;m=(l+r)/2)
		if(ck(m))r=m;else l=m+1;
	printf("%d\n",m);
}