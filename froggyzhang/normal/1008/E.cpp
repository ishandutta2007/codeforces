#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cstdlib>
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
ll n;
inline int Ask(ll x,ll y){
	printf("%lld %lld\n",x,y);
	fflush(stdout);
	int t=read();
	if(!t)exit(0);
	return t;
} 
int main(){
	n=read();
	for(ll x=0,y=0,dx=min(n,1LL<<60),dy=min(n,1LL<<60);;){
		int t=Ask(x+dx,y+dy);
		if(t==1)x+=dx,dx=min(n-x,dx<<1);
		if(t==2)y+=dy,dy=min(n-y,dy<<1);
		if(t==3)dx=max(1LL,dx>>1),dy=max(1LL,dy>>1);
	}
	return 0;
}