#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,c[30];
char s[N];
void sol()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=0;i<26;i++)
		c[i]=0;
	int f1=1;
	for(int i=1;i<=n;i++)
		if(s[i]!=s[1])
			f1=0;
	if(f1==1)
	{
		for(int i=1;i<=n;i++)
			printf("%c",s[i]);
		puts("");
		return;
	}
	for(int i=1;i<=n;i++)
		c[s[i]-'a']++;
	for(int x=0;x<26;x++)
	{
		if(c[x]==1)
		{
			printf("%c",'a'+x);
			for(int i=0;i<26;i++)
				if(i!=x)
					for(int j=0;j<c[i];j++)
						printf("%c",'a'+i);
			puts("");
			return;
		}
	}
	for(int x=0;x<26;x++)
	{
		if(c[x])
		{
			int o=0;
			for(int i=0;i<26;i++)
				if(x!=i)
					o+=c[i];
			if(c[x]-2<=o)
			{
				int y=x+1;
				printf("%c%c",'a'+x,'a'+x);
				for(int i=1;i<=c[x]-2;i++)
				{
					while(!c[y])
						y++;
					printf("%c%c",'a'+y,'a'+x);
					c[y]--;
				}
				while(1)
				{
					while(y<26&&!c[y])
						y++;
					if(y==26)
						break;
					printf("%c",'a'+y);
					c[y]--;
				}
			}	
			else
			{
				int y=x+1;
				while(!c[y])
					y++;
				int z=y+1;
				while(z<26&&!c[z])
					z++;
				if(z==26)
				{
					printf("%c%c",'a'+x,'a'+y);
					for(int i=1;i<c[y];i++)
						printf("%c",'a'+y);
					for(int i=1;i<c[x];i++)
						printf("%c",'a'+x);
				}
				else
				{
					printf("%c%c",'a'+x,'a'+y);
					for(int i=1;i<c[x];i++)
						printf("%c",'a'+x);
					printf("%c",'a'+z);
					c[y]--,c[z]--;
					while(1)
					{
						while(y<26&&!c[y])
							y++;
						if(y==26)
							break;
						printf("%c",'a'+y);
						c[y]--;
					}
				}
			}
			puts("");
			return;
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}