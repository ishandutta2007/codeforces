#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
int n,m,t,a[1000002],b[1000002],ans,sum;
int main(){
	t=read();
	while(t--){
		n=read();sum=0;
		for(re int i=1;i<=n;++i)a[i]=read(),sum+=a[i];
		sort(a+1,a+n+1);
		if(sum==0){
			puts("NO");
			continue;
		}
		else{
			puts("YES");
			if(sum>0)reverse(a+1,a+n+1);
			for(re int i=1;i<=n;++i)printf("%d ",a[i]);
			puts("");
		}
	}
}