#include <cstdio>
#include <cstdlib>
using namespace std;
int main(){
	int x1,y1,x2,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	if (x1==x2)
		printf("%d",abs(y1-y2)*2+6);
	else if (y1==y2)
		printf("%d",abs(x1-x2)*2+6);
	else printf("%d",(abs(x1-x2)+abs(y1-y2))*2+4);
}