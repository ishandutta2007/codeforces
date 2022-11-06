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
int n,r,a[N],s[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);
		if(++s[a[i]]>s[r])r=a[i];
	}
	printf("%d\n",n-s[r]);
	rep(i,1,n)if(a[i]==r){
		dep(j,i-1,1){
			if(a[j]==r)break;
			printf("%d %d %d\n",a[j]<r?1:2,j,j+1);a[j]=r;
		}
		rep(j,i+1,n){
			if(a[j]==r)break;
			printf("%d %d %d\n",a[j]<r?1:2,j,j-1);a[j]=r;
		}
	}
}