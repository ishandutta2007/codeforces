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
int n,tot,a[N],wr[N];
bool ck(int m){
	rep(i,0,n-1)if(a[i]!=a[i%m])return 0;return 1;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);a[i-1]=a[i]-a[i-1];
	}
	rep(i,1,n)if(ck(i))wr[++tot]=i;
	printf("%d\n",tot);
	rep(i,1,tot)printf("%d ",wr[i]);
}