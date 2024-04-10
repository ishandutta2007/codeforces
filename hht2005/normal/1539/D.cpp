#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
#define int long long
struct node{
	int a,b;
	int operator<(const node &x)const {
		return b<x.b;
	}
}v[maxn];
int c[maxn];
signed main() {
	int n,sum=0,ans=0,S=0,Ans=1e18;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) {
		scanf("%lld%lld",&v[i].a,&v[i].b);
		S+=v[i].a;
	}
	sort(v+1,v+n+1);
	for(int i=n;i>=1;i--) {
		int t=min(v[i].a,v[1].b-sum);
		c[i]+=t;
		sum+=t;
		ans+=2*t;
		if(sum>=v[1].b)break;
	}
	for(int i=1;i<=n;i++) {
		if(v[i].b>sum) {
			Ans=min(Ans,ans+2*(S-sum));
			S+=(v[i].b-sum);
			ans+=(v[i].b-sum);
			sum=v[i].b;
		}
		sum+=(v[i].a-c[i]);
		ans+=(v[i].a-c[i]);
		c[i]=v[i].a;
	}
	Ans=min(Ans,ans);
	cout<<Ans<<endl;
	return 0;
}