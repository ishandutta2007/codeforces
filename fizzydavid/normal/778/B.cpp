//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
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
int n,m;
char ss[1111];
map<string,int> id;
int tab[5111][1111];
int op[5111],tl[5111],tr[5111];
int v[5111];
int solve(int t)
{
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(op[i]==0)v[i]=tab[i][t];
		else if(op[i]==1)v[i]=v[tl[i]]&v[tr[i]];
		else if(op[i]==2)v[i]=v[tl[i]]|v[tr[i]];
		else if(op[i]==3)v[i]=v[tl[i]]^v[tr[i]];
		if(v[i])sum++;
	}
	return sum;
}
int main()
{
	getii(n,m);
	id["?"]=0;
	for(int i=1;i<=n;i++)
	{
		string s;
		gets(ss);
		int tn=strlen(ss);
		for(int j=0;j<tn;j++)
		{
			s.PB(ss[j]);
		}
		int pos=s.find(':');
		string vs;
		for(int j=0;j<pos&&s[j]!=' ';j++)
		{
			vs.PB(s[j]);
		}
//		cout<<"vs="<<vs<<endl;
		id[vs]=i;
		s=s.substr(pos+3);
		if(s[0]>='0'&&s[0]<='9')
		{
			for(int j=0;j<m;j++)
			{
				tab[i][j]=s[j]-'0';
			}
		}
		else
		{
			pos=s.find(' ');
			tl[i]=id[s.substr(0,pos)];
			if(s[pos+1]=='A')
			{
				op[i]=1;
				tr[i]=id[s.substr(pos+5)];
			}
			else if(s[pos+1]=='O')
			{
				op[i]=2;
				tr[i]=id[s.substr(pos+4)];
			}
			else if(s[pos+1]=='X')
			{
				op[i]=3;
				tr[i]=id[s.substr(pos+5)];
			}
//			cout<<op[i]<<" "<<tl[i]<<" "<<tr[i]<<endl;
		}
	}
	string s1,s2;
	for(int i=0;i<m;i++)
	{
		v[0]=0;
		int ans0=solve(i);
		v[0]=1;
		int ans1=solve(i);
//		cout<<ans0<<" "<<ans1<<endl;
		if(ans0<ans1)s1.PB('0'),s2.PB('1');
		else if(ans0>ans1)s1.PB('1'),s2.PB('0');
		else s1.PB('0'),s2.PB('0');
	}
	cout<<s1<<endl<<s2<<endl;
	return 0;
}