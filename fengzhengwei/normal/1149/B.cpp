#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,m;
const int xx=1e5+5;
char s[xx],a[xx],b[xx],c[xx];
int to[xx][26],f[251][251][251],tot1,tot2,tot3;
int main(){
	n=read();
	m=read();
	scanf("%s",s+1);
	for(int j=0;j<26;j++)to[n][j]=1e5+1;
	for(int i=n-1;i>=0;i--)
	{
		memcpy(to[i],to[i+1],sizeof(to[i+1]));
		to[i][s[i+1]-'a']=i+1;
	}
//	cout<<to[0][0]<<"\n";
	for(int i=0;i<=250;i++)
		for(int j=0;j<=250;j++)
			for(int k=0;k<=250;k++)f[i][j][k]=1e5+1;
	f[0][0][0]=0;
	while(m--)
	{
		char C;
		while((C=getchar())!='+'&&C!='-');
		if(C=='+')
		{
			int o=read();
			char w;while((w=getchar())>'z'&&w<'a');
			if(o==1)
			{
				a[++tot1]=w;
				for(int i=tot1-1;i<=tot1;i++)
				{
					for(int j=0;j<=tot2;j++)
					{
						for(int k=0;k<=tot3;k++)
						{
							if(f[i][j][k]==1e5+1)continue;
							if(i!=tot1)f[i+1][j][k]=min(f[i+1][j][k],to[f[i][j][k]][a[i+1]-'a']);//i=tot1 
							else 
							{
								if(j!=tot2)f[i][j+1][k]=min(f[i][j+1][k],to[f[i][j][k]][b[j+1]-'a']);
								if(k!=tot3)f[i][j][k+1]=min(f[i][j][k+1],to[f[i][j][k]][c[k+1]-'a']);
							}
						}
					}
				}
			}
			if(o==2)
			{
				b[++tot2]=w;
				for(int i=0;i<=tot1;i++)
				{
					for(int j=tot2-1;j<=tot2;j++)
					{
						for(int k=0;k<=tot3;k++)
						{
							if(f[i][j][k]==1e5+1)continue;
							if(j!=tot2)f[i][j+1][k]=min(f[i][j+1][k],to[f[i][j][k]][b[j+1]-'a']);
							else 
							{
								if(i!=tot1)f[i+1][j][k]=min(f[i+1][j][k],to[f[i][j][k]][a[i+1]-'a']);
								if(k!=tot3)f[i][j][k+1]=min(f[i][j][k+1],to[f[i][j][k]][c[k+1]-'a']);
							}
						}
					}
				}
			}
			if(o==3)
			{
				c[++tot3]=w;
				for(int i=0;i<=tot1;i++)
				{
					for(int j=0;j<=tot2;j++)
					{
						for(int k=tot3-1;k<=tot3;k++)
						{
							if(f[i][j][k]==1e5+1)continue;
							if(k!=tot3)f[i][j][k+1]=min(f[i][j][k+1],to[f[i][j][k]][c[k+1]-'a']);
							else 
							{
								if(i!=tot1)f[i+1][j][k]=min(f[i+1][j][k],to[f[i][j][k]][a[i+1]-'a']);
								if(j!=tot2)f[i][j+1][k]=min(f[i][j+1][k],to[f[i][j][k]][b[j+1]-'a']);
							}
						}
					}
				}
			}
		}
		else 
		{
			int o=read();
			if(o==1)
			{
				for(int i=tot1;i<=tot1;i++)
					for(int j=0;j<=tot2;j++)
						for(int k=0;k<=tot3;k++)
							f[i][j][k]=1e5+1;
				tot1--;
			}
			if(o==2)
			{
				for(int i=0;i<=tot1;i++)
					for(int j=tot2;j<=tot2;j++)
						for(int k=0;k<=tot3;k++)
							f[i][j][k]=1e5+1;
				tot2--;
			}
			if(o==3)
			{
				for(int i=0;i<=tot1;i++)
					for(int j=0;j<=tot2;j++)
						for(int k=tot3;k<=tot3;k++)
							f[i][j][k]=1e5+1;
				tot3--;
			}
		}
		if(f[tot1][tot2][tot3]!=1e5+1)puts("YES");
		else puts("NO");
	}
	return 0;
}