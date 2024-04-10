#include<map>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define LL long long
using namespace std;
map<LL,int> p;
int n,l,r;
char s[70001][15];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s[i]);
		for(int j=0;j<9;++j)
			for(int k=1,tmp=0;k+j<=9;++k)
			{
				tmp=tmp*11+s[i][j+k-1]-47;
				if(p[tmp] != i)
				{
					if(!p[tmp])p[tmp]=i;
					else p[tmp]=-1;
				}
			}
	}
	for(int i=1;i<=n;++i)
	{
		bool find=0;
		for(int k=1,tmp[15]={};k<=n && !find;++k)
			for(int j=0;j+k<=9 && !find;++j)
			{
				tmp[j]=tmp[j]*11+s[i][j+k-1]-47;
				if(!p[tmp[j]] || p[tmp[j]]==i)
				{
					l=j,r=j+k;
					find=1;
				}
			}
		for(int j=l;j<r;++j)
			printf("%c",s[i][j]);
		puts("");
	}
}