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
int T,n,cnt[2][2],a[N];
char s[N];
inline bool ok(int x){
	if(s[x]=='?')return true;
	if(cnt[a[x]][(x&1)^1])return false;
	if(cnt[a[x]^1][x&1])return false;
	return true;
}
void Solve(){
	scanf("%s",s+1);
	n=strlen(s+1);
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;++i)a[i]=s[i]-'0';
	ll ans=0;
	for(int i=1,j=0;i<=n;++i){
		while(j<n&&ok(j+1))++j,(s[j]!='?'?++cnt[a[j]][j&1]:233);
		ans+=j-i+1;
		s[i]!='?'?--cnt[a[i]][i&1]:233;
	}
	printf("%lld\n",ans);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}