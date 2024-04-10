#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=4e5+10;
struct pr{
	int x,y;
	friend bool operator<(const pr&a,const pr&b){
		return a.x+a.y<b.x+b.y;
	}
}a[N];
void sol(){int n;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1);
	rep(i,1,n)if(a[i].x<a[i-1].x||a[i].y<a[i-1].y){
		printf("NO\n");return;
	}
	printf("YES\n");
	rep(i,1,n){
		rep(j,a[i-1].x+1,a[i].x)printf("R");
		rep(j,a[i-1].y+1,a[i].y)printf("U");
	}printf("\n");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}