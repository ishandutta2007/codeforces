#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const int mo=1e9+7;
const int inf=1e9;
int a[N];
void sol(){int n,x;
	scanf("%d%d",&n,&x);
	rep(i,1,n)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	rep(i,1,n)if(a[i]==x){
		printf("1\n");return;
	}
	printf("%d\n",max(2,(x-1)/a[n]+1));
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}