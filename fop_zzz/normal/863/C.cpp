#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<algorithm>
#define For(i,j,k) for(ll i=j;i<=k;++i)
#define Dow(i,j,k) for(ll i=k;i>=j;--i)
#define ll long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c<='9'&&c>='0')	t=t*10LL+c-48LL,c=getchar();
	return t*f;
}
inline ll win(ll x,ll y)
{
	if(x==2&&y==1)	return 1;
	if(x==3&&y==2)	return 1;
	if(x==1&&y==3)	return 1;
	return 0;
}
ll ans1,ans2,del1,del2;
ll n,x,y,a[5][5],b[5][5];
ll rx[201],ry[201],tot,tep=1;
int main()
{
	n=read();x=read();y=read();
	For(i,1,3)	For(j,1,3)	a[i][j]=read();
	For(i,1,3)	For(j,1,3)	b[i][j]=read();
	ll nx=x,ny=y;
	rx[++tot]=nx,ry[tot]=ny;n--;ans1+=win(nx,ny);ans2+=win(ny,nx);
	ll tmp=nx;nx=a[nx][ny];ny=b[tmp][ny];
	bool flag=0;
	while(n&&(nx!=x||ny!=y))
	{
		ans1+=win(nx,ny);ans2+=win(ny,nx);
		rx[++tot]=nx;ry[tot]=ny;n--;
		ll tmp=nx;
		nx=a[nx][ny];ny=b[tmp][ny];
		For(i,1,tot-1)	
		{
			if(nx==rx[i]&&ny==ry[i])	
			{
				tep=i;flag=1;
				x=rx[i];y=ry[i];
				break;
			}
		}
		if(flag)	break;
	}
	For(i,tep,tot)	del1+=win(rx[i],ry[i]),del2+=win(ry[i],rx[i]);
	tot=tot-tep+1;
	ll round=(n/(tot));
	ans1+=del1*round;ans2+=del2*round;
	ll last=n-round*tot;
	nx=x;ny=y;

	For(i,1,last)
	{
		ans1+=win(nx,ny);ans2+=win(ny,nx);
		int tmp=nx;nx=a[nx][ny];ny=b[tmp][ny];	
	}
	cout<<ans1<<' '<<ans2<<endl;
}