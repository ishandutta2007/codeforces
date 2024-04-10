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
int T,a[4],p[4];
int main(){
	T=read();
	while(T--){
		for(int i=0;i<4;++i){
			a[i]=read(),p[i]=i;
		}
		sort(p,p+4,[&](int i,int j){return a[i]>a[j];});
		printf((p[0]>>1)==(p[1]>>1)?"NO\n":"YES\n");
	}
	return 0;
}