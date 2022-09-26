#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
typedef long long ll;
#define N 100010
inline int read(){
	int x=0,f=1;
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
int T,n;
char s[N];
map<int,int> mp;
ll Solve(){
	n=read();
	scanf("%s",s+1); 
	mp.clear();
	++mp[0];
	ll ans=0;
	int now=0;
	for(int i=1;i<=n;++i){
		now+=s[i]-'0';
		ans+=mp[now-i];
		++mp[now-i];
	}
	return ans;
}
int main(){
	T=read();
	while(T--){
		printf("%I64d\n",Solve());
	}
	return 0;
}