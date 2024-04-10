#include<bits/stdc++.h>
using namespace std;
#define y1 ysgh
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
int T,n,m,x1,y1,x2,y2,w,h;
int Solve(){
	n=read(),m=read();
	x1=read(),y1=read(),x2=read(),y2=read();
	w=read(),h=read();
	int lenx=x2-x1,leny=y2-y1;
	int ans=1e9;
	if(w+lenx<=n)ans=min(ans,min(w-x1,x2-(n-w)));
	if(h+leny<=m)ans=min(ans,min(h-y1,y2-(m-h)));
	ans=max(ans,0); 
	return ans==1e9?-1:ans;
}
int main(){
	T=read();
	while(T--){
		printf("%d\n",Solve());
	}
	return 0;
}