#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mo=1e9+7;
int a[N];
int main(){int n,tot=0;
	scanf("%d",&n);
	rep(i,1,n*2){
		scanf("%d",&a[i]);
		if(i<=n)tot+=a[i];else tot-=a[i];
	}
	if(tot){
		rep(i,1,n*2)printf("%d ",a[i]);
		return 0;
	}
	rep(i,1,n)rep(j,n+1,n*2)if(tot-a[i]*2+a[j]*2){
		swap(a[i],a[j]);
		rep(k,1,n*2)printf("%d ",a[k]);
		return 0;
	}
	printf("-1\n");
}