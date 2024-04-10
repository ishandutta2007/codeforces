#include<iostream>
#include<cstdio>
#include<cstring>
#include<bitset>
using namespace std;
const int N=410;
typedef bitset<N> B;
B can[N],a[26][N];
int n,m;
char str[N];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",str);
		for(int j=0;j<m;j++)
		{
			for(int l='a';l<='z';l++)
			if(str[j]!=l) a[l-'a'][i].set(j);
			can[i][j]=0;
		}
	}
	int n1,m1;
	scanf("%d%d",&n1,&m1);
//	for(int l=0;l<26;l++)
//		for(int i=0;i<n;i++)
//			for(int j=0;j<m;j++) a[l][i][j]=!a[l][i][j];
	for(int i=0;i<n1;i++)
	{
		scanf("%s",str);
		for(int j=0;j<m1;j++)
		if(str[j]!='?')
		{
			int c=str[j]-'a';
			for(int k=0;k<n;k++)
			{
				int k1=(k-i+n)%n,j1=j%m;
				can[k1]|=a[c][k]>>j1;
				can[k1]|=a[c][k]<<m-j1;
			}
		}
	}
	for(int i=0;i<n;i++,puts(""))
		for(int j=0;j<m;j++) printf("%d",!can[i].test(j));
	return 0;
}