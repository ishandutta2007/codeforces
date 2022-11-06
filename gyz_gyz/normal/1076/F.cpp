#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 3000000
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
int n;ll k,a[N],b[N],f[N],g[N];
int main(){
	scanf("%d%I64d",&n,&k);
	rep(i,1,n)scanf("%I64d",&a[i]);
	rep(i,1,n)scanf("%I64d",&b[i]);
	rep(i,1,n){
		f[i]=max(a[i]-(b[i]*k-f[i-1]),0ll);
		g[i]=max(b[i]-(a[i]*k-g[i-1]),0ll);
		if(f[i]>k||g[i]>k){
			printf("NO\n");return 0;
		}
	}printf("YES\n");
}