//qwq
#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
pair<int,int> a[N];
int n;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i].first=read(),a[i].second=read();
	}
	sort(a+1,a+n+1);
	ll ans=0;
	for(int i=1;i<=n;++i){
		ans+=a[i].second;
	}
	int mx=a[1].first+a[1].second;
	for(int i=2;i<=n;++i){
		ans+=max(a[i].first-mx,0);
		mx=max(mx,a[i].first+a[i].second);
	}
	printf("%lld\n",ans);
	return 0;
}