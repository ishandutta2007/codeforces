#include<cstdio>

using namespace std;

int x1,y1,z1,x2,y2,z2;

int main()
{
	scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
	if(x1!=x2&&y1!=y2&&z1!=z2)
		printf("NO");
	else
		printf("YES");
}