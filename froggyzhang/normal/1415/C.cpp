#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
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
int T,n,p,k,x,y,cnt[N],d[N];
char s[N];
int Solve(){
	n=read(),p=read(),k=read();
	scanf("%s",s+1);
	x=read(),y=read();
	for(int i=0;i<k;++i)cnt[i]=d[i]=0;
	int ans=0x7fffffff;
	for(int i=n;i>=p;--i){
		++d[i%k],cnt[i%k]+=s[i]-'0';
		ans=min(ans,x*(d[i%k]-cnt[i%k])+(i-p)*y);
	}
	return ans;
}
int main(){
	T=read();
	while(T--){
		printf("%d\n",Solve());
	}
	return 0;
}