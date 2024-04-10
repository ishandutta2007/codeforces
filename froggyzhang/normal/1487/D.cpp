#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,n,a[233333],tot;
int main(){
	T=read();
	for(int i=3;;i+=2){
		a[++tot]=(i*i-1)/2+1;
		if(a[tot]>1e9)break;
	}
	while(T--){
		n=read();
		printf("%d\n",upper_bound(a+1,a+tot+1,n)-a-1);
	}
	return 0;
}