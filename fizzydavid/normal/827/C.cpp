//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
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
struct node
{
	int sum[10][10][4];
	void init(){memset(sum,0,sizeof(sum));}
	node(){init();}
}a[262500];
#define ls p<<1
#define rs p<<1|1
char id[256];
int ia[100111],n;
void change(int x,int nv,int l,int r,int p)
{
//	cout<<"change:"<<x<<" "<<nv<<" "<<l<<" "<<r<<" "<<p<<endl;
	if(ia[x]!=-1)
	{
		for(int i=0;i<10;i++)
		{
			a[p].sum[i][x%(i+1)][ia[x]]--;
		}
	}
	for(int i=0;i<10;i++)
	{
		a[p].sum[i][x%(i+1)][nv]++;
	}
	if(l==r)return;
	int m=l+r>>1;
	if(x<=m)change(x,nv,l,m,ls);
	else change(x,nv,m+1,r,rs);
}
char qs[20];
int q1,q2,q3;
int query(int x,int y,int l,int r,int p)
{
	if(x<=l&&r<=y)return a[p].sum[q1][q2][q3];
	int m=l+r>>1,ret=0;
	if(x<=m)ret+=query(x,y,l,m,ls);
	if(m<y)ret+=query(x,y,m+1,r,rs);
	return ret;
}
char s[100111];
int main()
{
	id['A']=0;
	id['G']=1;
	id['C']=2;
	id['T']=3;
	memset(ia,-1,sizeof(ia));
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		change(i,id[s[i]],1,n,1);
		ia[i]=id[s[i]];
	}
	int q;
	geti(q);
	while(q--)
	{
		int cmd,x,y;
		getii(cmd,x);
		if(cmd==1)
		{
			char c=mygetchar();
			change(x,id[c],1,n,1);
			ia[x]=id[c];
		}
		else
		{
			geti(y);
			scanf("%s",qs);
			int l=strlen(qs),ans=0;
			for(int i=0;i<l;i++)
			{
				q1=l-1;q2=(x+i)%l;q3=id[qs[i]];
				ans+=query(x,y,1,n,1);
//				cout<<"ans="<<ans<<endl;
			}
			putsi(ans);
		}
	}
	return 0;
}