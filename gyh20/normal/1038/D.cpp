#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
int n,a[500002];
long long ans;
int main(){
	n=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	if(n==1){
		printf("%d",a[1]);
		return 0;
	}
	sort(a+1,a+n+1);
	if(a[1]>=0&&a[n]>=0){
		for(re int i=2;i<=n;++i)ans+=a[i];
		ans-=a[1];
	}
	else if(a[1]<=0&&a[n]<=0){
		for(re int i=1;i<n;++i)ans-=a[i];
		ans+=a[n];
	}
	else{
		for(re int i=1;i<=n;++i)ans+=abs(a[i]);
	}
	printf("%lld",ans);
}