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
int n;char a[N];
void sol(){
	scanf("%d",&n);int ans=n;
	scanf("%s",a+1);
	rep(i,1,n)if(a[i]=='>'){
		ans=min(ans,i-1);break;
	}
	dep(i,n,1)if(a[i]=='<'){
		ans=min(ans,n-i);break;
	}
	printf("%d\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	while(t--)sol();
}