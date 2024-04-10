#include<cstdio>

int main(void)
{
	int a,b,ta,tb;
	scanf("%d%d",&a,&ta);
	scanf("%d%d",&b,&tb);
	
	int h,m;
	scanf("%d:%d",&h,&m);
	int s=(h-5)*60+m, t=s+ta;
	
	int cnt=0,now=0;
	while(1)
	{
		if(now>=t || now/60>=19) break;
		int to=now+tb;
		if(to<=s || now>=t); else ++cnt;
		now+=b;
	}
	printf("%d",cnt);
	return 0;
}