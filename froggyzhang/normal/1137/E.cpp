#include<bits/stdc++.h>
using namespace std;
#define N 300030
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
ll n,K,B;
int Q;
struct Point{
	ll x,y;
	Point(ll _x=0,ll _y=0){x=_x;y=_y;}
	inline ll Val(){
		return K*x+y+B;
	}
	friend Point operator - (const Point &a,const Point &b){
		return Point(a.x-b.x,a.y-b.y);
	}
	friend __int128 operator % (const Point &a,const Point &b){
		return (__int128)a.x*b.y-(__int128)a.y*b.x;
	}
	
}st[N];
int top;
int main(){
	n=read(),Q=read();
	st[top=1]=Point(0,0);
	while(Q--){
		int opt=read();
		if(opt==1){
			n+=read();
			st[top=1]=Point(0,0);
			K=B=0;	
		}
		else if(opt==2){
			Point u=Point(n,-n*K-B);
			n+=read();
			while(top>1&&(u-st[top-1])%(st[top]-st[top-1])>=0)--top;
			st[++top]=u;
		}
		else{
			B+=read(),K+=read();
		}
		while(top>1&&st[top].Val()>=st[top-1].Val())--top;
		printf("%lld %lld\n",st[top].x+1,st[top].Val());
	}	
	return 0;
}