#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
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
int n,a[233][233],T,m;
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		int ans=0,mn=0x3f3f3f3f,p=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				a[i][j]=read();
				ans+=abs(a[i][j]);
				mn=min(mn,abs(a[i][j]));
				if(a[i][j]<0)++p;
			}
		}
		if(p&1)ans-=2*mn;
		printf("%d\n",ans);
	}
	return 0;
}