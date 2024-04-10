#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int mo=998244353;
double a[N];
int main(){int n;
	scanf("%d",&n);a[1]=1;
	rep(i,2,n)a[i]=a[i-1]+1./i;
	printf("%.12lf\n",a[n]);
}