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
void sol(){int n,d;
	scanf("%d%d",&n,&d);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,2,n){
		int x=min(d/(i-1),a[i]);
		a[i]-=x;a[1]+=x;d-=x*(i-1);
	}
	printf("%d\n",a[1]);	
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}