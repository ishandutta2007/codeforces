#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc()
{
	static char buf[1<<16],*s,*t;
	if(s==t)
	{
		t=(s=buf)+fread(buf,1,1<<16,stdin);
		if(s==t)return EOF;
	}
	return *s++;
}
#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,w,q;
const int xx=1e5+5;
int a[xx],minn[xx][21],maxx[xx][21];
int Log[xx];
int gmax(int l,int r)
{
	int k=Log[(r-l+1)];
	return max(maxx[l][k],maxx[r-(1<<k)+1][k]);
}
int gmin(int l,int r)
{
	int k=Log[(r-l+1)];
	return min(minn[l][k],minn[r-(1<<k)+1][k]);
}
int size[xx],f[xx],c[xx][2];// 
void ph(int k){size[k]=size[c[k][0]]+size[c[k][1]]+1;}
bool nroot(int x){return c[f[x]][0]==x||c[f[x]][1]==x;}
void rotate(int x)
{
	int y=f[x],z=f[y],s=(c[y][1]==x);
	c[y][s]=c[x][!s];f[c[x][!s]]=y;
	f[x]=z;if(nroot(y))c[z][c[z][1]==y]=x;
	f[c[x][!s]=y]=x;ph(y),ph(x);
}
void splay(int x)
{
	while(nroot(x))
	{
		int y=f[x],z=f[y];
		if(nroot(y))
		{
			if((c[z][1]==y)==(c[y][1]==x))rotate(y);
			else rotate(x);
		}
		rotate(x);
	}
}
void access(int x)
{
	for(int y=0;x;x=f[y=x])
	{
		splay(x);
		c[x][1]=y;
		ph(x);
	}
}
void link(int x,int y)
{
//	cout<<"L"<<x<<" "<<y<<"\n";
	access(x);splay(x);
	f[x]=y;
}
void cut(int x,int y)
{
	access(x),splay(y);//y 
	c[y][1]=f[x]=0;//cy1 
//	cout<<"C"<<x<<" "<<y<<" "<<c[y][1]<<"\n";
	ph(y);
}
struct qu
{
	int id,k;
	bool operator<(const qu&w)const{return k<w.k;}
}s[xx];
int ans[xx];
int find(int x,int y) //xy+1 
{
	int l=x,r=n,ans=0;
	while(l<=r)
	{
		int mid=l+r>>1;
		
		if(gmax(x,mid)-gmin(x,mid)<=y)ans=mid,l=mid+1;
		else r=mid-1;
//		if(l>r)break;
//		cout<<l<<" "<<r<<"\n";
	}
	return ans;
}
struct nod
{
	int s,x,y;//sset
	bool operator<(const nod&w) const{return s<w.s;}
};
multiset<nod>v;
signed main(){
//	cout<<int(ceil(pow(100000,1.0/4)));
	Log[0]=-1;
	for(int i=1;i<=100000;i++)Log[i]=Log[i-1]+(i==(i&-i));
	n=read();
	w=read();
	q=read();
	memset(minn,0x3f,sizeof(minn));
	memset(maxx,-0x3f,sizeof(maxx));
	for(int i=1;i<=n;i++)a[i]=read(),minn[i][0]=a[i],maxx[i][0]=a[i],size[i]=1;
	for(int j=1;j<=20;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i+((1<<j-1))>n)minn[i][j]=minn[i][j-1],maxx[i][j]=maxx[i][j-1];
			else minn[i][j]=min(minn[i][j-1],minn[i+(1<<j-1)][j-1]),maxx[i][j]=max(maxx[i][j-1],maxx[i+(1<<j-1)][j-1]);
		}
	}
	for(int i=1;i<=q;i++)s[i].k=w-read(),s[i].id=i;
	sort(s+1,s+q+1);//+1 
	for(int i=1;i<n;i++)link(i,i+1),v.insert((nod){max(a[i+1],a[i])-min(a[i+1],a[i]),i,i+1});
	// 
//	cout<<find(1,2)<<" "<<gmax(1,3)<<" "<<gmin(1,3)<<"\n";
	int B=78;
	for(int i=1;i<=q;i++)
	{
		int a=s[i].k;
		while(v.size()&&(*v.begin()).s<=a)//lct 
		{
			nod u=*v.begin();//n+1set 
			v.erase(v.begin());
			cut(u.x,u.y);
			int t=find(u.x,a);
			t++;
			if(t==n+1||t-u.x>B)continue;// 
			link(u.x,t);
			v.insert((nod){gmax(u.x,t)-gmin(u.x,t),u.x,t});
		}
		int now=1,bs=0;
		while(now!=n+1)
		{
//			cout<<f[now]<<" "<<"\n";
			access(now);
			splay(now);
			bs+=size[now]-1;
			while(c[now][0])now=c[now][0];
			now=find(now,a)+1;
			bs++;
		}
		ans[s[i].id]=bs;
//		cout<<s[i].k<<"\n";
//		puts("");
	}
	for(int i=1;i<=q;i++)cout<<ans[i]-1<<"\n";
	return 0;
}