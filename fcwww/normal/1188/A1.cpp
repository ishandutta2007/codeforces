#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <bitset>
#include <vector>
using namespace std;
typedef long long ll;
#define N 100050
int n,m,du[N];
int main() {
	scanf("%d",&n);
	int i,x,y;
	for(i=1;i<n;i++) scanf("%d%d",&x,&y),du[x]++,du[y]++;
	for(i=1;i<=n;i++) if(du[i]==2) return puts("NO"),0;
	puts("YES");
}