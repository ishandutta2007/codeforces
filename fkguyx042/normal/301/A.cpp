#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a,b,c,d,n,m,k,i;
int mas[202];
int main() {
	scanf("%d",&n);
	c=0; a=0;b=(int)1e9;
   for (i=1;i<2*n;i++) {
		scanf("%d",&mas[i]);
		c+=abs(mas[i]);
		if (mas[i]<0) ++a;
		b=min(b,abs(mas[i]));
	}
	if (a>=n) a-=n;
	if (n%2==1||a%2==0) printf("%d\n",c); else printf("%d\n",c-2*b);
}