#include<bits/stdc++.h>
using namespace std;
#define N 4000400
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
const int n=read(),mod=read();
int dp[N],s[N];
#define ck(x) (x)>=mod?(x)-mod:(x)
int main(){
	int sum=1;
	for(int i=1;i<=n;++i){
		s[i]=ck(s[i]+s[i-1]);
		dp[i]=ck(sum+s[i]);
		if(i==1)--sum;
		for(int j=2;j*i<=n;++j){
			s[i*j]=ck(s[i*j]+dp[i]);
			s[min(n+1,(i+1)*j)]=ck(s[min(n+1,(i+1)*j)]+mod-dp[i]);
		}
		sum=ck(sum+dp[i]);
	}
	printf("%d\n",dp[n]);
	return 0;
}