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
int n;char a[N],b[N];
int main(){
	scanf("%d",&n);int up=0;
	scanf("%s",a+1);scanf("%s",b+1);
	rep(i,1,n){
		int tp=(up+a[i]+b[i])%2;
		int x=(up+a[i]+b[i])/2;
		if(x>'z')++a[i-1],x-=26;
		a[i]=x;up=tp*26;
	}
	dep(i,n,2)if(a[i]>'z')++a[i-1],a[i]-=26;
	printf("%s",a+1);
}