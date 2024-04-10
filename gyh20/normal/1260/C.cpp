#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,p1,p2,p,k;
inline int g(re int x,re int y){
	return y?g(y,x%y):x;
}
signed main(){
//	freopen("color.in","r",stdin);
//	freopen("color.out","w",stdout);
	t=read();
	while(t--){
		p1=read();p2=read();k=read();
		p=g(p1,p2);
		p1/=p;p2/=p;
		if(p1<p2)swap(p1,p2);
		if((p1-2)/p2+1>=k)puts("REBEL");
		else puts("OBEY");
	}
}