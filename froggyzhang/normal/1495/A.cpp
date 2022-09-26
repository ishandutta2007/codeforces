#include<bits/stdc++.h>
using namespace std;
#define N 100010
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
int T,n;
struct Point{
	int x,y;
	friend bool operator <(const Point &a,const Point &b){
		return !a.x?abs(a.y)<abs(b.y):abs(a.x)<abs(b.x);
	}
}a[N],b[N];
double Dis(Point a,Point b){
	return sqrt(1LL*(a.x-b.x)*(a.x-b.x)+1LL*(a.y-b.y)*(a.y-b.y));
}
double Solve(){
	n=read();
	for(int i=1,an=0,bn=0;i<=(n<<1);++i){
		int x=read(),y=read();
		if(!x)a[++an]={0,y};
		else b[++bn]={x,0};
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	double ans=0;
	for(int i=1;i<=n;++i){
		ans+=Dis(a[i],b[i]);
	}
	return ans;
}
int main(){
	T=read();
	while(T--){
		printf("%.11lf\n",Solve());
	}
	return 0;
}