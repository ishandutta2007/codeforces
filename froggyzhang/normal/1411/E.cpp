#include<bits/stdc++.h>
using namespace std;
#define N 100110
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
int n;
ll k,tot;
int cnt[66];
char s[N];
int main(){
	n=read();
	k=read();
	scanf("%s",s+1);
	k-=1LL<<(s[n]-'a');
	k+=1LL<<(s[n-1]-'a');
	if(k<0)k=-k;
	for(int i=1;i<=n-2;++i){
		++cnt[s[i]-'a'+1];
		k+=1LL<<(s[i]-'a');
		tot+=1LL<<(s[i]-'a'+1);
	}
	for(int i=0;i<=62;++i){
		if(k>>i&1){
			if(!cnt[i])return !printf("No\n");
			--cnt[i];
		}
		cnt[i+1]+=cnt[i]>>1;
	}
	printf("Yes\n");
	return 0;
}