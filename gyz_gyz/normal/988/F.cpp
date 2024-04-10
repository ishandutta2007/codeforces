#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define N 2010
#define inf 1000000000
using namespace std;
typedef long long ll;
int n,m,k,a[N],w[N];bool v[N];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,m){int l,r;
		scanf("%d%d",&l,&r);
		rep(j,l,r-1)v[j]=1;
	}
	rep(i,0,n)w[i]=inf,a[i]=i?inf:0;
	rep(i,1,k){int x,y;
		scanf("%d%d",&x,&y);
		w[x]=min(w[x],y);
	}
	rep(i,0,n-1){
		if(!v[i])a[i+1]=min(a[i+1],a[i]);
		if(w[i]<inf)rep(j,i+1,n)a[j]=min(a[j],a[i]+w[i]*(j-i));
	}
	printf("%d\n",a[n]<inf?a[n]:-1);
}