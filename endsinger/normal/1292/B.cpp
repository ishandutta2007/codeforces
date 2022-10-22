#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=60,INF=3e16;
vector<int>x,y,dis;
main()
{
	int x0,y0,ax,ay,bx,by,xs,ys,t;
	cin>>x0>>y0>>ax>>ay>>bx>>by>>xs>>ys>>t;
	while(x0<=INF&&y0<=INF)
	{
		x.push_back(x0);
		y.push_back(y0);
		x0=x0*ax+bx;
		y0=y0*ay+by;
	}
	int m=x.size();
	dis.resize(m);
	for(int i=1;i<m;i++)
		dis[i]=x[i]-x[i-1]+y[i]-y[i-1];
	int ans=0;
	for(int i=0;i<m;i++)
	{
		int s1=1,s2=1;
		int k=abs(x[i]-xs)+abs(y[i]-ys);
		int r=t-k,j=i;
		if(r<0)
			continue;
		while(1)
		{
			if(j+1==m||r<dis[j+1])
				break;
			s1++;
			r-=dis[j+1];
			j++;
		}
		ans=max(ans,s1);
		r=t-k,j=i;
		while(1)
		{
			if(j==0||r<dis[j])
				break;
			s2++;
			r-=dis[j];
			j--;
		}
		ans=max(ans,s2);
	}
	cout<<ans<<endl;
	return 0;
}