#include<cstdio>

int main(void)
{
	char a;
	int b;
	scanf("%c%d",&a,&b);
	a=a-'a'+1;
	
	int ans=0;
	for(int i=-1; i<=1; ++i)
		for(int j=-1; j<=1; ++j)
		{
			if(a+i>=1 && a+i<=8 && b+j>=1 && b+j<=8)
				++ans;
		}
	
	printf("%d",ans-1);
	return 0;
}