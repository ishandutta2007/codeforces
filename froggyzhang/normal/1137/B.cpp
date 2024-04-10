#include<bits/stdc++.h>
using namespace std;
#define N 500010
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
int n,nxt[N],m;
char s[N];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int c[2]={0,0};
	for(int i=1;i<=n;++i){
		++c[s[i]-'0'];
	}
	scanf("%s",s+1);
	m=strlen(s+1);
	for(int i=2,j=0;i<=m;++i){
		while(j&&s[j+1]!=s[i])j=nxt[j];
		if(s[j+1]==s[i])++j;
		nxt[i]=j;
	}
	int k=nxt[m];
	for(int i=1;i<=n;++i){
		int t=(i<=k?s[i]:s[(i-k-1)%(m-k)+k+1])-'0';
		if(!c[t])break;
		--c[t];
		putchar(t+'0');
	}
	while(c[0]--)putchar('0');
	while(c[1]--)putchar('1');
	return 0;
}