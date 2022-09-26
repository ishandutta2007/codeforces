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
int T,n;
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			if(i==1)putchar('9');
			else if(i==2)putchar('8');
			else if(i==3)putchar('9');
			else
			putchar('0'+(i-4)%10);
		}
		putchar('\n');
	}
	return 0;
}