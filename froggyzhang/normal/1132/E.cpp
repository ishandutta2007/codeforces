#include<bits/stdc++.h>
using namespace std;
const int H=840;
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
ll W,cnt[9],sum;
bitset<17*H> dp;
int main(){
	W=read();
	for(int i=1;i<=8;++i)cnt[i]=read(),sum+=cnt[i]*i;
	if(sum<=W){
		return !printf("%lld\n",sum);
	}
	sum=0;
	for(int i=1;i<=8;++i){
		if(cnt[i]>2*(H/i)){
			ll t=min(W/H,(cnt[i]/(H/i)-1));
			sum+=t*H;
			W-=t*H;
			cnt[i]=cnt[i]%(H/i)+(H/i);
		}
	}
	dp[0]=1;
	for(int i=1;i<=8;++i){
		for(int j=1;j<=cnt[i];++j){
			dp|=dp<<i;	
		}
	}
	for(int i=W;i>=0;--i){
		if(dp[i]){sum+=i;break;}
	}
	printf("%lld\n",sum);
	return 0;
}