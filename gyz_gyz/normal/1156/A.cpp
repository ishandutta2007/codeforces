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
int a[N];
int main(){int n,ans=0;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,2,n)if(a[i]+a[i-1]==5)return printf("Infinite\n"),0;
	printf("Finite\n");
	rep(i,2,n)if(a[i-1]==1)ans+=a[i]+1;else ans+=a[i-1]+1;
	rep(i,3,n)if(a[i]==2&&a[i-1]==1&&a[i-2]==3)--ans;
	printf("%d\n",ans);
}