#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e5+10;
const int mo=1e9+7;
const ll inf=1e18;
int a[N];
void sol(){int n,k,cnt=1;
	scanf("%d%d",&n,&k);
	rep(i,1,n){
		scanf("%d",&a[i]);
		if(i>1&&a[i]>a[i-1])++cnt;
	}
	if(cnt==1){
		printf("1\n");return;
	}
	if(k==1){
		printf("-1\n");return;
	}
	printf("%d\n",(cnt-2)/(k-1)+1);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}