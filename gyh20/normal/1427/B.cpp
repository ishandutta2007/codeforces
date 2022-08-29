#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
int n,m,t,a[1000002],b[1000002],ans,sum,cnt,lst,ll;
char s[200002];
int main(){
	t=read();
	while(t--){
		n=read(),m=read();sum=ll=ans=0;
		scanf("%s",s+1);
		for(re int i=1;i<=n;++i)sum+=(s[i]=='L'),ll|=(s[i]=='W'),ans+=(s[i]=='W');
		m=min(sum,m);ans+=max(0,(ll?m*2:m*2-1));
		cnt=lst=0;
		for(re int i=1;i<=n;++i){
			if(s[i]=='W'){
				if(lst)a[++cnt]=i-lst-1;
				lst=i;
			}
		}
		sort(a+1,a+cnt+1);
		for(re int i=1;i<=cnt;++i){
			if(m>=a[i])m-=a[i],++ans;
		}
		printf("%d\n",ans);
	}
}