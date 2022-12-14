#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<map>
#define MN 200000
#define N 262144
#define INF 2000000000
#define eps 1e-7
#define pa pair<int,int>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
double L[MN+5];map<pa,long long> num;
int K,n,m,totx=0,toty=0,fx[MN+5],fy[MN+5],A[MN+5];
long long Ans[MN+5],T[N*2+5];
struct vec{int x,y;double slop;}s[25];
bool cmps(const vec&a,const vec&b){return a.slop<b.slop;}
struct ques{int kind,x;double y;int id,ad,t;};
vector<ques> v[11];
inline double GetSlop(int y,int x){if(!x)return INF;else return (double)y/x;}
bool cmp(const ques&a,const ques&b){return a.x==b.x?a.kind>b.kind:a.x<b.x;}
void Renew(int x,int y){for(T[x+=N]+=y,x>>=1;x;x>>=1) T[x]=T[x<<1]+T[x<<1|1];}
long long Query(int l,int r)
{
	long long sum=0;
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) sum+=T[l+1];
		if( r&1) sum+=T[r-1];
	}
	return sum;
}

int Find(int r,double y)
{
	int l=1,res=r+1,mid;
	while(l<=r)
	{
		mid=l+r>>1;	
		if(L[mid]>y) res=mid,r=mid-1;
		else l=mid+1;
	}
	return res-1;
}

void Solve(vector<ques> q,int ky,int kx)
{
//	cout<<"Solve"<<k<<endl;
	int cnt=0;memset(T,0,sizeof(T));
	for(int i=1;i<=n;++i) 
		if(!kx) q.push_back((ques){1,fx[i],fy[i],A[i],0,0}),L[++cnt]=fy[i];
		else 
		{
			double c=(double)fy[i]-(double)fx[i]*ky/kx;L[++cnt]=c;
			q.push_back((ques){1,fx[i],c,A[i],0,0});
		}
	sort(q.begin(),q.end(),cmp);
//	for(int i=0;i<q.size();++i) printf("%d %.8lf %.8lf %d %d\n",q[i].kind,q[i].x,q[i].y,q[i].id,q[i].ad);
	sort(L+1,L+cnt+1);
	for(int i=0;i<q.size();++i)
		if(q[i].kind)
		{
			int p=lower_bound(L+1,L+cnt+1,q[i].y)-L;
			Renew(p,q[i].id);
		}
		else 
		{
			int p=upper_bound(L+1,L+cnt+1,q[i].y)-L-1;
			while(p>0&&q[i].t&&q[i].y==L[p]) --p;
			if(p>0) Ans[q[i].id]+=q[i].ad*Query(1,p); 
		}
}

int main()
{
	K=read();n=read();m=read();
	for(int i=1;i<=K;++i) 
	{
		s[i].x=read(),s[i].y=read();
		if(s[i].x<0) s[i].x=-s[i].x,s[i].y=-s[i].y;
		if(s[i].x==0&&s[i].y<0) s[i].y=-s[i].y;
		totx+=s[i].x,toty+=s[i].y,s[i].x<<=1,s[i].y<<=1;
	}
	for(int i=1;i<=K;++i) s[i].slop=atan2(s[i].y,s[i].x);
	sort(s+1,s+K+1,cmps);
	for(int i=1;i<=K;++i) s[i+K].x=-s[i].x,s[i+K].y=-s[i].y;K<<=1;
	for(int i=1;i<=n;++i)
		fx[i]=read(),fy[i]=read(),A[i]=read(),num[make_pair(fx[i],fy[i])]+=A[i];
	for(int i=1;i<=m;++i) 
	{
		int x=read(),y=read(),t=read(),id;
		x-=t*totx;y-=t*toty;Ans[i]+=num[make_pair(x,y)];
		for(int j=1,id=1;j<=K;x+=s[j].x*t,y+=s[j].y*t,++j,id=(j-1)%(K>>1)+1) 
		if(!s[j].x)
		{
			if(s[j].y<0)
			{
				v[id].push_back((ques){0,x,y,i,1,0});
				v[id].push_back((ques){0,x,y+s[j].y*t,i,-1,0});
				v[id].push_back((ques){0,x-1,y,i,-1,0});
				v[id].push_back((ques){0,x-1,y+s[j].y*t,i,1,0});
			}
		}
		else if(s[j].x<0)
		{
			double c=y-(double)x*s[j].y/s[j].x;
			v[id].push_back((ques){0,x,c,i,1,0});
			v[id].push_back((ques){0,x+s[j].x*t,c,i,-1,0});
		}
		else 
		{
			double c=y-(double)x*s[j].y/s[j].x;
			v[id].push_back((ques){0,x+s[j].x*t,c,i,-1,1});
			v[id].push_back((ques){0,x,c,i,1,1});
		}
	}
	for(int i=1;i<=K>>1;++i) Solve(v[i],s[i].y,s[i].x);
	for(int i=1;i<=m;++i) printf("%lld\n",Ans[i]); 
	return 0;
}