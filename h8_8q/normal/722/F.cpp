#include<bits/stdc++.h>

#define int __int128
#define mid ((l+r)>>1)

using namespace std;

inline int read()
{
	int res=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){res=res*10+c-'0';c=getchar();}
	return res*f;
}

inline void write(int x)
{
	if(x<0){putchar('-'),x=-x;}
	if(x==0) return;
	write(x/10);putchar(x%10+'0');
}

const int N=1e5+5,M=45;
int n,m,k[N],a[N][M],rt[N];

vector<int> hav[N];

map<int,int> mp[N];

struct Node
{
	int a,b;
};

inline int exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1,y=0;
		return a;
	}
	int tmp=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return tmp;
}

inline Node merge(Node X,Node Y)
{
	if(X.a==-1) return (Node){-1,-1};
	if(Y.a==-1) return (Node){-1,-1};
	int A=X.a,B=-Y.a,C=Y.b-X.b;
	int x,y,gcd=exgcd(A,B,x,y);
	if(C%gcd!=0)
		return (Node){-1,-1};
	else
	{
		x=x*C/gcd;
		y=y*C/gcd;
		int tmp=X.a*x+X.b,lcm=X.a*Y.a/__gcd(X.a,Y.a);
		tmp=(tmp%lcm+lcm)%lcm;
		return (Node){lcm,tmp};
	}
}

struct Seg
{
	vector<Node> val;
	vector<int> lc,rc;
	int cnt=-1,id;
	inline int new_node()
	{
		val.push_back((Node){0,0});
		lc.push_back(0);
		rc.push_back(0);
		return ++cnt;
	}
	inline int build(int x,int l,int r)
	{
		if(cnt==-1)
			new_node();
		if(x==0)
			x=new_node();
		if(l==r)
		{
			val[x].a=k[hav[id][l]];
			val[x].b=mp[hav[id][l]][id];
			return x;
		}
		int tmp=build(lc[x],l,mid);lc[x]=tmp;
		tmp=build(rc[x],mid+1,r);rc[x]=tmp;
		val[x]=merge(val[lc[x]],val[rc[x]]);
		return x;
	}
	inline Node query(int x,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R) return val[x];
		if(L<=mid&&mid+1<=R)
			return merge(query(lc[x],l,mid,L,R),query(rc[x],mid+1,r,L,R));
		else if(L<=mid)
			return query(lc[x],l,mid,L,R);
		else return query(rc[x],mid+1,r,L,R);
	}
}sum[N];

signed main()
{
	//freopen("cycle.in","r",stdin);
	//freopen("cycle.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;++i)
	{
		k[i]=read();
		for(int j=1;j<=k[i];++j)
		{
			a[i][j]=read();
			hav[a[i][j]].push_back(i);
			mp[i][a[i][j]]=j;
		}
	}
	for(int i=1;i<=m;++i)
	{
		if(hav[i].size()==0)
		{
			printf("0\n");
			continue;
		}
		sum[i].id=i;
		rt[i]=sum[i].build(rt[i],0,hav[i].size()-1);
		int res=1,l=0,r=0;
		for(int j=1;j<hav[i].size();++j)
			if(hav[i][j]!=hav[i][j-1]+1)
				l=j,r=j;
			else
			{
				++r;
				while(sum[i].query(1,0,hav[i].size()-1,l,r).a==-1)
					++l;
				res=max(res,r-l+1);
			}
		write(res);
		putchar('\n');
	}
	return 0;
}