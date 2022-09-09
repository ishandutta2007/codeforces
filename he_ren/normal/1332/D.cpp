#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int inf = 0x3ffff;

int mxPos(int x)
{
	int res=1;
	while(res<=x) res<<=1;
	return res;
}

int main(void)
{
	int k;
	scanf("%d",&k);
	
	printf("%d %d\n",2,3);
	printf("%d %d %d\n",inf,k,0);
	printf("%d %d %d\n",mxPos(k),inf,k);
	return 0;
}