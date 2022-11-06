#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define gc getchar()
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 1000010
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
typedef long long ll;
int n,h,a[N];
bool ck(int n){
	sort(a+1,a+n+1);ll d=0;
	rep(i,1,n)if((i&1)==(n&1))d+=a[i];
	return d<=h;
}
int main(){
	scanf("%d%d",&n,&h);
	rep(i,1,n){
		scanf("%d",&a[i]);
		if(!ck(i))return printf("%d\n",i-1),0;
	}
	printf("%d\n",n);
}