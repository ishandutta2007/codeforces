#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 200000
#define mo 998244353
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,tot,ans,st,ed,a[N];bool v[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);tot+=a[i];
		if(a[i]>1)ans++;
	}
	if(tot<(n-1)*2){
		printf("NO\n");return 0;
	}
	printf("YES %d\n%d\n",min(n-1,ans+1),n-1);
	rep(i,1,n)if(!st){
		if(a[i]==1||i==n-1)st=i;
	}else{
		if(a[i]==1||i==n){ed=i;break;}
	}
	v[st]=1;--a[st];
	rep(i,1,n)if(i!=ed&&!v[i]&&a[i]>1){
		printf("%d %d\n",st,i);st=i;a[i]-=2;v[i]=1;
	}
	printf("%d %d\n",st,ed);--a[ed];v[ed]=1;st=1;
	rep(i,1,n)if(!v[i]){
		while(!v[st]||!a[st])++st;
		printf("%d %d\n",st,i);a[i]--;v[i]=1;a[st]--;
	}
}