#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;
	re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0'){
		t=(t<<3)+(t<<1)+v-48;
		v=getchar();
	}
	return t;
}
int t,n,a[100002],k,l,cnt1,cnt2,ans,num;
char s[1000002];
int main(){
		n=read();
		scanf("%s",s+1);
		l=1;cnt1=cnt2=0;
		for(re int i=1;i<=n;++i){
			if(s[i]=='(')++cnt1;
			else ++cnt2;
		}
		if(cnt1!=cnt2){
			puts("-1");
			return 0;;
		}
		ans=0;cnt1=cnt2=0;
		for(re int i=1;i<=n;++i){
			if(s[i]=='(')++num;
			else if(s[i]==')'&&num)--num;
			else {
				++cnt1;++ans;
				while(cnt1){
					++i;
					if(s[i]=='(')--cnt1;
					else ++cnt1;
					++ans;
				}
			}
		}
		printf("%d\n",ans);
	
}