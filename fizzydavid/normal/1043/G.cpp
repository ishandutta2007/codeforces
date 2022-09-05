//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
const int mod=1e9+7;
struct AP//Arithmetic Progression
{
	int s,d,n;//a_i=s+i*d(0<=i<n)
	AP(int S=0,int D=1,int N=0){s=S;d=D;n=N;}
	void clear(){s=0;d=1;n=0;}
	int get(int x)const{return s+x*d;}
	int last()const{return s+(n-1)*d;}
	bool check(int x)const{int t=(x-s)/d;return (x-s)%d==0&&t>=0&&t<n;}
	bool append(int x)
	{
		if(n==0)s=x,n=1;
		else if(n==1&&x>s)d=x-s,n=2;
		else if(n==2&&x>last()&&(x-last())==d)n++;
		else return false;
		return true;
	}
	AP operator+(const int &t){return AP(s+t,d,n);}
	AP operator-(const int &t){return AP(s-t,d,n);}
	AP operator-(){return AP(-last(),d,n);}
	AP operator&(const AP &t)const
	{
		if(d==t.d)
		{
			if(s%d!=t.s%d)return AP();
			else
			{
				int l=max(s,t.s),r=min(last(),t.last());
				if(l>r)return AP();else return AP(l,d,(r-l)/d+1);
			}
		}
		else
		{
			if(n<=t.n)
			{
				AP ret;
				for(int i=0;i<n;i++)
				{
					int x=get(i);
					if(t.check(x))ret.append(x);
				}
				return ret;
			}
			else return t&(*this);
		}
	}
};
const int maxn=200111;
const int maxh=20;
struct SuffixArray
{
	char s[maxn];
	int n,sa[maxn],rk[maxn],b[maxn];
	int lg2[maxn],lcp[maxn],tab[maxh][maxn];
	void getsa_init()
	{
		int m=256;
		for(int i=1;i<=n;i++)b[rk[i]=s[i]]++;
		for(int i=1;i<=m;i++)b[i]+=b[i-1];
		for(int i=n;i>=1;i--)sa[b[rk[i]]--]=i;	
	}
	#define rkpair(x) MP(rk[x],x+k<=n?rk[x+k]:x)
	void getsa(int k)
	{
		static int c[maxn];
		for(int i=1;i<=n;i++)if(sa[i]>n-k)c[++b[rk[sa[i]]]]=sa[i];
		for(int i=1;i<=n;i++)if(sa[i]>k)c[++b[rk[sa[i]-k]]]=sa[i]-k;
		swap(c,sa);
		int m=1;b[1]=0;c[sa[1]]=1;
		for(int i=2;i<=n;i++)
		{
			if(rkpair(sa[i-1])!=rkpair(sa[i]))b[++m]=i-1;
			c[sa[i]]=m;
		}
		swap(c,rk);
	}
	void construct_sa()
	{
		getsa_init();
		for(int k=1;k<n;k<<=1)getsa(k);
		for(int i=1;i<=n;i++)rk[sa[i]]=i;
	}
	void construct_lcp()
	{
		int h=0;
		for(int i=1;i<=n;i++)
		{
			h-=!!h;
			if(rk[i]==1)continue;
			int j=sa[rk[i]-1];
			while(i+h<=n&&j+h<=n&&s[i+h]==s[j+h])h++;
			lcp[rk[i]-1]=h;
		}
		for(int i=1;i<=n;i++)tab[0][i]=lcp[i];
		for(int i=1;i<maxh;i++)
		{
			for(int j=1;j<=n-(1<<i)+1;j++)
			{
				tab[i][j]=min(tab[i-1][j],tab[i-1][j+(1<<(i-1))]);
			}
		}
		lg2[1]=0;
		for(int i=2;i<=n;i++)lg2[i]=lg2[i>>1]+1;
	}
	void init(char S[],int N)
	{
		n=N;for(int i=1;i<=n;i++)s[i]=S[i];
	}
	void construct()
	{
		construct_sa();
		construct_lcp();
	}
	int getlcp(int x,int y)
	{
		x=rk[x];y=rk[y];
		if(x==y)return n-x+1;
		if(x>y)swap(x,y);
		int t=lg2[y-x];
		return min(tab[t][x],tab[t][y-(1<<t)]);
	}
}S1,S2;
struct IPM
{
	SuffixArray A;int n,m;
	struct data
	{
		int rk,pre,nxt,diff,dnxt;
	}tab[maxh][maxn];
	int rk[maxh][maxn],sa[maxh][maxn];
	void copysa(int k)
	{
		for(int i=1;i<=n;i++)
		{
			data &cur=tab[k][i];
			sa[k][i]=A.sa[i];
			cur.rk=A.rk[A.sa[i]];
			cur.pre=(i==1?1:(cur.rk==tab[k][i-1].rk?tab[k][i-1].pre:i));
			rk[k][A.sa[i]]=i;
		}
		for(int i=n;i>=1;i--)
		{
			data &cur=tab[k][i];
			if(i==n)
			{
				cur.diff=1e9;
				cur.dnxt=n;
				cur.nxt=n+1;
			}
			else
			{
				cur.diff=(cur.rk==tab[k][i+1].rk?sa[k][i+1]-sa[k][i]:1e9);
				cur.dnxt=(cur.diff==tab[k][i+1].diff?tab[k][i+1].dnxt:sa[k][i+1]);
				cur.nxt=(cur.rk==tab[k][i+1].rk?tab[k][i+1].nxt:i+1);
			}
		}
	}
	void construct(char s[],int N)
	{
		n=N;A.init(s,n);
		A.getsa_init();
		copysa(0);m=1;
		for(int k=1;k<n;k<<=1)
		{
			A.getsa(k);
			copysa(m++);
		}
	}
	AP matching(int x,int lv,int l,int r)//start positions in [l,r] 
	{
		if(l>r)return AP();
		assert(r-l+1<=(1<<lv));
		int i=rk[lv][x];
		int pl=tab[lv][i].pre,pr=tab[lv][i].nxt;
		int p=lower_bound(sa[lv]+pl,sa[lv]+pr,l)-sa[lv];
		if(p>=pl&&p<pr)
		{
			data &cur=tab[lv][p];
			if(sa[lv][p]>r)return AP();
			else return AP(sa[lv][p],cur.diff,(min(cur.dnxt,r)-sa[lv][p])/cur.diff+1);
		}
		else return AP();
	}
	AP queryborder(int lv,int l,int r)//[2^lv,2^(lv+1))
	{
		int L=(1<<lv);
		if(L>=r-l+1)return AP(0,1,0);
		else
		{
			AP ap1=matching(l,lv,max(l+1,r-L*2+2),r-L+1);
			AP ap2=matching(r-L+1,lv,l,min(r-L,l+L-1));
			AP ret=(ap2&(-ap1+(r+1-L+l)))+(L-l);
			return ret;
		}
	}
	vector<AP> queryborder(int l,int r)
	{
		vector<AP> ret;
		for(int k=0;k<m;k++)
		{
			AP ap=queryborder(k,l,r);
			if(ap.n>0)ret.PB(ap);
		}
		return ret;
	}
	int querymxborder(int l,int r)
	{
		for(int k=m-1;k>=0;k--)
		{
			AP ap=queryborder(k,l,r);
			if(ap.n>0)return ap.last();
		}
		return -1;
	}
}M;
int n,q;
char s[maxn];
int cnt[maxn][26];
int prep[maxn],nxtp[maxn],mnnxtp[maxn];
set<pair<int,int> > runs;
void prework()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<26;j++)cnt[i][j]=cnt[i-1][j]+(s[i]=='a'+j);
	}
	M.construct(s,n);
	S1.init(s,n);
//	S1.construct();
	for(int i=1;i<=n;i++)S1.sa[i]=M.A.sa[i];
	for(int i=1;i<=n;i++)S1.rk[S1.sa[i]]=i;
	S1.construct_lcp();
	reverse(s+1,s+n+1);
	S2.init(s,n);
	S2.construct();
	reverse(s+1,s+n+1);
	//find all primitive squares
	memset(prep,-1,sizeof(prep));
	memset(nxtp,-1,sizeof(nxtp));
	for(int i=1;i<=n+1;i++)mnnxtp[i]=n+1;
	runs.clear();
	for(int L=1;L<=n/2;L++)
	{
		int R=0;
		for(int i=1;(i+1)*L<=n;i++)
		{
			int p=i*L,q=(i+1)*L;
			if(q<=R)continue;
			int l1=S2.getlcp(n-p+1,n-q+1);
			int l2=S1.getlcp(p,q);
			if(l1+l2<=L)continue;
			int l=p-l1+1,r=q+l2-1;
			if(runs.find(MP(l,r))!=runs.end())continue;
			runs.insert(MP(l,r));
			for(int j=l;j+2*L-1<=r;j++)
			{
				if(nxtp[j]==-1)nxtp[j]=j+2*L-1;
				if(prep[j+2*L-1]==-1)prep[j+2*L-1]=j;
			}
			R=r;
		}
	}
	for(int i=n;i>=1;i--)
	{
		mnnxtp[i]=min(mnnxtp[i],mnnxtp[i+1]);
		if(nxtp[i]!=-1)mnnxtp[i]=min(mnnxtp[i],nxtp[i]);
	}
}
int query(int l,int r)
{
	int len=r-l+1;
	//answer -1
	if(len<=26)
	{
		bool flag=1;
		for(int i=0;i<26&&flag;i++)flag&=(cnt[r][i]-cnt[l-1][i])<=1;
		if(flag)return -1;
	}
	int mxborder=M.querymxborder(l,r);
	//answer 1
	if(mxborder!=-1&&len%(len-mxborder)==0)return 1;
	//answer 2
	if(nxtp[l]!=-1&&nxtp[l]<=r)return 2;
	if(prep[r]!=-1&&prep[r]>=l)return 2;
	if(mxborder!=-1)return 2;
	//answer 3
	if(cnt[r][s[l]-'a']-cnt[l-1][s[l]-'a']>1)return 3;
	if(cnt[r][s[r]-'a']-cnt[l-1][s[r]-'a']>1)return 3;
	if(mnnxtp[l]<=r)return 3;
	//answer 4
	return 4;
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	prework();
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",query(l,r));
	}
	return 0;
}