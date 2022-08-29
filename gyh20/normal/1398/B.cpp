#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,a[1000002],cnt;
char s[100002];
int main(){
	t=read();
	while(t--){
		scanf("%s",s+1);
		n=strlen(s+1);cnt=0;
		for(re int i=1;i<=n;++i){
			re int ans=0;
			if(s[i]=='1'){
				while(s[i]=='1')++ans,++i;
				a[++cnt]=ans;
			} 
		}
		sort(a+1,a+cnt+1);
		re int num=0;
		for(re int i=cnt;i>=1;i-=2)num+=a[i];
		printf("%d\n",num);
	}
}