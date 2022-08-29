#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t; 
}
int n,a[1000002],t,ans;
signed main(){
	t=read();
	while(t--){
		n=read();
		for(re int i=1;i<=n;++i)a[i]=read();
		sort(a+1,a+n+1);
		re int sum=0;
		for(re int i=1;i<n;++i)sum+=a[i];
		if(sum<a[n])puts("T");
		else{
			sum+=a[n];
			if(sum&1)puts("T");
			else puts("HL");
		}
	}
}