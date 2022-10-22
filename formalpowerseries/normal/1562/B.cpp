#include<bits/stdc++.h>
using namespace std;
char s[55];
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		int n;
		scanf("%d %s",&n,s+1);
		int flag=0;
		for(int i=1;i<=n;++i)
		{
			if(s[i]=='1' || s[i]=='4' || s[i]=='6' || s[i]=='8' || s[i]=='9')	flag=s[i]-'0';
		}
		if(flag)
		{
			printf("1\n");
			putchar(flag+'0');
			puts("");
			continue;
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=i+1;j<=n;++j)
			{
				if(s[i]=='2' && s[j]=='7')
				{
					puts("2");
					printf("%d\n",27);
					goto ano;
				}
				if(s[i]=='2' && s[j]=='5')
				{
					puts("2");
					printf("%d\n",25);
					goto ano;
				}
				if(s[i]=='2' && s[j]=='2')
				{
					puts("2");
					printf("%d\n",22);
					goto ano;
				}
				if(s[i]=='3' && s[j]=='2')
				{
					puts("2");
					printf("%d\n",32);
					goto ano;
				}
				if(s[i]=='3' && s[j]=='3')
				{
					puts("2");
					printf("%d\n",33);
					goto ano;
				}
				if(s[i]=='3' && s[j]=='5')
				{
					puts("2");
					printf("%d\n",35);
					goto ano;
				}
				if(s[i]=='5' && s[j]=='2')
				{
					puts("2");
					printf("%d\n",52);
					goto ano;
				}
				if(s[i]=='5' && s[j]=='5')
				{
					puts("2");
					printf("%d\n",55);
					goto ano;
				}
				if(s[i]=='5' && s[j]=='7')
				{
					puts("2");
					printf("%d\n",57);
					goto ano;
				}
				if(s[i]=='7' && s[j]=='2')
				{
					puts("2");
					printf("%d\n",72);
					goto ano;
				}
				if(s[i]=='7' && s[j]=='5')
				{
					puts("2");
					printf("%d\n",75);
					goto ano;
				}
				if(s[i]=='7' && s[j]=='7')
				{
					puts("2");
					printf("%d\n",77);
					goto ano;
				}
			}
		}
		ano:;
	}
	return 0;
}