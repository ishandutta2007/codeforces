#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	 int n,v1,v2;
	scanf("%d%d%d",&n,&v1,&v2);
	printf("%.5lf\n",1.*n*v1/(v1+v2));
}