#include<bits/stdc++.h>
#define re register
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
using namespace std;
int t,n,m,a[1000002],ans,x;
char s[102];
signed main(){
	t=read();
	while(t--){
		memset(s,0,sizeof(s));
		scanf("%s",s+1);
		n=strlen(s+1);
		for(re int i=1;i<=100;++i){
			re bool ia=0;
			for(re int j=1;j<n;++j){
				if(s[j]!=s[j+1]){
					for(re int k=j;k<=n;++k)s[k]=s[k+2];
					ia=1;n-=2;
					break;
				}
			}
			if(!ia){
				puts(i&1?"NET":"DA");
				break;
			}
		}
	}
}