#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,inv2=499122177;
int f[1300010],cnt[1300010],ans[1300010],n,m;
int mp[1000010];
char s[1000010];
#define lowbit(x) ((x)&(-(x)))
inline void tag_xor(int &a,int &b){
	int h1=a,h2=b;
	a=(h1+h2)%mod;
	b=(h1-h2+mod)%mod;
}
inline void tag_ixor(int &a,int &b){
	int h1=a,h2=b;
	a=1ll*(h1+h2)*inv2%mod;
	b=1ll*(h1-h2+mod)*inv2%mod;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",&s);
		for(int i=0;i<m;i++)mp[i]=(mp[i]<<1)|(s[i]-'0');
	}
	for(int i=0;i<m;i++)cnt[mp[i]]++;
	for(int i=1;i<(1<<n);i++)f[i]=f[i^lowbit(i)]+1;
	for(int i=0;i<(1<<n);i++)f[i]=min(f[i],n-f[i]);
	for(int s=1;s<(1<<n);s<<=1)
		for(int i=0;i<(1<<n);i+=(s<<1))
			for(int j=0;j<s;j++){
				tag_xor(f[i+j],f[i+j+s]);
				tag_xor(cnt[i+j],cnt[i+j+s]);
			}
	for(int i=0;i<(1<<n);i++)ans[i]=(1ll*f[i]*cnt[i])%mod;
	for(int s=1;s<(1<<n);s<<=1)
		for(int i=0;i<(1<<n);i+=(s<<1))
			for(int j=0;j<s;j++)
				tag_ixor(ans[i+j],ans[i+j+s]);
	int lala=1e9;
	for(int i=0;i<(1<<n);i++)lala=min(lala,ans[i]);
	return cout<<lala,0;
}