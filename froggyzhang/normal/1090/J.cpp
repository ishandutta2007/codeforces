#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
char s[N],t[N];
int nxt[N],sum[N],n,m;
ll ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>(s+1)>>(t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	for(int i=2,j=0;i<=m;++i){
		while(j&&t[j+1]^t[i])j=nxt[j];
		j+=t[j+1]==t[i];
		nxt[i]=j;
	}
	for(int i=1,j=0;i<=n;++i){
		while(j&&t[j+1]^s[i])j=nxt[j];
		j+=t[j+1]==s[i];
		++sum[j<i?j:nxt[j]];
	}
	for(int i=m;i>=1;--i){
		sum[nxt[i]]+=sum[i];
	}
	ans=1LL*n*m;
	for(int i=1;i<=m;++i){
		if(nxt[i])ans-=sum[i-nxt[i]];	
	}
	cout<<ans<<'\n';
	return 0;
}