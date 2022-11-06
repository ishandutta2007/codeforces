#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mo=1e9+7;
int a[N],b[N];
int main(){int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	rep(i,1,n){
		if(i==1)b[i]=2;else b[i]=min(b[i-1]+1,n+1);
		while(b[i]<=n&&a[b[i]]-a[i]<m)++b[i];
	}int ans=0;
	rep(i,1,n){
		if(b[i]>n)break;
		ans=max(ans,min(i,n-i));
	}
	printf("%d\n",ans);
}