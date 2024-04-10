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
int n;
int f[5005][2505][3];
/*
0ii-1 
1i-1 
2i 
*/
int a[1000005];
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	memset(f,0x3f,sizeof(f));
	f[1][1][2]=0;
	f[1][0][0]=0;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			f[i][j][0]=min(f[i-1][j][0],f[i-1][j][1]);
			f[i][j][1]=f[i-1][j][2]+max(0,a[i]-a[i-1]+1);
			if(j)f[i][j][2]=min(f[i-1][j-1][1]+max(0,min(a[i-2]-1,a[i-1])-a[i]+1),f[i-1][j-1][0]+max(0,a[i-1]-a[i]+1));
//			cout<<i<<' '<<j<<" "<<f[i][j][0]<<" "<<f[i][j][1]<<" "<<f[i][j][2]<<endl;
		}
	}
	for(int i=1;i<=(n+1)/2;i++)
	{
		cout<<min(f[n][i][0],min(f[n][i][1],f[n][i][2]))<<" ";
	}
	return 0;
}