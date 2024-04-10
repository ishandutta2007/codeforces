#include<bits/stdc++.h>
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
int n,p,m;
int q1,q2;
int f[2][1005][51][51];
/*
1ijlr lr  

2ijlr lr 
*/
int t1[10005];
int t2[10005];
int main(){
	n=read();p=read();m=read();
	q1=read();
	for(int i=1;i<=q1;i++)t1[read()]=1;
	q2=read();
	for(int i=1;i<=q2;i++)t2[read()]=1;
	if(p*m>2*n)
	{
		int res=0;
		for(int i=1;i<=n;i++)res+=(t1[i]|t2[i]);
		cout<<res<<"\n";
		return 0;
	}
	int ans=0;
	memset(f,-0x3f,sizeof(f));
	f[0][0][0][0]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=p;j++)
			for(int l=0;l<=m;l++)
				for(int r=0;r<=m;r++)f[(i+1)&1][j][l][r]=-2147483647;
		for(int j=0;j<=p;j++)
		{
			for(int l=0;l<=m;l++)
			{
				for(int r=0;r<=m;r++)
				{
					if(f[i&1][j][l][r]<-900000000)continue;
					f[(i+1)&1][j][max(l-1,0)][max(r-1,0)]=max(f[(i+1)&1][j][max(l-1,0)][max(r-1,0)],f[i&1][j][l][r]);// 
					if(l)f[(i+1)&1][j][l-1][max(r-1,0)]=max(f[(i+1)&1][j][l-1][max(r-1,0)],f[i&1][j][l][r]+t1[i+1]);
					if(r)f[(i+1)&1][j][max(l-1,0)][r-1]=max(f[(i+1)&1][j][max(l-1,0)][r-1],f[i&1][j][l][r]+t2[i+1]);
					if(l&&r)f[(i+1)&1][j][l-1][r-1]=max(f[(i+1)&1][j][l-1][r-1],f[i&1][j][l][r]+(t1[i+1]|t2[i+1]));
					f[(i+1)&1][j+1][m-1][max(r-1,0)]=max(f[(i+1)&1][j+1][m-1][max(r-1,0)],f[i&1][j][l][r]+t1[i+1]);
					f[(i+1)&1][j+1][max(l-1,0)][m-1]=max(f[(i+1)&1][j+1][max(l-1,0)][m-1],f[i&1][j][l][r]+t2[i+1]);
					if(r)f[(i+1)&1][j+1][m-1][r-1]=max(f[(i+1)&1][j+1][m-1][r-1],f[i&1][j][l][r]+(t1[i+1]|t2[i+1]));
					if(l)f[(i+1)&1][j+1][l-1][m-1]=max(f[(i+1)&1][j+1][l-1][m-1],f[i&1][j][l][r]+(t1[i+1]|t2[i+1]));
					f[(i+1)&1][j+2][m-1][m-1]=max(f[(i+1)&1][j+2][m-1][m-1],f[i&1][j][l][r]+(t1[i+1]|t2[i+1]));
//					int to1=l+t1[i+1],to2=r+t2[i+1];
//					cout<<i<<" "<<j<<" "<<l<<" "<<r<<" "<<f[i&1][j][l][r]<<" "<<(t3[i+1]-((i+1-m)>=0?t3[i+1-m]:0))<<' '<<to1<<" "<<to2<<"\n";
//					f[(i+1)&1][j][to1][to2]=max(f[(i+1)&1][j][to1][to2],f[i&1][j][l][r]);//i+1 
//					f[(i+1)&1][j+1][0][to2-(t3[i+1]-((i+1-m)>=0?t3[i+1-m]:0))]=max(f[(i+1)&1][j+1][0][to2-(t3[i+1]-((i+1-m)>=0?t3[i+1-m]:0))],f[i&1][j][l][r]+to1);
//					f[(i+1)&1][j+1][to1-(t3[i+1]-((i+1-m)>=0?t3[i+1-m]:0))][0]=max(f[(i+1)&1][j+1][to1-(t3[i+1]-((i+1-m)>=0?t3[i+1-m]:0))][0],f[i&1][j][l][r]+to2);
//					f[(i+1)&1][j+2][0][0]=max(f[(i+1)&1][j+2][0][0],f[i&1][j][l][r]+to2+to1-(t3[i+1]-((i+1-m)>=0?t3[i+1-m]:0)));
				}
			}
		}
	}
	for(int l=0;l<=m;l++)
	{
		for(int r=0;r<=m;r++)
		{
			ans=max(ans,f[n&1][p][l][r]);
		}
	}
	cout<<ans<<endl;
	return 0;
}