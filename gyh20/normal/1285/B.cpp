#include<bits/stdc++.h>
#define re register
using namespace std;
#define int long long
int n,a[100002],t,sum,mx,ans,ia;
inline int M(re int x,re int y){
	return x>y?x:y;
}
signed main(){
	scanf("%lld",&t);
	while(t--){
	sum=0;ia=0;
	mx=0;
	scanf("%lld",&n);
	for(re int i=1;i<=n;++i){
	scanf("%lld",&a[i]);sum+=a[i];if(sum<=0)ia=1;	}
	sum=0;
	for(re int i=n;i>=1;--i){
	sum+=a[i];if(sum<=0)ia=1;	}
	if(ia)puts("NO");
	else puts("YES");	}
}