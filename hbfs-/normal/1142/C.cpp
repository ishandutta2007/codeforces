#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
using ll=long long;
constexpr int N=5e6+5;
struct poi{
	ll x,y;
	poi operator-(poi p){return {x-p.x,y-p.y};}
	ll operator*(poi p){return x*p.y-y*p.x;}
	void scan(){scanf("%lld%lld",&x,&y);}
}a[N];
bool cmp(poi p,poi q){
	if(p.x!=q.x)return p.x<q.x;
	return p.y<q.y;
}
int n;
int main(){
	scanf("%d",&n);
	rep(i,n)a[i].scan(),a[i].y-=a[i].x*a[i].x;
	sort(a+1,a+n+1,cmp);
	int top=0;
	rep(i,n){
		while(top>1&&(a[top]-a[top-1])*(a[i]-a[top-1])>=0)--top;
		a[++top]=a[i];
	}
	//rep(i,n)printf("%lld %lld\n",a[i].x,a[i].y);
	n=top;
	int ans=0;
	rep(i,n-1)if(a[i].x!=a[i+1].x)++ans;
	printf("%d\n",ans);
}