#include<bits/stdc++.h>
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
int T,a[11];
char s[13];
void Solve(){
	scanf("%s",s+1);
	int n=10;
	for(int i=1;i<=n;++i){
		a[i]=s[i]=='?'?1:((s[i]-'0')^(i&1));
	}
	int ans=10;
	for(int i=1,cnt=0;i<=n;++i){
		if(a[i]==1)++cnt;
		if(cnt==6){
			ans=min(ans,i);break;
		}		
	}
	for(int i=1;i<=n;++i){
		a[i]=s[i]=='?'?0:((s[i]-'0')^(i&1));
	}
	for(int i=1,cnt=0;i<=n;++i){
		if(a[i]==0)++cnt;
		if(cnt==6){
			ans=min(ans,i);break;
		}		
	}
	printf("%d\n",ans);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}