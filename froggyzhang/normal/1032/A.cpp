#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
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
int n,k,cnt[101],ans;
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i){
		++cnt[read()];
	}
	int mx=0;
	for(int i=1;i<=100;++i){
		mx=max(mx,((cnt[i]-1)/k+1));
	}
	for(int i=1;i<=100;++i){
		if(cnt[i])ans+=mx*k-cnt[i];
	}
	printf("%d\n",ans);
	return 0;
}