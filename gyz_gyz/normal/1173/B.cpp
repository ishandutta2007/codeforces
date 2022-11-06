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
const int mo=998244353;
int main(){int n;
	scanf("%d",&n);
	printf("%d\n",n/2+1);
	rep(i,1,n/2+1)printf("1 %d\n",i);
	rep(i,n/2+2,n)printf("%d %d\n",i-n/2,n/2+1);
}