#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 0x3f3f3f3f

using namespace std;

int cnt[200005];

int main() {
  int n,k;
  scanf("%d%d",&n,&k);
  int minn=inf,maxn=0;
  for(int i=1;i<=n;i++) {
  	int x;
  	scanf("%d",&x);
  	cnt[x]++;
  	maxn=max(maxn,x);
  	minn=min(minn,x);
  }
  int ans=0,s=0;
  for(int i=maxn;i>minn;i--) {
  	cnt[i]+=cnt[i+1];
  	if (s+cnt[i]>k) {
  		ans++;
  		s=0;
	  }
	s+=cnt[i];
  }
  if (s) ans++;
  printf("%d\n",ans);
  return 0;
}