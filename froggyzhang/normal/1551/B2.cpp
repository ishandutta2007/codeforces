#include<bits/stdc++.h>
using namespace std;
#define N 200020
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
int T,n,K,a[N];
vector<int> p[N];
void Solve(){
	n=read(),K=read();
	for(int i=1;i<=n;++i)p[i].clear(),a[i]=0;
	for(int i=1;i<=n;++i){
		p[read()].push_back(i);
	}
	int sum=0;
	for(int i=1;i<=n;++i){
		sum+=min(K,(int)p[i].size());
	}
	sum=sum/K*K;
	for(int i=1;i<=n;++i){
		for(int j=0;j<min(K,(int)p[i].size())&&sum;++j,--sum)a[p[i][j]]=sum%K+1;
	}
	for(int i=1;i<=n;++i)printf("%d ",a[i]);
	printf("\n");
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}