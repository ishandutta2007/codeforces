#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mo=1e9+7;
const int inf=1e9;
int a[3];
void sol(){int ans=0;
	rep(i,0,2)scanf("%d",&a[i]);
	sort(a,a+3);
	dep(i,2,0)if(a[i])--a[i],++ans;
	dep(i,2,0)dep(j,i-1,0)if(a[i]&&a[j])--a[i],--a[j],++ans;
	if(a[0]&&a[1]&&a[2])++ans;
	printf("%d\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}