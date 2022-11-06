#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 2000000
#define ll long long
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
int n,k,t,s[N],p[N];ll ans,a[N];
ll cal(ll l,ll r){
	ll s=(r+l)/k;ll s1=l/k;ll s2=r/k;ll ans=s;
	add(ans,(k*(s1+1))*s1/2);
	add(ans,(s-s1)*l);
	add(ans,(k*(s2+1))*s2/2);
	add(ans,(s-s2)*r);
	add(ans,mo-(k*(s+1))*s/2%mo);return ans;
}
int main(){
	scanf("%d%d",&n,&k);k--;
	rep(i,1,n){
		scanf("%I64d",&a[i]);
		for(;t&&a[s[t]]<=a[i];t--)add(ans,a[s[t]]*cal(s[t]-p[t],i-1-s[t]));
		t++;p[t]=s[t-1]+1;s[t]=i;
	}
	for(;t;t--)add(ans,a[s[t]]*cal(s[t]-p[t],n-s[t]));
	printf("%I64d\n",ans);
}