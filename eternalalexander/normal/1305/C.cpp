#include <bits/stdc++.h>
#define maxn 200005
#define ll long long
int n,m,a[maxn],vis[1005],ans=1;
ll cnt[1005];
int dec(int x){return x>=m?x-m:x;}
int qpow(int a,ll b){
	if(b==0)return 1;
	int d=qpow(a,b>>1);d=d*d%m;
	if(b&1)d=d*a%m;
	return d;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		int d=a[i]%m;
		for(register int j=0;j<m;++j)
			cnt[dec(d-j+m)]+=vis[j];
		vis[d]++;
	}for(int i=0;i<m;++i)
		ans=ans*qpow(i,cnt[i])%m;
	std::cout<<ans;
	return 0;
}