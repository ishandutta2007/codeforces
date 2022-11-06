#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int inf=1e9;
const int mo=1e9+7;
int a[N];
bool cmp(int x,int y){return x>y;}
void sol(){int n;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	rep(i,1,n)printf("%d%c",a[i],i==n?'\n':' ');
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}