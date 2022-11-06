#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
bool visx[105],visy[105];
int mp[105][105],n,m;
int v1[105],v2[105],num1,num2;
char s[105];
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
		{
			if(s[j]=='#') mp[i][j]=1;
			else mp[i][j]=0;
			//cout<<mp[i][j]<<" ";
		}
		//cout<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j])
			{
				num1=0;num2=0;
				if(visx[i]||visy[j])
				{
					puts("NO");
					//cout<<"ok";
					return 0;
				}
			
				for(int k=1;k<=m;k++)
				{
					if(mp[i][k])
					{
						if(visy[k])
						{
							puts("NO");
							//cout<<"ok";
							return 0;
						}v2[++num2]=k;
					}
					
				}
				//cout<<num1<<" "<<num2<<endl;
				for(int k=1;k<=n;k++)
				{
					if(mp[k][j])
					{
						if(visx[k])
						{
							puts("NO");
							//cout<<"ok";
							return 0;
						}v1[++num1]=k;
					}
					
				}
				for(int k=1;k<=num1;k++)
				{
					for(int l=1;l<=num2;l++)
					{
						if(!mp[v1[k]][v2[l]])
						{
							puts("NO");
							//cout<<i<<" "<<j<<" "<<v1[k]<<" "<<v2[l]<<endl;
							return 0;
						}
						mp[v1[k]][v2[l]]=0;
					}
				}
				for(int k=1;k<=num1;k++) visx[v1[k]]=1;
				for(int k=1;k<=num2;k++) visy[v2[k]]=1; 
			}
		}
	}
	puts("YES");
}