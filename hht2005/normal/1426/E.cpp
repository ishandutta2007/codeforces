#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
int main() {
	int n,a1,b1,c1,a2,b2,c2;
	scanf("%d",&n);
	scanf("%d%d%d",&a1,&b1,&c1);
	scanf("%d%d%d",&a2,&b2,&c2);
	printf("%lld %lld\n",0ll+a1-min(a1,c2+a2)+b1-min(b1,a2+b2)+c1-min(c1,b2+c2),0ll+min(a1,b2)+min(b1,c2)+min(c1,a2));
	return 0;
}