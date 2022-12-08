#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef long long ll;
ll c[11][N];
int n,a[N];
void add(int x,int y,ll v) {
	if(!x) {
		c[y][x]+=v;
		return;
	}
	for(int i=x;i<=n;i+=i&-i)
		c[y][i]+=v;
}
ll sum(int x,int y) {
	ll ans=c[y][0];
	for(int i=x;i;i-=i&-i)
		ans+=c[y][i];
	return ans;
}
int main() {
	int k;
	ll ans=0;
	scanf("%d%d",&n,&k);
	add(0,0,1);
	for(int i=1;i<=n;i++) {
		scanf("%d",a+i);
		ans+=sum(a[i],k);
		for(int j=k;j>=1;j--)
			add(a[i],j,sum(a[i],j-1));
	}
	cout<<ans<<endl;
	return 0;
}