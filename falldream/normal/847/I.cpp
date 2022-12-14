#include<cstdio>
#define MN 250
char s[MN+5][MN+5];
long long z[MN+5][MN+5];
int qx[MN*MN+5],qy[MN*MN+5],qz[MN+5][MN+5],qn;
const int o[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int main()
{
	int n,m,q,p,i,j,k,l,x,y,ans=0;
	scanf("%d%d%d%d",&n,&m,&q,&p);
	for(i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)if(s[i][j]>='A'&&s[i][j]<='Z')
	{
		qz[qx[qn=1]=i][qy[1]=j]=(s[i][j]-'A'+1)*q;
		for(k=1;k<=qn;++k)
		{
			z[qx[k]][qy[k]]+=qz[qx[k]][qy[k]];
			if(qz[qx[k]][qy[k]]>>1)for(l=0;l<4;++l)
			{
				x=qx[k]+o[l][0];y=qy[k]+o[l][1];
				if(!qz[x][y]&&((s[x][y]>='A'&&s[x][y]<='Z')||s[x][y]=='.'))
					qx[++qn]=x,qy[qn]=y,qz[x][y]=qz[qx[k]][qy[k]]>>1;
			}
		}
		for(k=1;k<=qn;++k)qz[qx[k]][qy[k]]=0;
	}
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)if(z[i][j]>p)++ans;
	printf("%d",ans);
}