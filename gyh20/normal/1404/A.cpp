#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t; 
}
int t,n,m,a[1000002],ia,b[1000002];
char s[1000002];
int main(){
	t=read();
	while(t--){
		n=read(),m=read();
		scanf("%s",s+1);ia=0;
		for(re int i=m+1;i<=n;++i){
			if(s[i]=='?')s[i]=s[i-m];
			if(s[i-m]=='?'||s[i]==s[i-m])continue;
			ia=1;break;
		}
		for(re int i=1;i<=n;++i)a[i]=a[i-1]+(s[i]=='1'?1:(s[i]=='0'?-1:0))-(s[i>=m?i-m:0]=='1'?1:(s[i>=m?i-m:0]=='0'?-1:0)),b[i]=b[i-1]+(s[i]=='?')-(s[i>=m?i-m:0]=='?');
		for(re int i=m;i<=n;++i)if(abs(a[i])>b[i])ia=1;
		puts(ia?"NO":"YES");
	}
}