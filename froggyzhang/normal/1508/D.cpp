#include<bits/stdc++.h>
using namespace std;
#define N 2020
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
int a[N],n;
vector<pair<int,int> > ans;
inline void Swap(int x,int y){
	swap(a[x],a[y]);
	ans.emplace_back(x,y);
}
struct Union_Set{
	int f[N];
	void init(int n){
		for(int i=1;i<=n;++i)f[i]=i;
	}
	inline int getf(int x){
		return f[x]==x?x:f[x]=getf(f[x]);
	}
}S;
struct Point{
	int x,y,id;
	Point(int _x=0,int _y=0){x=_x,y=_y;}
	friend Point operator - (const Point &a,const Point &b){
		return Point(a.x-b.x,a.y-b.y);
	}
	friend bool operator < (const Point &a,const Point &b){
		return a.x==b.x?a.y<b.y:a.x<b.x;
	}
	friend ll operator % (const Point &a,const Point &b){
		return 1LL*a.x*b.y-1LL*a.y*b.x;
	}
	inline ll len(){
		return 1LL*x*x+1LL*y*y;
	}
}p[N],LTL;
inline bool Left(Point a,Point b){
	return a%b<0;
}
inline bool Para(Point a,Point b){
	return a%b==0;
}
inline bool cmp(Point a,Point b){
	a=a-LTL,b=b-LTL;	
	return Para(a,b)?a.len()<b.len():Left(a,b);
}
int main(){
	n=read();
	int _n=0;
	for(int i=1;i<=n;++i){
		int x=read(),y=read();
		a[i]=read();
		if(a[i]^i){
			++_n;
			p[_n].x=x,p[_n].y=y,p[_n].id=i;
		}
	}
	n=_n;
	if(!n){
		puts("0");
		return 0;
	}
	LTL=*min_element(p+1,p+n+1);
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;++i){
		static int vis[N];
		if(vis[p[i].id])continue;
		for(int u=p[i].id;!vis[u];u=a[u]){
			vis[u]=1;
			S.f[u]=p[i].id;
		}
	}
	for(int i=2;i<n;++i){
		int x=p[i].id,y=p[i+1].id;
		if(S.getf(x)==S.getf(y))continue;
		Swap(x,y);
		S.f[S.getf(y)]=S.getf(x);
	}
	while(p[1].id^a[p[1].id]){
		Swap(p[1].id,a[p[1].id]);
	}
	printf("%d\n",(int)ans.size());
	for(auto [x,y]:ans){
		printf("%d %d\n",x,y);
	}
	return 0;
}