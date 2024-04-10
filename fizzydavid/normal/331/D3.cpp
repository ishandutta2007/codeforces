//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
const int Imx=2147483647;
const int mod=1000000007;
const ll Lbig=2e18;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
const int dx[4]={0,0,-1,1};
const int dy[4]={-1,1,0,0};
struct SGT
{
	int a[400111],n;
	#define ls p<<1
	#define rs p<<1|1
	void Build(int N){n=N;memset(a,0,sizeof(a));}
	void pushdown(int p)
	{
		if(a[p])
		{
			a[ls]=a[rs]=a[p];
			a[p]=0;
		}
	}
	int x,y,v;
	void modify(int l,int r,int p)
	{
		if(x<=l&&r<=y)
		{
			a[p]=v;
			return;
		}
		pushdown(p);
		int m=l+r>>1;
		if(x<=m)modify(l,m,ls);
		if(m<y)modify(m+1,r,rs);
	}
	void Modify(int X,int Y,int V)
	{
//		cout<<"Modify:"<<X<<" "<<Y<<" "<<V<<endl;
		x=X;y=Y;v=V;
		modify(0,n,1);
	}
	int query(int l,int r,int p)
	{
		if(l==x&&r==x)return a[p];
		pushdown(p);
		int m=l+r>>1;
		if(x<=m)return query(l,m,ls);
		else return query(m+1,r,rs);
	}
	int Query(int X)
	{
//		cout<<"Query:"<<X<<endl;
		x=X;
		return query(0,n,1);
	}
}sgt;
ll lim;
int n,ax[100111],ay[100111],bx[100111],by[100111];
struct data
{
	bool type;
	int x,y,id;
	data(bool Type=0,int X=0,int Y=0,int Id=0){if(X>Y)swap(X,Y);type=Type;x=X;y=Y;id=Id;}
};
int tot;
map<pair<int,int>,int> mid;
vector<pair<int,int> > vx[100111],vy[100111];
int px[500111],py[500111];
int getid(int x,int y,bool f=1)
{
	if(!f)
	{
		px[++tot]=x;
		py[tot]=y;
		return tot;
	}
	int &p=mid[MP(x,y)];
	if(p==0)
	{
		p=++tot;
		px[p]=x,py[p]=y;
		vx[y].PB(MP(x,p));
		vy[x].PB(MP(y,p));
	}
	return p;
}
vector<data> vu[100111],vd[100111],vl[100111],vr[100111];
int dir[400111],ans[400111],nxt0[400111];
ll qt[100111];
ll nxt[55][400111],nxtd[55][400111];
void addpt(int x,int y,int d,int i)
{
	if(d==0)vd[y].PB(data{1,x,x,i});
	if(d==1)vu[y].PB(data{1,x,x,i});
	if(d==2)vl[x].PB(data{1,y,y,i});
	if(d==3)vr[x].PB(data{1,y,y,i});
}
void solve(vector<data> v[])
{
	sgt.Build(lim);
	for(int i=0;i<=lim;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			if(v[i][j].type==1&&v[i][j].id<=n)ans[v[i][j].id]=sgt.Query(v[i][j].x);
		}
		for(int j=0;j<v[i].size();j++)
		{
			if(v[i][j].type==0&&v[i][j].id==0)sgt.Modify(v[i][j].x,v[i][j].y,v[i][j].id);
		}
		for(int j=0;j<v[i].size();j++)
		{
			if(v[i][j].type==0&&v[i][j].id)sgt.Modify(v[i][j].x,v[i][j].y,v[i][j].id);
		}
		for(int j=0;j<v[i].size();j++)
		{
			if(v[i][j].type==1&&v[i][j].id>n)ans[v[i][j].id]=sgt.Query(v[i][j].x);
		}
	}
}
int main()
{
	getii(n,lim);
	for(int i=1;i<=n;i++)
	{
		getii(ax[i],ay[i]);
		getii(bx[i],by[i]);
		getid(bx[i],by[i]);
		int mxy=max(ay[i],by[i]),mny=min(ay[i],by[i]),mxx=max(ax[i],bx[i]),mnx=min(ax[i],bx[i]);
		vu[mxy].PB(data{0,ax[i],bx[i],i});
		vd[mny].PB(data{0,ax[i],bx[i],i});
		vr[mxx].PB(data{0,ay[i],by[i],i});
		vl[mnx].PB(data{0,ay[i],by[i],i});
		if(ax[i]==bx[i])dir[i]=ay[i]<by[i];
		else dir[i]=2+(ax[i]<bx[i]);
		addpt(bx[i],by[i],dir[i],i);
	}
	int q;
	geti(q);
	for(int i=1;i<=q;i++)
	{
		int x,y;
		ll T;
		getii(x,y);
		char c=mygetchar();
		geti(T);
		qt[i]=T;
		getid(x,y,0);
		if(c=='D')dir[n+i]=0;
		if(c=='U')dir[n+i]=1;
		if(c=='L')dir[n+i]=2;
		if(c=='R')dir[n+i]=3;
		addpt(x,y,dir[n+i],n+i);
	}
	reverse(vu,vu+lim+1);
	reverse(vr,vr+lim+1);
	solve(vu);
	solve(vd);
	solve(vl);
	solve(vr);
	int ttot=tot;
	for(int i=1;i<=n+q;i++)
	{
		int t=ans[i],x=px[i],y=py[i];
//		cout<<x<<" "<<y<<" "<<dir[i]<<" ans["<<i<<"]="<<t<<endl;
		if(t)
		{
			int dis;
			if(dir[i]<2)dis=min(abs(ay[t]-y),abs(by[t]-y));
			else dis=min(abs(ax[t]-x),abs(bx[t]-x));
			int nx=x+dx[dir[i]]*dis,ny=y+dy[dir[i]]*dis;
			if((dir[i]^dir[t])==1&&min(ax[t],bx[t])<=x&&x<=max(ax[t],bx[t])&&min(ay[t],by[t])<=y&&y<=max(ay[t],by[t]))nxt0[i]=getid(x,y);
			else 
			nxt0[i]=getid(nx,ny);
			dir[nxt0[i]]=dir[t];
		}
	}
	for(int i=0;i<=lim;i++)
	{
		sort(vx[i].begin(),vx[i].end());
		for(int j=0;j<vx[i].size();j++)
		{
			int it=vx[i][j].SS;
			if(it>ttot)
			{
				if(dir[it]==2)assert(j>0),nxt0[it]=vx[i][j-1].SS;
				else if(dir[it]==3)assert(j+1<vx[i].size()),nxt0[it]=vx[i][j+1].SS;
			}
		}
		sort(vy[i].begin(),vy[i].end());
		for(int j=0;j<vy[i].size();j++)
		{
			int it=vy[i][j].SS;
			if(it>ttot)
			{
				if(dir[it]==0)assert(j>0),nxt0[it]=vy[i][j-1].SS;
				else if(dir[it]==1)assert(j+1<vy[i].size()),nxt0[it]=vy[i][j+1].SS;
			}
		}
	}
//	for(int i=1;i<=tot;i++)cout<<px[i]<<","<<py[i]<<":"<<dir[i]<<" ";cout<<endl;
	for(int i=1;i<=tot;i++)
	{
		nxt[0][i]=nxt0[i];
		if(nxt0[i])nxtd[0][i]=abs(px[nxt0[i]]-px[i])+abs(py[nxt0[i]]-py[i]);
		else nxtd[0][i]=Lbig;
//		cout<<i<<":"<<px[i]<<","<<py[i]<<"->"<<nxt0[i]<<"("<<px[nxt0[i]]<<","<<py[nxt0[i]]<<"),"<<nxtd[0][i]<<endl;
	}
	for(int i=1;i<55;i++)
	{
		for(int j=1;j<=tot;j++)
		{
			if(nxt[i-1][j])nxt[i][j]=nxt[i-1][nxt[i-1][j]],nxtd[i][j]=min(Lbig,nxtd[i-1][j]+nxtd[i-1][nxt[i-1][j]]);
			else nxt[i][j]=nxt[i-1][j],nxtd[i][j]=nxtd[i-1][j];
//			cout<<nxt[i][j]<<","<<nxtd[i][j]<<" ";
		}
//		cout<<endl;
	}
	for(int i=1;i<=q;i++)
	{
		int it=n+i;
		ll t=qt[i];
		for(int j=54;j>=0;j--)
		{
			if(nxt[j][it]&&t>=nxtd[j][it])
			{
				t-=nxtd[j][it];
				it=nxt[j][it];
			}
		}
		ll nx=px[it]+dx[dir[it]]*t,ny=py[it]+dy[dir[it]]*t;
		nx=max(0ll,min(lim,nx));
		ny=max(0ll,min(lim,ny));
		putsii(nx,ny);
	}
	return 0;
}