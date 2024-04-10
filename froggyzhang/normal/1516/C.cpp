#include<bits/stdc++.h>
using namespace std;
#define N 123
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
int n,a[N],sum;
bitset<2001*2001> dp;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		sum+=a[i];
	}
	int pos=0;
	if(!(sum&1)){
		dp[0]=1;
		for(int i=1;i<=n;++i){
			dp=dp|(dp<<a[i]);
		}
		if(dp[sum>>1]){
			pair<int,int> mn=make_pair(1e9,1e9);
			for(int i=1;i<=n;++i){
				mn=min(mn,make_pair(__builtin_ctz(a[i]),i));
			}
			pos=mn.second;	
		}
	}
	if(!pos)puts("0");
	else{
		printf("1\n%d\n",pos);
	}
	return 0;
}