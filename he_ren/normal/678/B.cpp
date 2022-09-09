#include<cstdio>

inline bool leap(int y)
{
	return y%400==0 || (y%4==0 && y%100!=0);
}

int main(void)
{
	int y;
	scanf("%d",&y);
	
	int ans=y+1,d=0;
	for(int nd=0; ; ++ans)
	{
		nd=(nd+365+leap(ans))%7;
		if(leap(ans)!=leap(y)) continue;
		
		if(nd==d)
		{
			printf("%d",ans);
			return 0;
		}
	}
	return 0;
}