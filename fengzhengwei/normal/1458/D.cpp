#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC target("avx")
#include<bits/stdc++.h>
#define ll long long
#define dd double
#define LL __int128
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
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout));
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
mt19937 fhq_random(218);
int op;
template<int nd>struct fhq_val
{
	void split_s(int k,int a,int &x,int &y)
	{
		if(!k)return x=y=0,void();
		pd(k);
		if(siz[c[k][0]]+1<=a)x=k,split_s(c[k][1],a-siz[c[k][0]]-1,c[k][1],y);
		else y=k,split_s(c[k][0],a,x,c[k][0]);
		upd(k);
	}
	int merge(int x,int y)
	{
		if(!x||!y)return x+y;
		pd(x),pd(y);
		if(rd[x]<rd[y])return c[x][1]=merge(c[x][1],y),upd(x),x;
		return c[y][0]=merge(x,c[y][0]),upd(y),y;
	}
	void print(int k)
	{
		puts("Out the Fhq ");
		pr(k);
		puts("");
		puts("End");
	}
	//val 
	unsigned int rd[nd];
	int c[nd][2],siz[nd],cst;
	void pr(int k)
	{
		pd(k); 
		if(c[k][0])pr(c[k][0]);
//		cerr<<sum[k]<<" ";
		if(c[k][1])pr(c[k][1]);
	}
	struct nod{int n,x,s,v,i,L,R;}e[nd];
	int ft[nd],rt[nd];
	nod em;
	nod upd(const nod&A,const nod&B){return !A.L?B:!B.L?A:(nod){min(A.n,A.s+B.n),max(A.x,A.s+B.x),A.s+B.s,0,0,A.L,B.R};}
	nod gone(int v,int i){return {min(0,v),max(0,v),v,v,i,i,i};}
	void cks(int k){e[k].i=e[k].L+siz[c[k][0]];}
	void upd(int k)
	{
		if(!k)return;
		siz[k]=siz[c[k][0]]+siz[c[k][1]]+1;
		int v=e[k].v,i=e[k].i;
		e[k]=gone(e[k].v,e[k].i);
		if(c[k][0])e[k]=upd(e[c[k][0]],e[k]);
		if(c[k][1])e[k]=upd(e[k],e[c[k][1]]);
		e[k].v=v,e[k].i=i;
		cks(k);
//		cerr<<k<<" "<<c[k][1]<<" "<<e[0].R<<" "<<e[6].R<<" "<<e[6].i<<" "<<e[1].L<<" "<<e[1].R<<"BBB\n";
//		cerr<<k<<" "<<c[k][1]<<" "<<e[k].L<<" "<<e[k].R<<" "<<e[k].i<<" "<<e[k].s<<" "<<e[k].n<<" "<<e[k].x<<"BBB\n";
	}
	int Nw(int v,int i)
	{
		++cst,e[cst]=gone(v,i),ft[cst]=rt[cst]=0,siz[cst]=1,c[cst][0]=c[cst][1]=0,rd[cst]=fhq_random();
		return cst;
	}
	void flip(int k)
	{
		e[k].s*=-1,e[k].v*=-1;
		swap(e[k].n,e[k].x),e[k].n*=-1,e[k].x*=-1;
		ft[k]^=1;
	}
	void ck(int k,int B)
	{
		if(!k)return;
		//swap  
		e[k].L=B,e[k].R=B+siz[k]-1;
		cks(k);
	}
	void reverse(int k)
	{
		swap(c[k][0],c[k][1]);
		cks(k);//What  
		ck(c[k][0],e[k].L),ck(c[k][1],e[k].i+1);
		swap(e[k].n,e[k].x),e[k].n=e[k].s-e[k].n,e[k].x=e[k].s-e[k].x;
		rt[k]^=1;
	}
	void pd(int k)
	{
		cks(k);//What  
		ck(c[k][0],e[k].L),ck(c[k][1],e[k].i+1);
		if(ft[k])flip(c[k][0]),flip(c[k][1]),ft[k]=0;
		if(rt[k])reverse(c[k][0]),reverse(c[k][1]),rt[k]=0;
	}
	nod nw;
	int bind(int k,int l,int lim)
	{
		if(!k)return -1;// 
		if(e[k].R<l)return nw=em,e[k].R+1;
		pd(k);
		if(e[k].i<l)return bind(c[k][1],l,lim);
//		if(op)cerr<<k<<" "<<c[k][0]<<" "<<c[k][1]<<" "<<e[k].i<<" "<<e[k].L<<" "<<e[k].R<<" "<<l<<" "<<e[k].n<<" "<<e[k].s<<" "<<e[k].x<<" "<<lim<<" "<<nw.s<<" "<<upd(nw,e[k]).n<<" "<<nw.n<<"$1\n";
		if(l<=e[k].L&&upd(nw,e[k]).n>lim)return nw=upd(nw,e[k]),e[k].R+1;
//		cerr<<k<<" "<<c[k][0]<<" "<<c[k][1]<<" "<<e[k].i<<" "<<e[k].L<<" "<<e[k].R<<" "<<e[k].n<<" "<<e[k].s<<" "<<e[k].x<<" "<<lim<<" "<<nw.s<<" "<<upd(nw,e[k]).n<<" "<<nw.n<<"$2\n";
		int A=bind(c[k][0],l,lim);
//		if(op)cerr<<A<<" "<<e[c[k][0]].L<<" "<<e[k].L<<" "<<siz[c[k][0]]<<" "<<e[c[k][0]].R<<"%%%\n";
//		cerr<<k<<" "<<c[k][0]<<" "<<c[k][1]<<" "<<e[k].i<<" "<<e[k].L<<" "<<e[k].R<<" "<<e[k].n<<" "<<e[k].s<<" "<<e[k].x<<" "<<lim<<" "<<nw.s<<" "<<upd(nw,e[k]).n<<" "<<nw.n<<"$3\n";
		if(!c[k][0]||A==e[k].i)
		{
//		cerr<<k<<" "<<c[k][0]<<" "<<c[k][1]<<" "<<e[k].i<<" "<<e[k].L<<" "<<e[k].R<<" "<<e[k].n<<" "<<e[k].s<<" "<<e[k].x<<" "<<lim<<" "<<nw.s<<" "<<upd(nw,e[k]).n<<" "<<nw.n<<"$\n";
			nw=upd(nw,gone(e[k].v,e[k].i));
//			cerr<<e[k].v<<"%^%^%^%^%^%^%^\n";
//		cerr<<k<<" "<<c[k][0]<<" "<<c[k][1]<<" "<<e[k].i<<" "<<e[k].L<<" "<<e[k].R<<" "<<e[k].n<<" "<<e[k].s<<" "<<e[k].x<<" "<<lim<<" "<<nw.s<<" "<<nw.n<<" "<<"q\n";
			if(nw.n<=lim)return e[k].i;
			if(c[k][1])return bind(c[k][1],l,lim);
			return e[k].R+1;
		}
		return A;
	}
	int binu(int k,int l,int lim)
	{
		int A=0;
		flip(k),A=bind(k,l,-lim),flip(k);
		return A;
	}
	void on(int &k,int l,int r)
	{
		int A,B,C;
		split_s(k,l-1,A,B);
		split_s(B,r-l+1,B,C);
		flip(B),reverse(B);
		k=merge(A,merge(B,C));
	}
	int gg(int &k,int l)
	{
		if(siz[c[k][0]]+1==l)return e[k].v;
		pd(k);
		if(siz[c[k][0]]>=l)return gg(c[k][0],l);
		return gg(c[k][1],l-siz[c[k][0]]-1);
	}
//	int gg(int &k,int l,int r)
//	{
//		int A,B,C;
//		split_s(k,l-1,A,B);
//		split_s(B,r-l+1,B,C);
//		int ans=e[B].v;
//		k=merge(A,merge(B,C));
//		return ans;
//	}
};
const int xx=1e6+5;
fhq_val<xx>f;
//
// -2  1 
char s[xx],c[xx];
char ED;
int main(){
//	cerr<<abs(&ST-&ED)/1024.0/1024<<"\n";
//	freopen("a.in","w",stdout);
//	cout<<2<<"\n";
//	for(int i=1;i<=500000;i++)cout<<(fhq_random()&1);
//	puts("");
//	for(int i=1;i<=500000;i++)cout<<(fhq_random()&1);
//	puts("");
//	exit(0);
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	int T;
	cin>>T;
	f.cst=0;
	while(T--)
	{
		f.cst=0;
		scanf("%s",s+1);
		int n=strlen(s+1),rt=0;
		for(int i=1;i<=n;i++)rt=f.merge(rt,f.Nw((s[i]=='1')-(s[i]=='0'),i));
//		cerr<<rt<<"$\n";
		for(int i=1;i<=n;i++)
		{
			int v=f.gg(rt,i);
			if(v==-1)c[i]='0';
			else 
			{
//				if(i==399)op=1;
//				cout<<i<<"@\n";
				c[i]='1';
				f.nw={};
				int ty=f.bind(rt,i,-1);
//				cerr<<ty<<"$$\n";
				if(ty+1<=n)
				{
					f.nw={};
					ty=f.binu(rt,ty+1,1);
//					cerr<<ty<<"qqqq $$\n";
					if(ty<=n)/*cerr<<i<<" "<<ty<<"!!!!!!!!!!!!!!!!\n",*/c[i]='0',f.on(rt,i,ty);
				}
//				if(i==399)exit(0);
			}
//			if(i==2)exit(0);
		}
		c[n+1]=0;
		cout<<c+1<<"\n";
	}
	pc('1',1);
	return 0;
}