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
int a[N],n,K,s[N],f[N];
int main() {
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++) {
		scanf("%d%s",&a[i],w+1);
		for(j=1;w[j];j++) {
			s[i]|=(1<<(w[j]-'A'));
		}
	}
	memset(f,0x3f,sizeof(f)); f[0]=0;
	int mask=(1<<3)-1;
	for(i=0;i<=mask;i++) {
		for(j=1;j<=n;j++) {
			f[i|s[j]]=min(f[i|s[j]],f[i]+a[j]);
		}
	}
	if(f[mask]==0x3f3f3f3f) puts("-1");
	else printf("%d\n",f[mask]);
}