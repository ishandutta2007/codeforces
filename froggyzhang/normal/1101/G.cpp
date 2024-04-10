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
int n,now;
struct Basis{
	int d[31],sz;
	void Insert(int x){
		for(int i=30;i>=0;--i){
			if(x>>i&1){
				if(!d[i]){
					d[i]=x;++sz;
					return;
				}
				else x^=d[i];
			}
		}
	}
}B;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		now^=read();
		B.Insert(now);
	}
	if(!now)return !printf("-1\n");
	printf("%d\n",B.sz);
	return 0;
}