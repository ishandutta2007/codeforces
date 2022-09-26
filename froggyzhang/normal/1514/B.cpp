#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
int n,k;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&k);
		printf("%d\n",qpow(n,k));
	}
}