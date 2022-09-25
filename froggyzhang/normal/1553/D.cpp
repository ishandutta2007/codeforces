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
int T,n,m;
char s[N],t[N];
void Solve(){
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	for(int i=1,j=1;i<=m;++i){
		while(j<=n&&s[j]^t[i])j+=2;
		if(j>n)break;
		++j;
		if(i==m&&(n-j)&1){
			printf("YES\n");
			return;
		}
	}
	for(int i=1,j=2;i<=m;++i){
		while(j<=n&&s[j]^t[i])j+=2;
		if(j>n)break;
		++j;
		if(i==m&&(n-j)&1){
			printf("YES\n");
			return;
		}
	}
	printf("NO\n");
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}