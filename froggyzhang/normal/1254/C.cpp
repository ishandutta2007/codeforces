#include<bits/stdc++.h>
using namespace std;
#define N 2333
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
//#define mak akioi
namespace Grader{
	int n;
	struct Point{
		int x,y;
		Point(int _x=0,int _y=0){x=_x,y=_y;}
		friend Point operator - (const Point &a,const Point &b){
			return Point(a.x-b.x,a.y-b.y);
		}
		friend ll operator % (const Point &a,const Point &b){
			return 1LL*a.x*b.y-1LL*a.y*b.x;
		}
	}a[N];
	inline ll Abs(ll x){return x>=0?x:-x;}
	inline ll Ask1(int i,int j,int k){
		return Abs((a[j]-a[i])%(a[k]-a[i]));
	}
	inline int Ask2(int i,int j,int k){
		return (a[j]-a[i])%(a[k]-a[i])>0?1:-1;
	}
}
int n,p[N];
ll s[N];
ll Ask(int opt,int i,int j,int k){
	printf("%d %d %d %d\n",opt,i,j,k);
	fflush(stdout);
	#ifdef mak
	return opt==1?Grader::Ask1(i,j,k):Grader::Ask2(i,j,k);
	#endif
	return read();
}
int main(){
	n=read();
	#ifdef mak
	for(int i=1;i<=n;++i){
		Grader::a[i].x=read();
		Grader::a[i].y=read();
	}
	#endif
	int mn=2;
	for(int i=3;i<=n;++i){
		if(Ask(2,1,mn,i)==-1)mn=i;	
	}
	for(int i=2;i<=n;++i){
		p[i]=i;
		if(i==mn)continue;
		s[i]=Ask(1,1,mn,i);
	}
	sort(p+2,p+n+1,[&](int i,int j){return s[i]>s[j];});
	deque<int> ans;
	ans.push_back(p[2]);
	for(int i=3;i<n;++i){
		if(Ask(2,p[2],p[i],1)==-1)ans.push_front(p[i]);
		else ans.push_back(p[i]);
	}
	ans.push_front(mn);
	ans.push_front(1);
	printf("0 ");
	for(int i=0;i<n;++i){
		printf("%d ",ans[i]);
	}
	fflush(stdout);
	return 0;
}