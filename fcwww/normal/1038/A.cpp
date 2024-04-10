#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define N 100050
char s[N];
int n,K,c[N];
int main() {
	scanf("%d%d%s",&n,&K,s+1);
	int i;
	for(i=1;i<=n;i++) c[s[i]-'A']++;
	int ans=n;
	for(i=0;i<K;i++) {
		ans=min(ans,c[i]);
	}
	printf("%d\n",ans*K);
}