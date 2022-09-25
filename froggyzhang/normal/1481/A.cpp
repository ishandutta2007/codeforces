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
int T,n,x,y;
char s[N];
int main(){
	T=read();
	while(T--){
		x=read(),y=read();
		scanf("%s",s+1);
		n=strlen(s+1);
		int L=0,R=0,U=0,D=0;
		for(int i=1;i<=n;++i){
			if(s[i]=='L')++L;
			else if(s[i]=='R')++R;
			else if(s[i]=='U')++U;
			else ++D;
		}
		bool ok=true;
		if(x>0&&R<x)ok=false;
		if(x<0&&L<(-x))ok=false;
		if(y>0&&U<y)ok=false;
		if(y<0&&D<(-y))ok=false;
		printf(ok?"YES\n":"NO\n");
	}
	return 0;
}