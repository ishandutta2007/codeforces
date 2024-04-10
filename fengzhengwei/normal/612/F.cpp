// LUOGU_RID: 90316785
#include<bits/stdc++.h>
namespace ifzw{
#define ll long long 
#define dd double
#define LL __int128
#define ld long double
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
char ST;
const int xx=2005;
int f[xx],g[xx],prf[xx],prg[xx],a[xx],n,m;
// 
// op  
void upd(int i,int m,int dlt)
{
//	cerr<<f[i]<<" "<<dlt<<"%^^^^^\n";
	if(i==0)
	{
		if(f[i]>dlt)
		f[i]=dlt,prf[i]=m;
	}
	else 
	if(f[i]>dlt+min(abs(m-i),n-abs(m-i)))/*cerr<<i<<"##\n",*/f[i]=dlt+min(abs(m-i),n-abs(m-i)),prf[i]=m;
}
// x  y  
#define PP pair<char,int>
PP dis(int x,int y)
{
	if(abs(x-y)<n-abs(x-y))
	{
		if(x<=y)return {'+',abs(y-x)};
		return {'-',abs(y-x)};
	}
	else 
	{
		if(x<=y)return {'-',n-abs(y-x)};
		return {'+',n-abs(y-x)};
	}
	assert(0);
	return {};
}
template<typename T>
void print(T v){cout<<v.first<<""<<v.second<<"\n";}
// 0->f 1->g 
int nx[xx],pr[xx];
int cl(int x,int y){return x<=y?(y-x):n-abs(x-y);}
int co(int x,int y){return x==y?0:n-cl(y,x);}
void re(int x,int op)
{
	if(op==0)
	{
		if(a[prf[x]]<a[x]||x==0)re(prf[x],1);
		if(x)print(dis(prf[x],x));
	}
	else 
	{
		re(prg[x],0);
		if(prg[x]==x);
		else 
		{
			vector<PP>v1,v2;
			int to=prg[x];
			// 
			while(to!=nx[x])v1.push_back(dis(to,pr[to])),to=pr[to];
			v1.push_back(dis(to,nx[prg[x]])),to=nx[prg[x]];
			while(to!=x)v1.push_back(dis(to,nx[to])),to=nx[to];
			
			to=prg[x];
			while(to!=pr[x])v2.push_back(dis(to,nx[to])),to=nx[to];
			v2.push_back(dis(to,pr[prg[x]])),to=pr[prg[x]];
			while(to!=x)v2.push_back(dis(to,pr[to])),to=pr[to];
			
			ll val1=0,val2=0;
			for(auto it:v1)val1+=it.second;
			for(auto it:v2)val2+=it.second;
			if(val1<val2)for(auto it:v1)print(it);
			else for(auto it:v2)print(it);
		}
	}
}
int dist(int x,int y){return min(abs(x-y),n-abs(x-y));}
int run(int x,int y){return min(n-cl(pr[y],y)+cl(x,pr[y]),n-cl(y,nx[y])+co(x,nx[y]));}
char ED;
int main(){
//	freopen("a.in","r",stdin);
	n=read(),m=read();
	vector<int>lsh;
	for(int i=1;i<=n;i++)a[i]=read(),lsh.push_back(a[i]);
	sort(lsh.begin(),lsh.end());
	lsh.resize(unique(lsh.begin(),lsh.end())-lsh.begin());
	for(int i=1;i<=n;i++)a[i]=lower_bound(lsh.begin(),lsh.end(),a[i])-lsh.begin();
	for(int i=0;i<=n;i++)f[i]=g[i]=1e9;
	for(int i=1;i<=n;i++)if(a[i]==0)upd(i,m,0);//,cerr<<f[i]<<" "<<i<<"^^^\n";
	for(int i=1;i<=n;i++)
	{
		int j=i+1;
		while(1)
		{
			if(j==n+1)j=1;
			if(a[j]==a[i]){nx[i]=j;break;}
			++j;
		}
		j=i-1;
		while(1)
		{
			if(j==0)j=n;
			if(a[j]==a[i]){pr[i]=j;break;}
			--j;
		}
	}
//	cout<<run(7,1)<<" "<<pr[1]<<" "<<pr[7]<<" "<<nx[1]<<" "<<nx[7]<<"#\n";
//	exit(0);
	for(int j=0;j<lsh.size();j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=j)continue;
			for(int k=1;k<=n;k++)
			{
				if(a[k]==j&&k!=i)
				{
					if(g[k]>f[i]+run(i,k))
						/*cerr<<k<<" "<<i<<" "<<f[i]+run(i,k)<<" "<<f[i]<<" "<<"%\n",*/g[k]=f[i]+run(i,k),prg[k]=i;
				}
			}
			if(nx[i]==i)g[i]=f[i],prg[i]=i;
		}
		//cerr<<g[2]<<"#$#$\n";
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=j)continue;
			for(int k=0;k<=n;k++)
				if(a[k]==j+1||(j==(lsh.size()-1)&&k==0))/*cerr<<k<<" "<<i<<" "<<g[i]<<"%%\n",*/upd(k,i,g[i]);
		}
		//cout<<f[2]<<"$\n";
	}
	cout<<f[0]<<"\n";
	re(0,0);
	pc('1',1);
	return 0;
}

}signed main(){return ifzw::main();}