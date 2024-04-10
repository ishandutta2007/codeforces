// luogu-judger-enable-o2
#include<cstdio>
#include<cstring>
#include<algorithm>
const int N=18;
int h[N];
int f[13][N][N];
std::pair<int,int> opt[13][N][N];
inline void chmin(int &a,const int &b){(a>b)&&(a=b);}
void print(int i,int j,int k)
{
	if(i==1) return;
	for(int _=1;_<=k;++_)
	{
		printf("%d ",i);
	}
	print(i-1,opt[i][j][k].first,opt[i][j][k].second);
}
int main()
{
	memset(f,63,sizeof(f));
	int n,a,b;
	scanf("%d %d %d",&n,&a,&b);
	for(int i=1;i<=n;++i) scanf("%d",&h[i]),++h[i];
	f[1][h[1]][0]=0;
	for(int i=2;i<n;++i)
	{
		for(int j=0;j<=h[i];++j)
		{
			for(int k=0;k<=16;++k)
			{
				for(int tmp=0;tmp<=h[i-1];++tmp)
				{
					for(int t=0;t<=16;++t)
					{
						if(j)
						{
							if(k*a+j+t*b==h[i]&&k*b>=tmp)
							{
								chmin(f[i][j][k],f[i-1][tmp][t]+k);
								if(f[i][j][k]==f[i-1][tmp][t]+k)
								{
									opt[i][j][k]=std::make_pair(tmp,t);
								}
							}
						}
						else
						{
							if(k*a+t*b>=h[i]&&k*b>=tmp)
							{
								chmin(f[i][j][k],f[i-1][tmp][t]+k);
								if(f[i][j][k]==f[i-1][tmp][t]+k)
								{
									opt[i][j][k]=std::make_pair(tmp,t);
								}
							}
						}
					}
				}
			}
		}
	}
	int ans=0x3f3f3f3f;
	int pos=0;
	for(int i=0;i<=16;++i)
	{
		if(i*b>=h[n])
		{
			chmin(ans,f[n-1][0][i]);
			if(ans==f[n-1][0][i])
			{
				pos=i;
			}
		}
	}
	printf("%d\n",ans);
	print(n-1,0,pos);
	return 0;
}