
 #include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 3000010
#define mo 998244353
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,a[N],b[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)scanf("%d",&b[i]);
	dep(i,n,2)a[i]-=a[i-1],b[i]-=b[i-1];
	sort(a+2,a+n+1);sort(b+2,b+n+1);
	rep(i,1,n)if(a[i]!=b[i])return printf("No\n"),0;
	printf("Yes\n");
}