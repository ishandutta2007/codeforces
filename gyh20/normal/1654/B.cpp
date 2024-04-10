#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,a[26],b[1000002],A,B,ans;
char s[1000002];
signed main(){
	t=read();
	while(t--){
		scanf("%s",s+1),n=strlen(s+1),memset(a,0,sizeof(a));
		for(re int i=1;i<=n;++i)++a[s[i]-'a'];
		for(re int i=1;i<=n;++i){
			if(a[s[i]-'a']>1)--a[s[i]-'a'];
			else{
				for(re int j=i;j<=n;++j)putchar(s[j]);
				puts("");break;
			}
		}
		
	}
}