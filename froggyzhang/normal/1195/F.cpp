#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
#define N 300010
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
map<pair<int,int>,int> id;
int n,tot,Q,ans[N],las[N];
vector<pair<int,int> > q[N];
inline int _gcd(int a,int b){
	if(b==0)return a;
	if(a==0)return b;
	return _gcd(b,a%b);
}
inline int Abs(int x){
	return x>=0?x:-x;
}
struct Point{
	int x,y;
	Point(int _x=0,int _y=0){x=_x,y=_y;};
	Point operator -(const Point b)const{
		return Point(x-b.x,y-b.y);
	}
};
vector<Point> p[N];
vector<int> t[N];
struct BIT{
	int b[N];
	inline int lowbit(int x){
		return x&(-x);
	}
	inline void Add(int x,int d){
		while(x<=n){
			b[x]+=d;
			x+=lowbit(x);
		}
	}
	inline int Ask(int x){
		int ans=0;
		while(x){
			ans+=b[x];
			x-=lowbit(x);
		}
		return ans;
	}
}B;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		int k=read();
		while(k--){
			int x=read(),y=read();
			p[i].push_back(Point(x,y));
		}
		for(int j=0;j<(int)p[i].size();++j){
			Point a=p[i][j]-p[i][(j+1)%p[i].size()];
			int g=_gcd(Abs(a.x),Abs(a.y));
			a.x/=g,a.y/=g;
			if(!id.count(make_pair(a.x,a.y)))id[make_pair(a.x,a.y)]=++tot;
			t[i].push_back(id[make_pair(a.x,a.y)]);
		}	
	}
	Q=read();
	for(int i=1;i<=Q;++i){
		int l=read(),r=read();
		q[r].emplace_back(l,i);
	}
	for(int i=1;i<=n;++i){
		for(auto x:t[i]){
			if(las[x]){
				B.Add(las[x],-1);
			}
			B.Add(i,1);
			las[x]=i;
		}
		for(auto [l,id]:q[i]){
			ans[id]=B.Ask(i)-B.Ask(l-1);
		}
	}
	for(int i=1;i<=Q;++i){
		printf("%d\n",ans[i]);
	}
	return 0;
}