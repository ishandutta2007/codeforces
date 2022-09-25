#include<bits/stdc++.h>
using namespace std;
#define N 2505
typedef long double ld;
typedef long long ll;
const long double eps=1e-12;
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
int n;
ll ans;
struct Point{
	int x,y;
	Point(int _x=0,int _y=0){x=_x,y=_y;}
	friend Point operator - (const Point &a,const Point &b){
		return Point(a.x-b.x,a.y-b.y);
	}
	friend ll operator % (const Point &a,const Point &b){
		return 1LL*a.x*b.y-1LL*a.y*b.x;
	}
}p[N];
inline bool Left(Point a,Point b){
	return b%a>0;
}
void calc(int k){
	static long double t[N];
	vector<int> A,B,s;
	for(int i=1;i<=n;++i){
		if(i==k)continue;
		t[i]=atan2l(p[i].y-p[k].y,p[i].x-p[k].x);
		if(t[i]>=eps)A.push_back(i);
		else B.push_back(i);
	}
	sort(A.begin(),A.end(),[&](int i,int j){return t[i]<t[j];});
	sort(B.begin(),B.end(),[&](int i,int j){return t[i]<t[j];});
	s.resize(A.size());
	for(int i=0,j=0;i<(int)A.size();++i){
		while(j<(int)B.size()&&Left(p[B[j]]-p[k],p[A[i]]-p[k]))++j;
		s[i]=j;
	}
	ll sum=0;
	for(int i=1;i<(int)A.size();++i){
		sum+=s[i-1];
		ans+=1LL*s[i]*i-sum;
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		p[i].x=read(),p[i].y=read();
	}
	for(int i=1;i<=n;++i){
		calc(i);	
	}
	for(int i=1;i<=n;++i){
		p[i].x=-p[i].x;
		p[i].y=-p[i].y;
	}
	for(int i=1;i<=n;++i){
		calc(i);
	}
	ans=ans*(n-4)/2;
	printf("%lld\n",ans);
	return 0;
}