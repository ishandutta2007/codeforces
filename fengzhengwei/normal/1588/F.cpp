#include<bits/stdc++.h>
namespace ifzw{
#define ll long long 
#define dd double
#define LL __int128
#define ull unsigned ll 
#define prs pair<int,int>
#define fi first
#define se second
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
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int xx=2e5+5;
int n,q,p[xx],p_[xx],bp[xx],rp[xx],ban[xx];
ll a[xx];
struct nod{int op,x,y;}e[xx];
ll ans[xx];
// 
vector<int>inf[xx];
struct tp
{
	int x,id,op;
	bool operator<(const tp&w)const{return x<w.x;}
};
// 
int T[xx],TT,bel[xx];
ll dlt[xx];
vector<ll>ndlt[xx];
ll sum[xx];
mt19937 G(218);
int rd(int l,int r){return uniform_int_distribution<int>(l,r)(G);}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
//	n=2e5;
//	for(int i=1;i<=n;i++)a[i]=i;
//	for(int i=1;i<=n;i++)p[i]=i;
//	q=2e5;
	for(int i=1;i<=q;i++)e[i].op=rd(1,3),e[i].x=rd(1,n),e[i].y=rd(1,n),(e[i].x>e[i].y?swap(e[i].x,e[i].y):void());
//	exit(0);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)p[i]=read();
	q=read();
	for(int i=1;i<=q;i++)
		e[i].op=read(),e[i].x=read(),e[i].y=read();
	random_device R;
	const int B=sqrt(2e5);//sqrt n  
//	cerr<<B<<"!\n";
	int ls=0;
	for(int I=1;I<=q;I++)
		if(I%B==0||I==q)
		{
			++TT;
			vector<int>use;
			for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
			for(int i=1;i<=n;i++)rp[i]=p[i];
			for(int i=ls+1;i<=I;i++)
				if(e[i].op==3)ban[e[i].x]=1,ban[e[i].y]=1;
			int tt=0;
			for(int i=1;i<=n;i++)p_[p[i]]=i;
			for(int i=1;i<=n;i++)
				if(!bel[i])
				{
					bel[i]=++tt;
					int x=i;
					while(!ban[x]&&!bel[x=rp[x]])bel[x]=tt;
					x=i;
					while(!ban[x=p_[x]]&&!bel[x])bel[x]=tt;
				}
			for(int i=1;i<=tt;i++)bp[i]=i;
			for(int i=1;i<=n;i++)if(ban[i])bp[bel[i]]=bel[rp[i]];
			for(int i=1;i<=n;i++)inf[bel[i]].push_back(i);
//			cerr<<I<<"@@\n";
			for(int i=ls+1;i<=I;i++)
			{
				if(e[i].op==1)
				{
					ndlt[i].resize(use.size());
					for(int j=0;j<(int)use.size();j++)ndlt[i][j]=(dlt[use[j]]);// time  
				}
				if(e[i].op==2)
				{
					int x=e[i].x,y=e[i].y;
					x=bel[x];
					#define upd(x) dlt[x]+=y;if(T[x]!=TT)use.push_back(x),T[x]=TT;
					upd(x);
					while((x=bp[x])!=bel[e[i].x])
					{
						upd(x);
					}
				}
				if(e[i].op==3)
				{
					swap(rp[e[i].x],rp[e[i].y]);
//					assert(ban[e[i].x]);
//					assert(ban[e[i].y]);
					bp[bel[e[i].x]]=bel[rp[e[i].x]];
					bp[bel[e[i].y]]=bel[rp[e[i].y]];
//					for(int i=1;i<=n;i++)if(ban[i])bp[bel[i]]=bel[rp[i]];
//					for(int o=1;o<=n;o++)cerr<<rp[o]<<" "<<ban[o]<<" "<<bel[o]<<"!!!!!\n";
//			for(int i=1;i<=tt;i++)cerr<<bp[i]<<"!\n";
				}
			}
			vector<tp>v;
			for(int i=ls+1;i<=I;i++)if(e[i].op==1)ans[i]=sum[e[i].y]-sum[e[i].x-1];
			for(int i=ls+1;i<=I;i++)
				if(e[i].op==1)v.push_back({e[i].x-1,i,-1}),v.push_back({e[i].y,i,1});
			sort(v.begin(),v.end());
			for(int j=0;j<(int)use.size();j++)
			{
				int lp=0;
				for(auto it:v)
				{
					while(lp<(int)inf[use[j]].size()&&inf[use[j]][lp]<=it.x)++lp;
//					assert(j<(int)ndlt[it.id].size());
					if(j<(int)ndlt[it.id].size())
					{
						ans[it.id]+=1ll*it.op*lp*ndlt[it.id][j];
//						if(it.id==255)cerr<<it.op<<" "<<it.id<<" "<<ans[it.id]<<" "<<lp<<" "<<ndlt[it.id][j]<<"@@\n";
//						if(it.op==1)
//						{
//							if(ans[it.id]<0)cerr<<it.op<<" "<<it.id<<" "<<ans[it.id]<<" "<<lp<<" "<<ndlt[it.id][j]<<"@@\n";
//							assert(ans[it.id]>=0);
//						}
					}
				}
				for(auto it:inf[use[j]])a[it]+=dlt[use[j]];
			}
			for(int i=ls+1;i<=I;i++)
				if(e[i].op==3)swap(p[e[i].x],p[e[i].y]);
			ls=I;
			//cls 
			for(int i=1;i<=n;i++)bel[i]=ban[i]=0;
			for(int i=1;i<=tt;i++)dlt[i]=0,inf[i].clear();
		}
	for(int i=1;i<=q;i++)if(e[i].op==1)cout<<ans[i]<<"\n";
	pc('1',1);
	return 0;
}

}int main(){return ifzw::main();}