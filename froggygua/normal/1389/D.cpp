#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
inline int read(){
	int x=0,f=1;
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
int n,l1,r1,l2,r2,T;
ll k;
ll Solve(){
	ll p=max(0,min(r1,r2)-max(l1,l2));
	k-=p*n;
	if(k<=0)return 0;
	ll res=max(r1,r2)-min(l1,l2)-p,h=max(r2-r1,r1-r2)+max(l2-l1,l1-l2);
	if(k<res)return max(0,max(l1,l2)-min(r1,r2))+k;
	ll ans1=h,ans2=h;
	k-=res;
	--n;
	ans2+=2LL*k;
	while(n&&k>=res){
		ans1+=h;
		k-=res;
		--n;
	}
	if(k){
		if(n)ans1+=min(2LL*k,max(0,max(l1,l2)-min(r1,r2))+k);
		else ans1+=2LL*k;
	}
	return min(ans1,ans2);
}
int main(){
	T=read();
	while(T--){
		n=read(),k=read();
		l1=read(),r1=read(),l2=read(),r2=read();
		printf("%I64d\n",Solve());
	}
	return 0;
}