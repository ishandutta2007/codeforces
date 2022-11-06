#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e6+10;
const int mo=1e9+7;
int a[N],v[3];
void sol(){int n;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,0,2)v[i]=0;
	rep(i,1,n)++v[a[i]%3];
	int s1=min(v[1],v[2]);
	int s2=(max(v[1],v[2])-s1)/3;
	printf("%d\n",v[0]+s1+s2);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}