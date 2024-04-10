#include<bits/stdc++.h>
using namespace std;
#define N 400020
const double eps=1e-9;
const double PI=acos(-1.0);
typedef long long ll;
int n;
ll m;
struct Point{
	double x,y;
	Point(double _x=0,double _y=0){x=_x,y=_y;}
	friend Point operator + (const Point &a,const Point &b){
		return Point(a.x+b.x,a.y+b.y);	
	}
	friend Point operator - (const Point &a,const Point &b){
		return Point(a.x-b.x,a.y-b.y);	
	}
	inline double len(){
		return sqrt(x*x+y*y);
	}
}p[N];
double Normal(double ang){
	if(ang>=PI)ang-=2*PI;
	if(ang<-PI)ang+=2*PI;
	return ang;
}
class BIT{
	int b[N];
	inline int lowbit(int x){return x&(-x);}
public:
	void Clear(){
		memset(b,0,sizeof(b));
	}
	inline void Add(int x,int d){
		while(x<=2*n)b[x]+=d,x+=lowbit(x);
	}
	inline int Ask(int x){
		int ans=0;
		while(x)ans+=b[x],x-=lowbit(x);
		return ans;
	}
}B;
ll check(double x){
	static bool In[N];
	static double b[N],_l[N],_r[N];
	static int P[N],len;
	len=0;
	for(int i=1;i<=n;++i){
		In[i]=false;
		if(p[i].len()<=x){
			In[i]=true;
			continue;
		}
		double t=acos(x/p[i].len());
		double d=atan2(p[i].y,p[i].x);
		double t1=Normal(d-t),t2=Normal(d+t);
		if(t1>t2)swap(t1,t2);
		_l[i]=t1,_r[i]=t2;
		b[++len]=t1,b[++len]=t2;
	}
	B.Clear();
	for(int i=1;i<=n;++i){
		P[i]=i;
	}
	sort(P+1,P+n+1,[&](int i,int j){return _l[i]<_l[j];});
	sort(b+1,b+len+1);
	ll tot=1LL*n*(n-1)/2;
	for(int i=1;i<=n;++i){
		int u=P[i];
		if(In[u])continue;
		int l=lower_bound(b+1,b+len+1,_l[u])-b;
		int r=lower_bound(b+1,b+len+1,_r[u])-b;
		tot-=B.Ask(r)-B.Ask(l-1);
		B.Add(r,1);
	}
	return tot;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.setf(ios::fixed);
	cout.precision(9);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>p[i].x>>p[i].y;	
	}
	double l=0,r=1e5;
	while(r-l>eps){
		double mid=(l+r)/2.0;
		if(check(mid)>=m){
			r=mid;	
		}
		else{
			l=mid;
		}
	}
	cout<<r<<'\n';
	return 0;
}