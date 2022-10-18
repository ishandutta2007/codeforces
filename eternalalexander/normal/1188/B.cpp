#include <bits/stdc++.h>
#define ll long long
std::multiset<int>table;
int n,p,k,a[400005];
ll ans=0;
int qpow(int a,int b){
	if (b==0)return 1;
	int d=qpow(a,b>>1);d=(ll)d*d%p;
	if (b&1)d=(ll)d*a%p;
	return d;
}

int main(){
	scanf("%d%d%d",&n,&p,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		int t=(qpow(a[i],4)-(ll)k*a[i]%p+p)%p;
		ans+=table.count(t);
		table.insert(t);
	}std::cout<<ans;
	return 0;
}