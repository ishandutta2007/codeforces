#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,a[100002],b[100002];
signed main(){
	t=read();
	while(t--){
		n=read();re long long suma=0,sumb=0;
		bool ia=1;
		for(re int i=1;i<=n;++i){
			a[i]=read();b[i]=read();
			if(a[i]<a[i-1]||b[i]<b[i-1])ia=0;
			if(b[i]-b[i-1]>a[i]-a[i-1])ia=0;
		}
		if(ia)puts("YES");
		else puts("NO");
	}
}