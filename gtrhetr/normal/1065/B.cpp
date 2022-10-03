#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
  ll n,m;
  scanf("%I64d%I64d",&n,&m);
  for(int i=0;i<=n;i++)
  	if (((n-i+1)>>1)<=m) {
  		printf("%d ",i);
  		break;
	  }
  for(int i=n;i>=0;i--)
    if (((n-i)*(n-i-1)>>1)>=m) {
    	printf("%d\n",i);
    	break;
	}
  return 0;
}