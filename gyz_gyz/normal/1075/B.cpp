#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define fr first
#define sc second
#define ll long long
#define N 400000
#define mo 998244353
#define inf 1000000000
#define Inf 5000000000000000000ll
using namespace std;
int n,m,x,a[N],b[N],l[N],r[N],w[N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n+m)scanf("%d",&a[i]);
	rep(i,1,n+m){
		scanf("%d",&b[i]);
		if(b[i])x=i;else l[i]=x;
	}
	x=n+m+1;a[n+m+1]=inf*2;a[0]=-inf;
	dep(i,n+m,1)if(b[i])x=i;else r[i]=x;
	rep(i,1,n+m)if(!b[i]){
		if(a[i]-a[l[i]]<=a[r[i]]-a[i])w[l[i]]++;else w[r[i]]++;
	}
	rep(i,1,n+m)if(b[i])printf("%d ",w[i]);
}