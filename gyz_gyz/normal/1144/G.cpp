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
int n,a[N],b[N],s[N];bool fa[N],fb[N];
void wr(int x,bool y){
	if(x>1)wr(x-1,(!y&&fa[x])||(y&&!fb[x]));
	printf("%d ",y);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&s[i]);
		a[i]=-1;b[i]=inf;
	}
	a[1]=inf;b[1]=-1;
	rep(i,2,n){
		if(s[i]>s[i-1])a[i]=max(a[i],a[i-1]);
		if(s[i]<s[i-1])b[i]=min(b[i],b[i-1]);
		if(s[i]>b[i-1]&&s[i-1]>a[i])fa[i]=1,a[i]=s[i-1];
		if(s[i]<a[i-1]&&s[i-1]<b[i])fb[i]=1,b[i]=s[i-1];
	}
	if(a[n]==-1&&b[n]==inf)return printf("NO\n"),0;
	printf("YES\n");wr(n,b[n]<inf);
}