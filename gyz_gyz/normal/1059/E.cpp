#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 200000
#define ll long long
#define pb push_back
#define mo 1000000007
#define add(x,y) x=(x+(y))%mo;
using namespace std;
int n,m,ans,h[N],a[N],d[N],f[N][18];ll k,s[N],w[N][18];
int main(){
	scanf("%d%d%I64d",&n,&m,&k);f[1][0]=1;
	rep(i,1,n){
		scanf("%d",&s[i]);
		if(s[i]>k){printf("-1");return 0;}
	}
	rep(i,2,n){
		scanf("%d",&f[i][0]);
		w[i][0]=s[f[i][0]];h[i]=h[f[i][0]]+1;
	}
	rep(j,1,17)rep(i,1,n){
		f[i][j]=f[f[i][j-1]][j-1];
		w[i][j]=w[i][j-1]+w[f[i][j-1]][j-1];
	}
	rep(i,1,n){
		int x=i,y=m-1;ll z=k-s[i];
		dep(j,17,0)if((y>=(1<<j))&&(z>=w[x][j])){
			y-=1<<j;z-=w[x][j];x=f[x][j];
		}d[i]=x;
	}
	dep(i,n,1){
		if((!a[i])||(h[a[i]]>h[i]))a[i]=d[i],ans++;
		if((i>1)&&((!a[f[i][0]])||(h[a[i]]<h[a[f[i][0]]])))a[f[i][0]]=a[i];
	}
	printf("%d",ans);
}