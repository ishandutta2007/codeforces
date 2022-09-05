#include<cstdio>
#include<algorithm>
using namespace std;
int n,X1,Y1,X2,Y2,x,y;
char s[500005];
int main()
{
	scanf("%d",&n);
	scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2);
	y=Y2-Y1;
	x=X2-X1;
	scanf("%s",s);
	if(x==0&&y==0) return !printf("0");
	for(int i=0;i<n;++i){
		if(x>0 && s[i]=='E') x--;
		if(x<0 && s[i]=='W') x++;
		if(y>0 && s[i]=='N') y--;
		if(y<0 && s[i]=='S') y++;
		if(x==0 && y==0) return !printf("%d",i+1);
	}
	printf("-1");
	return 0;
}