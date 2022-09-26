#include<bits/stdc++.h>
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
int T,n,k,cnt[26];
char s[N],ans[N];
inline bool check(int p){
	int rem=n-p;
	for(int i=0;i<26;++i){
		rem-=(k-cnt[i]%k)%k;
		if(rem<0)return false;
	}
	return true;
}
bool Solve(){
	scanf("%s",s+1);
	if(n%k)return false;
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;++i){
		++cnt[s[i]-'a'];
	}
	int pos=n;
	while(~pos){
		if(pos==n){
			if(check(pos)){
				break;
			}
		}
		else{
			bool ok=false;
			for(char c=s[pos+1]+1;c<='z';++c){
				ans[pos+1]=c;++cnt[c-'a'];
				if(check(pos+1)){
					ok=true;
					break;
				}
				--cnt[c-'a'];
			}
			if(ok)break;
		}
		if(pos>0)--cnt[s[pos]-'a'];
		--pos;
	}
	if(pos<0)return false;
	for(int i=1;i<=pos;++i)ans[i]=s[i];
	for(int i=pos+2;i<=n;++i){
		bool ok=false;
		for(char c='a';c<='z';++c){
			ans[i]=c;++cnt[c-'a'];
			if(check(i)){
				ok=true;
				break;
			}
			--cnt[c-'a'];
		}
		if(!ok)return false;
	}
	for(int i=1;i<=n;++i){
		putchar(ans[i]);
	}
	putchar('\n');
	return true;
}
int main(){
	T=read();
	while(T--){
		n=read(),k=read();
		if(!Solve())printf("-1\n");;
	}
	return 0;
}