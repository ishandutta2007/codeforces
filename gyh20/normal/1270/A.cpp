#include<bits/stdc++.h>
using namespace std;
#define re register
#define int long long
inline int read(){
	re int t=0;
	re char v=getchar();
	while(v<'0'||v>'9')v=getchar();
	while(v>='0'&&v<='9'){
		t=(t<<3)+(t<<1)+(v^48);
		v=getchar();
	}
	return t;
}
int n,a,b,c,d,t,mx,mxp;
signed main(){
	t=read();
	while(t--){
		mxp=0;
		n=read();
		a=read();
		b=read();
		while(a--){
		c=read();
		if(c==n)mxp=1;
		}
		while(b--){
			c=read();
		}
		if(mxp)puts("YES");
		else puts("NO");
	}
	
}