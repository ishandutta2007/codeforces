#include<bits/stdc++.h>
#define ll long long
#define LL __int128
#define dd double
#define ull unsigned ll
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(ll x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(ll x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int xx=2e5+5;
int n;
ll r;
namespace SS
{
	struct seg{int mn,l,r,tag;}e[xx*32];
	int cst;
	void upd(int k){/*cerr<<k<<"@@@@@@@@@@@@@@@@@\n";*/e[k].mn=min(e[e[k].l].mn,e[e[k].r].mn)+e[k].tag;}
	void Cov(int k,int l,int r,int x,int y,int z)
	{
		if(x>y||!k)return; 
		if(x<=l&&r<=y)return e[k].tag+=z,e[k].mn+=z,void();
		int mid=l+r>>1;
		if(x<=mid)Cov(e[k].l,l,mid,x,y,z);
		if(mid<y)Cov(e[k].r,mid+1,r,x,y,z);
		upd(k);
	}
//	void get(int k,int l,int r)
//	{
//		if(e[k].mn==e[e[k].l].mn+e[k].tag)cerr<<
//	}
	int rt;
	void cov(int k,int x,int y,int z)
	{
//		cerr<<x<<" "<<y<<" "<<z<<" "<<rt<<"##\n";
		if(x>y)return;
		Cov(k,0,r-1,x,y,z);
	}
	// tag  
	void Set(int &k,int l,int r,int x,int y)
	{
	//	cerr<<k<<" "<<x<<" "<<y<<" "<<" "<<rt<<"##\n";
	//	assert(k>=0);
	//	cerr<<k<<" "<<cst<<"!!!!!!!!!!!!!!!!!\n";
		if(!k)k=++cst,e[k].mn=1e9,assert(!e[k].l),assert(!e[k].r);
		y-=e[k].tag;// a 
//		cerr<<y<<" "<<k<<" "<<e[k].tag<<"$$$\n";
		if(l==r)return e[k].mn=min(e[k].mn,y+e[k].tag),void();
		int mid=l+r>>1;
		if(x<=mid)Set(e[k].l,l,mid,x,y);
		else Set(e[k].r,mid+1,r,x,y);
		upd(k);
//		cout<<e[k].mn<<" "<<e[k].tag<<" "<<k<<"!!\n";
	}
}
using SS::rt;
using SS::Set;
using SS::cov;
vector<ll>use;
//tm 
int f[xx];
struct info
{
	ll T;
	int id,op;
	//-1   id 5 1 R  2 3 4 
	bool operator<(const info&w)const{return T==w.T?op==w.op?id<w.id:op<w.op:T<w.T;}
};
set<info>tb;
struct nod
{
	int l,r;
}e[xx];
ll sf(ll x){return (x%r+r)%r;}
signed main(){
	SS::e[0].mn=1e9;
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	n=read(),r=read();
//	if(r==1)
//	{
//		cout<<n<<"\n";
//		return 0;
//	}
	//len 
	for(int i=1;i<=n;i++)
	{
		e[i].l=read(),e[i].r=read();
		if(e[i].r<0){i--,n--;continue;}
		if(e[i].l>=0)use.push_back(e[i].l);
	}
	use.push_back(0),use.push_back(3e9);
	sort(use.begin(),use.end());
	use.resize(unique(use.begin(),use.end())-use.begin());
//	for(auto it:use)cerr<<it<<"%%\n";
//	cerr<<use.size()<<"#\n";
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	//**** i r+1 
	// r -1  
	for(int i=0;i<(int)use.size();i++)tb.insert({use[i]+r,i,5});
	for(int i=1;i<=n;i++)tb.insert({e[i].r+1,i,1});
	ll nt=0;
	int ct=0;
	multiset<int>L;
	int te=0;
	for(int i=1;i<(int)use.size();i++)
	{
//		cerr<<i<<" "<<use[i]<<"~!~~\n";
		while(tb.size()&&tb.begin()->T<=use[i])
		{
			auto it=*tb.begin();
			tb.erase(tb.begin());
			int id=it.id;
			if(it.op==-1)
			{
//				cerr<<it.T<<"@@\n";
				for(auto l:L)
//					cerr<<it.T<<" "<<it.id<<" "<<it.op<<"@\n",
					cov(rt,0,sf(l)-1,-1),cov(rt,sf(l),r-1,-1);
			}
			// 
			if(it.op==5)
			{
//				cerr<<rt<<" "<<f[id]<<" "<<it.T<<" "<<SS::e[rt].mn<<"##########\n";
				Set(rt,0,r-1,use[id]%r,f[id]);
			}
			if(it.op==1)
			{
				++te;
				if(e[id].l<=it.T-r)
				{
//					cerr<<e[id].l<<" "<<it.T-r<<"^^^^^^^^^\n";
					if(e[id].l<=it.T-r-r+1)continue;
					tb.insert({e[id].l+r+r-1,id,4});
					L.insert(e[id].l);
					if(sf(e[id].l)<=sf((it.T-r)))
//					cerr<<L.size()<<"^ $\n",
					cov(rt,0,sf(e[id].l)-1,1),tb.insert({((it.T-r)/r+1)*r+r,0,-1});
					else cov(rt,sf(e[id].l),r-1,-1);
				}
				else 
				{
//					cerr<<it.T<<" "<<id<<"$\n",
					++ct;
					tb.insert({e[id].l+r,id,2});
				}
			}
			if(it.op==2)
			{
				--ct;
				tb.insert({e[id].r+r+1,id,3});
				L.insert(e[id].l);
				if(sf(e[id].l)<=sf((it.T-r)))cov(rt,0,sf(e[id].l)-1,1),tb.insert({((it.T-r)/r+1)*r+r,0,-1});
				else cov(rt,sf(e[id].l),r-1,-1);
			}
			if(it.op==3)
			{
				if(sf(e[id].l)<=sf(e[id].r))
				{
					cov(rt,sf(e[id].r)+1,r-1,1);
					cov(rt,0,sf(e[id].l)-1,1);
				}
				else 
				{
//				cerr<<id<<" "<<it.T<<"@@\n",
					cov(rt,sf(e[id].r)+1,sf(e[id].l)-1,1);
				}
				L.erase(L.find(e[id].l));
				if(sf(e[id].l)<=sf((it.T-r)))cov(rt,0,sf(e[id].l)-1,-1);//len   
				else 
				cov(rt,sf(e[id].l),r-1,1);
			}
			if(it.op==4)
			{
				L.erase(L.find(e[id].l));
				// 1  L  0  R  r-1  
				if(sf(e[id].l)<=sf((it.T-r)))cov(rt,0,sf(e[id].l)-1,-1);
				else cov(rt,sf(e[id].l),r-1,1);
			}
		}
		nt=use[i];
//				cerr<<"@@\n",
		cov(rt,sf(nt-r)+1,r-1,L.size());
		f[i]=SS::e[rt].mn+ct;
		f[i]=min(f[i],te);// 
		cov(rt,sf(nt-r)+1,r-1,-L.size());
//		cerr<<i<<" "<<" "<<f[i]<<" "<<te<<" "<<nt<<" qqqqqqqqqqqqq "<<use[i]<<" "<<rt<<" "<<SS::e[rt].mn<<" "<<L.size()<<"$\n";
	}
//	cerr<<f[(int)use.size() -1]<<"\n";
	cout<<n-f[(int)use.size() -1]<<"\n";
	pc('1',1);
	return 0;
}
/*
6 3
-6 -5
1 2
2 8
-7 0
-8 0
-2 -1

8 7
1 4
-9 0
-3 6
1 2
-1 0
-10 9
1 6
-3 7

6 5
-1 10
1 3
6 7
2 8
-2 1
-1 0

6 7
1 9
-1 1
2 3
2 5
5 6
1 2

5 5
3 4
-1 9
-8 4
-3 8
-2 2

*/