#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
typedef long long ll;
#define N 1010
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
int x,n,pos,ans,C[N][N];
void init(int n){
	C[0][0]=1;
	for(int i=1;i<=n;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
}
int main(){
	n=read(),x=read(),pos=read();
	int small=0,big=0;
	init(n);
	int l=0,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(mid==pos){
			l=mid+1;continue;
		}
		if(mid<pos){
			++small,l=mid+1;
		}
		else{
			++big,r=mid;
		}
	}
	int ans=1LL*C[x-1][small]*C[n-x][big]%mod;
	
	auto fac=[&](int t)->void{
		for(int i=1;i<=t;++i){
			ans=1LL*ans*i%mod;
		}
	};
	fac(small),fac(big),fac(n-1-small-big);
	printf("%d\n",ans);
	return 0;
}