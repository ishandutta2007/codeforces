#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;
const int mo=998244353;
const ll inf=1e18;
int a[N];
bool cmp1(int x,int y){
	if(!x)return 0;
	if(!y)return 1;
	return x<y;
}
bool cmp2(int x,int y){
	if(!x)return 0;
	if(!y)return 1;
	return x>y;
}
void sol(){int n,tot=0;
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);tot+=a[i];
	}
	if(!tot){
		printf("NO\n");return;
	}
	sort(a+1,a+n+1,tot<0?cmp1:cmp2);
	printf("YES\n");
	rep(i,1,n)printf("%d%c",a[i],i==n?'\n':' ');
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}