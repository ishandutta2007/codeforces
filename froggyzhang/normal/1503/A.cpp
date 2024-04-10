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
int n,T;
char s[N],a[N],b[N];
inline bool check(char *s){
	int now=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='(')++now;
		else --now;
		if(now<0)return false;
	}
	return now==0;	
}
void Solve(){
	n=read();
	scanf("%s",s+1);
	int tot=0;
	for(int i=1;i<=n;++i){
		tot+=s[i]-'0';
	}
	if(tot&1){
		printf("NO\n");
		return;
	}
	int now1=0,now2=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='1'){
			++now1;
			if(now1<=(tot>>1))a[i]='(',b[i]='(';
			else a[i]=')',b[i]=')';
		}
		else{
			now2^=1;
			if(now2)a[i]='(',b[i]=')';
			else a[i]=')',b[i]='(';
		}
	}
	if(!check(a)||!check(b)){
		printf("NO\n");
		return;
	}
	printf("YES\n");
	for(int i=1;i<=n;++i){
		putchar(a[i]);
	}
	putchar('\n');
	for(int i=1;i<=n;++i){
		putchar(b[i]);
	}
	putchar('\n');
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}