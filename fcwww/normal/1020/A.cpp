#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long ll;
int n,a,b,m;
int Abs(int x) {
	return x>0?x:-x;
}
int main() {
	int K,ta,fa,tb,fb;
	scanf("%d%d%d%d%d",&n,&m,&a,&b,&K);
	while(K--) {
		int ans=0,nf;
		scanf("%d%d%d%d",&ta,&fa,&tb,&fb);
		if(ta==tb) {
			printf("%d\n",Abs(fa-fb)); continue;
		}
		if(fa<a) {
			ans=a-fa+Abs(ta-tb); nf=a;
		}else if(fa>b) {
			ans=fa-b+Abs(ta-tb); nf=b;
		}else {
			ans=Abs(ta-tb); nf=fa;
		}
		ans+=Abs(nf-fb);
		printf("%d\n",ans);
	}
}