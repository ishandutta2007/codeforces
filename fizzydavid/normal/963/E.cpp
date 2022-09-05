#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000000007;
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
int qpow(int x,int k){return k==0?1:1ll*(k&1?x:1)*qpow(1ll*x*x%mod,k>>1)%mod;}
int R,a[4];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
vector<pair<int,pair<int,int> > > con[10111];
void adde(int x,int y,int p,int l)
{
//	cerr<<"adde:"<<x<<","<<y<<" "<<p<<" "<<l<<endl;
	con[x].PB(MP(y,MP(p,l)));
}
void erase(int x,int c)
{
	swap(con[x][c],con[x][con[x].size()-1]);
	con[x].resize(con[x].size()-1);
}
int id[111][111],tot;
ll dpp[10111],dpl[10111];
ll mpp[10111],mpl[10111];
bool vis[10111];
int V[2333],vn;
void solve2(int x,int du)
{
	vn=0;
	vis[x]=1;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i].FF;
		if(u!=du)
		{
			mpp[u]+=con[x][i].SS.FF;
			mpl[u]+=con[x][i].SS.SS;
			V[vn++]=u;
		}
		else
		{
			for(int j=0;j<con[du].size();j++)
			{
				int v=con[du][j].FF;
				ll p=1ll*con[x][i].SS.FF*con[du][j].SS.FF%mod;
				mpp[v]+=p;
				mpl[v]+=(1ll*con[x][i].SS.SS*con[du][j].SS.FF+1ll*con[x][i].SS.FF*con[du][j].SS.SS)%mod;
				V[vn++]=v;
			}
		}
	}
	vector<pair<int,pair<int,int> > > ncon;
	for(int i=0;i<vn;i++)
	{
		int u=V[i];
		if(mpp[u]!=0||mpl[u]!=0)
		{
			ncon.PB(MP(u,MP(mpp[u]%mod,mpl[u]%mod)));
			mpp[u]=mpl[u]=0;
		}
	}
	con[x].swap(ncon);
}
void solve(int _x,int _y)
{
	int X=id[_x][_y];
//	cerr<<"solve:"<<_x<<","<<_y<<endl;
//	cerr<<con[X].size()<<endl;
	ll selfp=0,selfl=0;
	for(int i=0;i<con[X].size();i++)
	{
		int u=con[X][i].FF;
		if(u==X)
		{
			selfp+=con[X][i].SS.FF;
			selfl+=con[X][i].SS.SS;
		}
	}
	vector<pair<int,pair<int,int> > > ncon;
	selfp%=mod;selfl%=mod;
//	cerr<<"selfp="<<selfp<<" selfl="<<selfl<<endl;
	assert(selfp!=1);
	ll inv=qpow(1+mod-selfp,mod-2);
	ll c=inv*selfl%mod;
	for(int i=0;i<con[X].size();i++)
	{
		int u=con[X][i].FF;
		if(u!=X)
		{
			ncon.PB(MP(con[X][i].FF,MP(1ll*con[X][i].SS.FF*inv%mod,inv*(con[X][i].SS.SS+c*con[X][i].SS.FF%mod)%mod)));
		}
	}
	con[X]=ncon;
	
	for(int i=0;i<con[X].size();i++)
	{
		int u=con[X][i].FF;
		dpp[u]=(dpp[u]+1ll*con[X][i].SS.FF*dpp[X])%mod;
		dpl[u]=(dpl[u]+1ll*con[X][i].SS.FF*dpl[X]+1ll*dpp[X]*con[X][i].SS.SS%mod)%mod;
	}
	dpp[X]=dpl[X]=0;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<con[X].size();i++)
	{
		if(!vis[con[X][i].FF])solve2(con[X][i].FF,X);
	}
//	for(int i=0;i<=tot;i++)cerr<<dpl[i]<<" ";cerr<<endl;
//	for(int i=0;i<=tot;i++)out(dpl[i]);cerr<<endl;
}
int main()
{
	cin>>R>>a[0]>>a[1]>>a[2]>>a[3];
//	R=50;
//	a[0]=a[1]=a[2]=a[3]=233;
	int sum=a[0]+a[1]+a[2]+a[3];
	for(int i=0;i<4;i++)a[i]=1ll*a[i]*qpow(sum,mod-2)%mod;
	for(int i=0;i<=100;i++)
	{
		for(int j=0;j<=100;j++)
		{
			if((i-50)*(i-50)+(j-50)*(j-50)<=R*R)
			{
				id[i][j]=++tot;
			}
			else continue;
		}
	}
	for(int i=0;i<=100;i++)
	{
		for(int j=0;j<=100;j++)
		{
			if(!id[i][j])continue;
			int cur=id[i][j];
			for(int t=0;t<4;t++)
			{
				int nx=i+dx[t],ny=j+dy[t];
				int nid=nx>=0&&nx<=100&&ny>=0&&ny<=100?id[nx][ny]:0;
				adde(cur,nid,a[t],a[t]);
			}
		}
	}
	dpp[id[50][50]]=1;
	dpl[id[50][50]]=0;

	for(int si=0;si<=200;si++)
	{
		for(int j=0;j<=100;j++)
		{
			int i=si-j;
			if(i>=0&&i<=100&&id[i][j])
			{
				solve(i,j);
			}
		}
	}
	/*
	for(int d=0;d<=R;d++)
	{
//		cerr<<"solve:"<<d<<endl;
		for(int i=0;i<=100;i++)
		{
			for(int j=0;j<=100;j++)
			{
				if(abs(i-50)+abs(j-50)==d)
				{
					solve(i,j);
				}
			}
		}
	}*/
	cout<<(dpl[0]%mod+mod)%mod<<endl;
	return 0;
}