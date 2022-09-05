//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
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
const int B=2000;
const int msk=65535;
int tcnt[200111];
struct BLOCK
{
	int ht[200111];
	int cnt[B+2],nxt[B+2],pre[B+2];
	int ccnt[200111];
	void build(int a[],int n)
	{
		memset(ht,0,sizeof(ht));
		memset(ccnt,0,sizeof(ccnt));
		memset(nxt,0,sizeof(nxt));
		memset(pre,0,sizeof(pre));
		for(int i=1;i<=n;i++)
		{
			if(!(ht[a[i]]>>16))ht[a[i]]|=i<<16;
			cnt[i]=++tcnt[a[i]];
			ccnt[cnt[i]]++;
			if(ht[a[i]]&msk)
			{
				nxt[ht[a[i]]&msk]=i;
				pre[i]=ht[a[i]]&msk;
			}
			ht[a[i]]=(ht[a[i]]&(~msk))|i;
		}
	}
	int tpre,tnxt;
	void rebuild(int v,int x)
	{
		assert(ht[v]>0);
		int p=ht[v]>>16;
		tpre=-1,tnxt=-1;
		while(p)
		{
			if(p<x)tpre=p;
			else if(tnxt==-1)tnxt=p;
//			pre[nxt[p]]=p;
			cnt[nxt[p]]=cnt[p]+1;
			p=nxt[p];
		}
	}
	
	void addB(int v)
	{
		if(!ht[v])return;
		ccnt[cnt[ht[v]>>16]++]--;
		if((ht[v]>>16)==(ht[v]&msk))cnt[ht[v]>>16]--;
		ccnt[++cnt[ht[v]&msk]]++;
	}
	void delB(int v)
	{
		if(!ht[v])return;
		ccnt[--cnt[ht[v]>>16]]++;
		if((ht[v]>>16)==(ht[v]&msk))cnt[ht[v]>>16]++;
		ccnt[cnt[ht[v]&msk]--]--;
	}
	int querycnt(int x,int v)
	{
//		cout<<"querycnt:"<<x<<" "<<v<<endl;
		int p=ht[v]>>16;
//		cout<<"p="<<p<<endl;
		while(p&&p<x)cnt[nxt[p]]=cnt[p]+1,p=nxt[p];
		assert(p==x);
//		cout<<cnt[x]<<endl;
		return cnt[x];
	}
	void del(int x,int v)
	{
//		cout<<"del:"<<x<<","<<v<<endl;
//		rebuild(v);
//		cout<<pre[x]<<","<<nxt[x]<<endl;
		int head=ht[v]>>16,tail=ht[v]&msk;
		ccnt[cnt[tail]]--;
		if(head==x&&tail==x)ht[v]=0;
		else if(head==x)ht[v]=(ht[v]&msk)|(nxt[x]<<16),cnt[nxt[x]]=cnt[x],cnt[tail]-=nxt[x]!=tail,pre[nxt[x]]=0;
		else if(tail==x)ht[v]=(ht[v]&(~msk))|pre[x],cnt[pre[x]]=cnt[x]-1,nxt[pre[x]]=0;
		else nxt[pre[x]]=nxt[x],pre[nxt[x]]=pre[x],cnt[tail]--;
		nxt[x]=pre[x]=cnt[x]=0;
	}
	void add(int x,int v,int precnt,int tpre,int tnxt)
	{
//		cout<<"add:"<<x<<" "<<v<<" "<<precnt<<endl;
		int head=ht[v]>>16,tail=ht[v]&msk;
		if(head==0&&tail==0)
		{
			ht[v]=x<<16|x;
			cnt[x]=precnt+1;
			ccnt[cnt[x]]++;
		}
		else
		{
//			rebuild(v,x);
//			cout<<tpre<<","<<tnxt<<endl;
			ccnt[cnt[tail]+1]++;
			if(tpre!=-1)nxt[tpre]=x,pre[x]=tpre;
			else ht[v]=(ht[v]&msk)|(x<<16),cnt[x]=cnt[tnxt],pre[x]=0;
			if(tnxt!=-1)nxt[x]=tnxt,pre[tnxt]=x,cnt[tail]++;
			else cnt[x]=cnt[tail]+1,ht[v]=(ht[v]&(~msk))|x,nxt[x]=0;
		}
	}
	int queryccnt(int x,int v)
	{
		int ret=0;
		for(int i=1;i<=x;i++)
		{
			cnt[nxt[i]]=cnt[i]+1;
			ret+=cnt[i]==v;
		}
//		out(1);
		return ret;
	}
	void out(int n)
	{
		cout<<"------------debug----------"<<endl;
		for(int i=1;i<=n;i++)cout<<pre[i]<<" ";cout<<endl;
		for(int i=1;i<=n;i++)cout<<nxt[i]<<" ";cout<<endl;
		for(int i=1;i<=n;i++)cout<<cnt[i]<<" ";cout<<endl;
		for(int i=1;i<=3;i++)cout<<ccnt[i]<<" ";cout<<endl;
	}
}b[55];
int n,q,a[100111];
int val[200111],idtot;
map<int,int> id;
set<int>pos[200111];
int getid(int x)
{
	int &v=id[x];
	if(v==0)v=++idtot,val[idtot]=x;
	return v;
}
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)
	{
		geti(a[i]);
		a[i]=getid(a[i]);
		pos[a[i]].insert(i);
	}
	for(int i=1;i<=n;i+=B)b[(i-1)/B].build(a+i-1,min(n-i+1,B));
//	for(int i=0;i<n;i++)printf("%d",i),b[i].out(1);
	geti(q);
	int Bn=(n-1)/B;
	for(int i=1;i<=q;i++)
	{
//		for(int j=1;j<=n;j++)cout<<a[j]<<" ";cout<<endl;
//	b[0].out(n);
		int t,x,y;
		getiii(t,y,x);
		if(t==1)
		{
			y=getid(y);
			if(a[x]==y)continue;
			pos[a[x]].erase(x);
			int Bx=(x-1)/B,By=(x-1)%B+1;
			int precnt=0;
			for(int j=Bx-1;j>=0;j--)
			{
				if(b[j].ht[y]&msk)
				{
					precnt=b[j].cnt[b[j].ht[y]&msk];
					break;
				}
			}
			b[Bx].del(By,a[x]);
			for(int i=Bx+1;i<=Bn;i++)b[i].delB(a[x]);
			a[x]=y;
			pos[a[x]].insert(x);
			auto it=pos[a[x]].find(x);
			int tpre,tnxt;
			if(it==pos[a[x]].begin())tpre=-1;else tpre=*(--it),it++;
			it++;
			if(it==pos[a[x]].end())tnxt=-1;else tnxt=*it;
			tpre-=Bx*B;tnxt-=Bx*B;
			if(tpre<=0||tpre>B)tpre=-1;
			if(tnxt<=0||tnxt>B)tnxt=-1;
//			cout<<"precnt="<<precnt<<endl;
			b[Bx].add(By,a[x],precnt,tpre,tnxt);
			for(int i=Bx+1;i<=Bn;i++)b[i].addB(a[x]);
		}
		else if(t==2)
		{
			int Bx=(x-1)/B,By=(x-1)%B+1;
			if(y==1)putsi(val[a[x]]);
			else if(y%2==0)
			{
				putsi(b[Bx].querycnt(By,a[x]));
			}
			else
			{
				int ret=0,v=b[Bx].querycnt(By,a[x]);
//				cout<<"v="<<v<<endl;
				for(int i=0;i<Bx;i++)ret+=b[i].ccnt[v];
				ret+=b[Bx].queryccnt(By,v);
				putsi(ret);
			}
		}
	}
	return 0;
}