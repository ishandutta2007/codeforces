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
int n,m;
struct Point{
	int x,y;
}p[N],L,R,U,D;
inline int Dis(Point a,Point b){
	return abs(a.x-b.x)+abs(a.y-b.y);
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		p[i].x=read(),p[i].y=read();
	}
	L=*min_element(p+1,p+n+1,[&](Point a,Point b){return a.x<b.x;});
	R=*max_element(p+1,p+n+1,[&](Point a,Point b){return a.x<b.x;});
	D=*min_element(p+1,p+n+1,[&](Point a,Point b){return a.y<b.y;});
	U=*max_element(p+1,p+n+1,[&](Point a,Point b){return a.y<b.y;});
	int ans=0;
	for(int i=1;i<=n;++i){
		ans=max(ans,Dis(L,p[i])+Dis(D,p[i])+Dis(L,D));
		ans=max(ans,Dis(R,p[i])+Dis(D,p[i])+Dis(R,D));
		ans=max(ans,Dis(L,p[i])+Dis(U,p[i])+Dis(L,U));
		ans=max(ans,Dis(R,p[i])+Dis(U,p[i])+Dis(R,U));
	}
	printf("%d ",ans);
	for(int i=4;i<=n;++i){
		printf("%d ",2*(R.x-L.x+U.y-D.y));
	}
	return 0;
}