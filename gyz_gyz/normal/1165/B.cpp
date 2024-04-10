#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const ll Inf=1e18;
int a[N];
int main(){int n,ans=0;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	rep(i,1,n)if(a[i]>ans)++ans;
	printf("%d\n",ans);
}