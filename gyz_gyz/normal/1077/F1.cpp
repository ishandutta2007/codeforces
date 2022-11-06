#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 200000
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
int n,m,k,s,h,t,d[N];ll ans,a[N],f[2][N];
int main(){
	scanf("%d%d%d",&n,&k,&m);
	if(n/k>m){
		printf("-1\n");return 0;
	}
	rep(i,1,n)scanf("%I64d",&a[i]);
	rep(i,1,n)f[0][i]=-Inf;
	rep(i,1,m){
		s^=1;h=1;t=1;d[1]=0;f[s][0]=0;
		rep(j,1,n){
			if(d[h]+k<j)h++;f[s][j]=f[s^1][d[h]]+a[j];
			while(h<=t&&f[s^1][d[t]]<=f[s^1][j])t--;
			d[++t]=j;if(j+k>n)ans=max(ans,f[s][j]);
		}
	}
	printf("%I64d\n",ans);
}