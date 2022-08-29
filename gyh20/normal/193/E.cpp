#include<bits/stdc++.h>
#define re register
#define int long long
#define ll long long
using namespace std;
inline ll read(){
	re ll t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const ll M=1e13,M1=1e7;
ll A,B,C,X1,Y1,X2,Y2,ans,n,m;
inline void add(re ll &x,re ll y){(x+=y)>=M?x-=M:x;}
inline ll Mod(re ll x){return x>=M?x-M:x;}
inline ll Mod1(re ll x){return x>=M1?x-M1:x;}
inline void chk(re ll v,re ll x,re ll y){
	if(y==n){
		ans=min(ans,v);
		return;
	}
    int ttt=0;
	for(re ll i=v+15000000;i<=15000000000000ll;i+=15000000){
		re ll z=((__int128)x*A+(__int128)y*B)%M,z1=((__int128)x*(B-A+M)+(__int128)y*A)%M;
		x=z1,y=z;
		if(y==n){
			ans=min(ans,i);
			return;
		}
	}
}
signed main(){
	B=1;ans=1e18;n=read(),m=n%M1;
	for(re int i=1;i<=15000000;++i)C=Mod(A+B),A=B,B=C;
	Y1=1,Y2=1;if(m==1)chk(0,0,1);
	for(re int i=1;i<=15000000;++i){
		C=Mod1(X2+Y2),X2=Y2,Y2=C;
		C=Mod(X1+Y1),X1=Y1,Y1=C;
		if(Y2==m)chk(i,X1,Y1);
	}
	if(ans==1e18)return puts("-1"),0;
	printf("%lld",ans+1);
}