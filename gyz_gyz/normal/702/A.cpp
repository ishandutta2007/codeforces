#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
int a[N];
int main(){int n,t,ans=0;
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);
		if(i>1&&a[i]>a[i-1])++t;else t=1;
		ans=max(ans,t);
	}
	printf("%d\n",ans);
}