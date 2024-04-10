//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
const int Imx=2147483647;
const ll Lbg=2e18;
int mod;
struct matrix 
{
	int a[2][3];
	void init(){memset(a,0,sizeof(a));}
	void init1(){init();a[0][0]=a[1][1]=1;}
	matrix(){init();}
	matrix operator*(const matrix &t)const
	{
		matrix ret;
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<3;j++)
			{
				for(int k=0;k<2;k++)
				{
					ret.a[i][j]+=1ll*a[i][k]*t.a[k][j];
				}
				if(j==2)ret.a[i][j]+=a[i][2];
				ret.a[i][j]%=mod;
			}
		}
		return ret;
	}
	void out()
	{
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<3;j++)cout<<a[i][j]<<" ";cout<<endl;
		}
		cout<<endl;
	}
};
struct SGT
{
	matrix a[800111];
	void init(){for(int i=0;i<800111;i++)a[i].init1();}
	SGT(){init();}
	#define ls p<<1
	#define rs p<<1|1
	void change(int x,int v,int l,int r,int p=1)
	{
		if(x==l&&x==r)
		{
			a[p].init1();
			if(v!=-1)
			{
				a[p].a[0][0]=0;
				a[p].a[1][0]=a[p].a[0][1]=1;
				a[p].a[1][2]=v;
			}
			return;
		}
		int m=l+r>>1;
		if(x<=m)change(x,v,l,m,ls);
		else change(x,v,m+1,r,rs);
		a[p]=a[ls]*a[rs];
	}
	matrix query(int x,int y,int l,int r,int p=1)
	{
		if(x<=l&&r<=y)return a[p];
		int m=l+r>>1;
		if(x<=m&&m<y)return query(x,y,l,m,ls)*query(x,y,m+1,r,rs);
		else if(x<=m)return query(x,y,l,m,ls);
		else return query(x,y,m+1,r,rs);
	}
	matrix haru(){return a[1];}
	void out(int l,int r,int p=1)
	{
		cout<<l<<","<<r<<":"<<endl;
		a[p].out();
		if(l==r)return;
		int m=l+r>>1;
		out(l,m,ls);
		out(m+1,r,rs);
	}
}sora;
const int B=123;
int n,q,a[30011],id[30011];
vector<int>v;
struct query
{
	int l,r,id;
	bool operator<(const query &t)const
	{
		if(l/B!=t.l/B)return l<t.l;
		else return r<t.r;
	}
}qr[30011];
int cnt[30011],ans[30011];
void add(int x){if(!(cnt[id[x]]++))sora.change(id[x],a[x],1,n);}
void del(int x){if(!(--cnt[id[x]]))sora.change(id[x],-1,1,n);}
int main()
{
	scanf("%d%d",&n,&mod);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),v.PB(a[i]);
	sort(v.begin(),v.end());
	for(int i=1;i<=n;i++)id[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&qr[i].l,&qr[i].r);
		qr[i].id=i;
	}
	sort(qr+1,qr+q+1);
	int L=1,R=0;
	for(int i=1;i<=q;i++)
	{
		int l=qr[i].l,r=qr[i].r;
//		cout<<"-------l="<<l<<" r="<<r<<endl;
		while(R<r)add(++R);
		while(R>r)del(R--);
		while(L<l)del(L++);
		while(L>l)add(--L);
//		sora.out(1,n);
		matrix tmp=sora.haru();
//		tmp.out();
		ans[qr[i].id]=sora.haru().a[1][2];
	}
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
	return 0;
}