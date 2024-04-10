#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;                                                                              
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,m;
const int xx=1e6+5;
struct node
{
	int s,p;
	bool operator<(const node&w)const{return s<w.s;}
}e[xx];
int mx[xx<<2],ad[xx<<2];
void Ad(int k,int x)
{
	mx[k]+=x;
	ad[k]+=x;
//	cout<<mx[k]<<" "<<x<<"\n";
}
void pd(int k)
{
	if(ad[k])
	{
		Ad(k<<1,ad[k]);
		Ad(k<<1|1,ad[k]);
		ad[k]=0;
	}
}
void update(int k)
{
	mx[k]=max(mx[k<<1],mx[k<<1|1]);
//	cout<<k<<" qweqwe "<<mx[k]<<"\n";
}
void cg(int k,int l,int r,int x,int y,int z)
{
	if(x<=l&&r<=y)return Ad(k,z);
	pd(k);
	int mid=l+r>>1;
	if(x<=mid)cg(k<<1,l,mid,x,y,z);
	if(mid<y)cg(k<<1|1,mid+1,r,x,y,z);
	update(k); 
}
int lsh[xx],tt;
vector<int>vp[xx];
vector<int>vs[xx];
void cc(int k,int l,int r,int x,int y)
{
	if(l==r)
	{
		mx[k]=y;
//		cout<<k<<" qweqe "<<mx[k]<<"\n";
		return ;
	}
	pd(k);
	int mid=l+r>>1;
	if(x<=mid)cc(k<<1,l,mid,x,y);
	else cc(k<<1|1,mid+1,r,x,y);
	update(k);
}
int ask(int k,int l,int r,int x,int y)
{
	if(x>y)return -1e9;
	if(x<=l&&r<=y)return mx[k];
	pd(k);
	int mid=l+r>>1;
	if(y<=mid)return ask(k<<1,l,mid,x,y);
	if(mid<x)return ask(k<<1|1,mid+1,r,x,y);
	return max(ask(k<<1,l,mid,x,y),ask(k<<1|1,mid+1,r,x,y));
}
ll F[xx];
int main(){
	n=read(),m=read();// 
	lsh[++tt]=m;
	for(int i=1;i<=n;i++)
		e[i].s=read(),e[i].p=read(),lsh[++tt]=e[i].p,lsh[++tt]=e[i].s;
	sort(lsh+1,lsh+tt+1);
	tt=unique(lsh+1,lsh+tt+1)-lsh-1;
	m=lower_bound(lsh+1,lsh+tt+1,m)-lsh;
	for(int i=1;i<=n;i++)
		e[i].p=lower_bound(lsh+1,lsh+tt+1,e[i].p)-lsh,
		e[i].s=lower_bound(lsh+1,lsh+tt+1,e[i].s)-lsh;
	sort(e+1,e+n+1);
	for(int i=1;i<=n;i++)
	{
		vp[e[i].p].push_back(i);
		vs[e[i].s].push_back(i);
	}
//	cout<<m<<"!!!\n";
//	for(int i=1;i<=n;i++)
//	{
//		cout<<e[i].s<<" "<<e[i].p<<"\n";
//	}
	memset(mx,-0x3f,sizeof(mx));
	cc(1,0,tt,0,0);//00 
	//yy+1s=y,p<=yp==y+1s>=y+1 
	//fx+dlt ()
	ll ans=0;
	for(int i=0;i<=tt;i++)
	{
		int mx=-1;
		for(auto it:vp[i])
		{
//			cout<<e[it].s<<" "<<i<<"ss \n";
			if(e[it].s<i)
				mx=max(mx,e[it].s);
		}
//	cout<<ask(1,0,tt,0,0)<<"\n";
		if(i<m)
		{
			F[i]=-1e9;
		}
		else 
		{
			if(i==m)F[i]=ask(1,0,tt,0,0),cc(1,0,tt,0,-1e9);
			else 
			F[i]=max(ask(1,0,tt,mx+1,i),ask(1,0,tt,0,mx)+1);
//			cout<<"!!!ADSD "<<ask(1,0,tt,0,3)<<"\n";
		}
		ans=max(ans,F[i]);
		if(i)cc(1,0,tt,i,F[i]);
//		cout<<i<<" "<<m<<" iii "<<F[i]<<" "<<mx<<" "<<ask(1,0,tt,0,tt)<<"\n";
		for(auto it:vs[i])
		{
			if(e[it].p>i)continue;
//			puts("SSSSS");
//			cout<<e[it].p-1<<" opo "<<"\n";
//			cout<<"!!!#$#$#$ "<<ask(1,0,tt,0,3)<<"\n";
			cg(1,0,tt,0,e[it].p-1,-1);
//			cout<<"!!!#$#$#$ "<<ask(1,0,tt,0,3)<<"\n";
		}
		for(auto it:vp[i+1])
		{
			if(e[it].s<i+1)continue;
//			puts("qweqwe");
			//>=y+1
			cg(1,0,tt,0,tt,1);
		}
	}
	cout<<ans<<"\n";
	return 0;
}