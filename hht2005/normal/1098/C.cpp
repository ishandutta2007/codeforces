#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int n,m,cnt[N],D,fa[N];
int check(int x) {
	int t=n,dep=1,sum=0;
	for(int i=1;i<=t;i*=x) {
		sum+=dep*i;
		cnt[dep++]=i;
		t-=i;
	}
	cnt[dep]=t;
	sum+=t*dep;
	D=dep;
	return sum;
}
signed main() {
	scanf("%lld%lld",&n,&m);
	if(m==n*(n+1)/2) {
		puts("Yes");
		for(int i=2;i<=n;i++)
			printf("%lld ",i-1);
		puts("");
		return 0;
	}
	if(m>n*(n+1)/2||m<2*n-1) {
		puts("No");
		return 0;
	}
	int l=1,r=n-1;
	while(l<=r) {
		int mid=(l+r)>>1;
		if(check(mid)>m)l=mid+1;
		else r=mid-1;
	}
	int ans=0;
	if(l-1)ans=check(l-1);
	int a=2,b=D;
	while(1) {
		int now=min(cnt[a-1]*l-cnt[a],cnt[b]);
		if(ans-now*(b-a)<=m)break;
		ans-=now*(b-a);
		cnt[a]+=now;
		cnt[b]-=now;
		if(cnt[a-1]*l==cnt[a])a++;
		if(cnt[b]==0)b--;
	}
	ans-=m;
	int now=ans/(b-a);
	ans-=now*(b-a);
	cnt[a]+=now;
	cnt[b]-=now;
	cnt[b]--;
	cnt[b-ans]++;
	now=1,ans=0;
	for(int i=2;i<=b;i++) {
		int t=now;
		ans=0;
		now+=cnt[i-1];
		for(int j=1;j<=cnt[i];j++) {
			fa[now+j-1]=t;
			ans++;
			if(ans==l)t++,ans=0;
		}
	}
	puts("Yes");
	for(int i=2;i<=n;i++)
		printf("%lld ",fa[i]);
	puts("");
	return 0;
}