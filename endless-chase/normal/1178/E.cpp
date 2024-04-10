#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
char s[1111111];
int n,l,r,len;
bool f[1111111];
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for (int i=0;i<3;i++)
	{
		memset(f,0,sizeof(f));
		len=0;l=r=-1;
		for (int j=0;j<n;j++)
		{
			if (s[j]-'a'==i) 
			{
				l=j;
				break;
			}
		}
		for (int j=n-1;j>=0;j--)
		{
			if (s[j]-'a'==i)
			{
				r=j;
				break;
			}
		}
		if (!~l || !~r) continue;
		if (l==r) len=1;
		else len=2;
		f[l]=f[r]=1;
		while(l<r-1)
		{
			if (l+2==r)
			{
				len++;
				f[l+1]=1;
				break;
			}
			if (s[l+1]==s[r-1])
			{
				l++;r--;
				f[l]=f[r]=1;
				len+=2;
			}
			else
			{
				if (l+3==r)
				{
					len++;
					f[l+1]=2;
					break;
				}
				else if (l+4==r)
				{
					if (s[l+2]==s[r-1])
					{
						f[l+2]=f[r-1]=1;
						len+=2;
						break;
					}
					if (s[l+1]==s[r-2])
					{
						f[l+1]=f[r-2]=1;
						len+=2;
						break;
					}
					len++;
					f[l+2]=1;
					break;
				}
				else
				{
					if (s[l+1]==s[r-2])
					{
						len+=2;
						f[l+1]=f[r-2]=1;
						l++;r-=2;
					}
					else if (s[l+2]==s[r-1])
					{
						len+=2;
						f[l+2]=f[r-1]=1;
						l+=2;r--;
					}
					else
					{
						len+=2;
						f[l+2]=f[r-2]=1;
						l+=2;r-=2;
					}
				}
			}
		}
		if (len>=n/2)
		{
			for (int j=0;j<n;j++)
			{
				if (f[j]) printf("%c",s[j]);
			}
			printf("\n");
			return 0;
		}
	}
	printf("IMPOSSIBLE\n");
	return Accepted;
}