#include<bits/stdc++.h>
#define ll long long
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
const int xx=1e5+5;
int mp[xx<<2],mp2[xx<<2];
int n,m;
int t[xx];
int f[xx][3];
ll sum[xx];
int B;
int bel(int x){return (x-1)/B+1;}
struct node
{
	int l,r,id;
	bool operator<(const node&w)const{return bel(l)==bel(w.l)?bel(l)&1?r<w.r:r>w.r:l<w.l;}
}e[xx];
ll ans=0;
ll lsh[xx<<2];
void addl(int x)
{
//	cout<<x<<" "<<sum[x]<<" "<<sum[x-1]<<"\n";
	ans+=mp[f[x][1]];
	mp[f[x][0]]++;
}
void addr(int x)
{
	ans+=mp[f[x][2]];
	mp[f[x][0]]++;
//	cout<<ans<<" "<<f[x][2]<<" "<<x<<" ss "<<sum[x]<<"\n";
}
void erasel(int x)// 
{
	mp[f[x][0]]--; 
	ans-=mp[f[x][1]];
}
void eraser(int x)
{
	mp[f[x][0]]--; 
	ans-=mp[f[x][2]];
}
ll res[xx];
int main(){
//	mp[0]++;
	n=read();
	m=read();
	for(int i=1;i<=n;i++)t[i]=-(read()-2),!t[i]?t[i]=-1:t[i]=1;//12 
	for(int i=1;i<=n;i++)t[i]=read()*t[i];//12 
	int tot=0;
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+t[i],lsh[++tot]=sum[i],lsh[++tot]=sum[i]+m,lsh[++tot]=sum[i]-m;
	lsh[++tot]=sum[0],lsh[++tot]=sum[0]+m,lsh[++tot]=sum[0]-m;
	sort(lsh+1,lsh+tot+1);
	tot=unique(lsh+1,lsh+tot+1)-lsh-1;
	for(int i=0;i<=n;i++)
	{
		f[i][0]=lower_bound(lsh+1,lsh+tot+1,sum[i])-lsh;// 
		f[i][1]=lower_bound(lsh+1,lsh+tot+1,sum[i]+m)-lsh;//+m 
		f[i][2]=lower_bound(lsh+1,lsh+tot+1,sum[i]-m)-lsh;//-m 
	}
//	for(int i=1;i<=n;i++)cout<<sum[i]<<"ss \n";
	int q=read();
	B=sqrt(q);
	for(int i=1;i<=q;i++)e[i].l=read()-1,e[i].r=read(),e[i].id=i;
	sort(e+1,e+q+1);
	int l=1,r=0;
	for(int i=1;i<=q;i++)
	{
		while(r<e[i].r)addr(++r);
//		cout<<i<<"\n";
		while(l>e[i].l)addl(--l);
		while(r>e[i].r)eraser(r--);
		while(l<e[i].l)erasel(l++);
		res[e[i].id]=ans;
	}
	for(int i=1;i<=q;i++)cout<<res[i]<<"\n";
	return 0;
}