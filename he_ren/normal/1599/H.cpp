#include<bits/stdc++.h>
using namespace std;
const int inf=1000000000;
int ask(int x,int y)
{
	printf("? %d %d\n",x,y);
	fflush(stdout);
	int v;
	scanf("%d",&v);
	return v;
}
int main()
{
	int v1=ask(1,1),v2=ask(inf,1),v3=ask(inf,inf),v4=ask(1,inf);
	int p1=(v1+inf-v4)/2,p2=(v1+inf-v2)/2,p3=(v2+inf-v3)/2,p4=(v4+inf-v3)/2;
	int xl=ask(1,p1)+1,xr=inf-ask(inf,p3),yl=ask(p2,1)+1,yr=inf-ask(p4,inf);
	printf("! %d %d %d %d\n",xl,yl,xr,yr);
	fflush(stdout);
	return 0;
}