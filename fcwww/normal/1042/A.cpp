#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <vector>
#include <set>
#include <string>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uit;
typedef double f2;
typedef long double f3;
#define N 100050
#define rep(n) for(i=1;i<=n;i++)
char w[N];
int a[N],n,K;
int check(int mid) {
	int i,re=0;
	for(i=1;i<=n;i++) {
		if(a[i]>mid) return 0;
		re+=mid-a[i];
	}
	return re>=K;
}
int main() {
	int mx=0,i;
	scanf("%d%d",&n,&K);
	for(i=1;i<=n;i++) scanf("%d",&a[i]),mx=max(mx,a[i]);
	int ans1=0,ans2=mx+K;
	for(i=0;i<=mx+K;i++) {
		if(check(i)) return printf("%d %d\n",i,ans2),0;
	}
}