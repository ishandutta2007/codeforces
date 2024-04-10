// luogu-judger-enable-o2
#include<cstdio>
#include<cstring>
#include<algorithm>

typedef long long ll;

template<typename _Tp>void read(_Tp &x)
{
	register char ch=getchar();
	bool f=0;
	while(ch<48||ch>57) f|=ch=='-',ch=getchar();
	x=ch&15,ch=getchar();
	while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	if(f) x=-x;
}
const int N=100005;
const int block_size=550;
struct node{
	int val,num;
	inline bool operator < (const node &o)const{return val<o.val;}
	inline bool operator < (const int &o)const{return val<o;}
};
struct block{
	int l,r;
	node a[555];
	int pos,sum;
	ll tot;
	ll ans;
}f[555];
ll ttmp[N];
int bel[N<<2];
node tt[555];
int a[N<<2];
int b[N<<2];
ll t[N<<2];
int pos;
int opt[N],l[N],r[N];
int block_sum;
void build(int len)
{
	int tmp=block_size,cur=0;
	for(int i=1;i<=len;++i)
	{
		++tmp;
		if(tmp>block_size)
		{
			f[cur].r=i-1;
			tmp=1;
			++cur;
			f[cur].l=i;
		}
		bel[i]=cur;
	}
	block_sum=cur;
	f[cur].r=len;
	for(int i=1;i<=cur;++i)
	{
		for(int j=f[i].l;j<=f[i].r;++j)
		{
			if(b[j])
			{
				f[i].a[++f[i].pos]=(node){j,b[j]};
				f[i].sum+=b[j];
				f[i].tot+=1ll*t[j]*b[j];
			}
		}
		ll sum=0;
		for(int j=1;j<=f[i].pos;++j)
		{
			f[i].ans+=1ll*t[f[i].a[j].val]*sum*f[i].a[j].num;
			sum+=f[i].a[j].num;
		}
		sum=0;
		for(int j=f[i].pos;j>=1;--j)
		{
			f[i].ans-=1ll*t[f[i].a[j].val]*sum*f[i].a[j].num;
			sum+=f[i].a[j].num;
		}
	}
}
ll solve1(int l,int r)
{
	int Pos=0;
	for(int i=l;i<=r;++i)
	{
		if(b[i])
		{
			tt[++Pos]=(node){i,b[i]};
		}
	}
	ll sum=0;
	ll ans=0;
	for(int i=1;i<=Pos;++i)
	{
		ans+=sum*t[tt[i].val]*tt[i].num;
		sum+=tt[i].num;
	}
	sum=0;
	for(int i=Pos;i>=1;--i)
	{
		ans-=sum*t[tt[i].val]*tt[i].num;
		sum+=tt[i].num;
	}
	return ans;
}
void rebuild1(int cur,int pre)
{
	--f[cur].sum;
	f[cur].tot-=t[pre];
	int p=std::lower_bound(f[cur].a+1,f[cur].a+f[cur].pos+1,pre)-f[cur].a;
	--f[cur].a[p].num;
	if(!f[cur].a[p].num)
	{
		for(int i=p;i<f[cur].pos;++i)
		{
			f[cur].a[i]=f[cur].a[i+1];
		}
		--f[cur].pos;
	}
//	int tmp=t[pre];
//	ll sum=0;
//	for(int i=1;i<p;++i)
//	{
//		sum+=f[cur].a[i].num;
//	}
//	f[cur].ans-=sum*tmp;
//	int T=p+1;
//	if(!f[cur].a[p].num)
//	{
//		for(int i=p;i<f[cur].pos;++i)
//		{
//			f[cur].a[i]=f[cur].a[i+1];
//		}
//		--f[cur].pos;
//		--T;
//	}
//	sum=0;
//	for(int i=T;i<=f[cur].pos;++i)
//	{
//		sum+=f[cur].a[i].num;
//	}
//	f[cur].ans+=sum*tmp;
	f[cur].ans=solve1(f[cur].l,f[cur].r);
}
void rebuild2(int cur,int now)
{
	++f[cur].sum;
	f[cur].tot+=t[now];
	int p=std::lower_bound(f[cur].a+1,f[cur].a+f[cur].pos+1,now)-f[cur].a;
	if(f[cur].a[p].val==now)
	{
		++f[cur].a[p].num;
	}
	else
	{
		for(int i=f[cur].pos+1;i>=p+1;--i)
		{
			f[cur].a[i]=f[cur].a[i-1];
		}
		++f[cur].pos;
		f[cur].a[p]=(node){now,1};
	}
	f[cur].ans=solve1(f[cur].l,f[cur].r);
//	int tmp=t[now];
//	ll sum=0;
//	for(int i=1;i<p;++i)
//	{
//		sum+=f[cur].a[i].num;
//	}
//	f[cur].ans+=sum*tmp;
//	sum=0;
//	for(int i=p+1;i<=f[cur].pos;++i)
//	{
//		sum+=f[cur].a[i].num;
//	}
//	f[cur].ans-=sum*tmp;
}
void Update(int pre,int now)
{
	--b[pre],++b[now];
	rebuild1(bel[pre],pre);
	rebuild2(bel[now],now);
}
ll Query(int l,int r)
{
//	for(int i=1;i<=block_sum;++i)
//	{
//		for(int j=1;j<=f[i].pos;++j)
//		{
//			for(int k=1;k<=f[i].a[j].num;++k)
//			{
//				printf("%d ",f[i].a[j].val);
//			}
//		}
//	}
//	printf("\n");
//	for(int i=1;i<=block_sum;++i)
//	{
//		printf("[%d,%d] %d %lld\n",f[i].l,f[i].r,f[i].sum,f[i].tot);
//	}
	if(bel[l]==bel[r])
	{
		return solve1(l,r);
	}
	ll cnt1=0,cnt2=0;
	ll ans=0;
	for(int i=l;i<=f[bel[l]].r;++i)
	{
		cnt1+=b[i];
	}
	ans+=solve1(l,f[bel[l]].r);
	for(int i=f[bel[r]].l;i<=r;++i)
	{
		cnt2+=b[i];
	}
	ans+=solve1(f[bel[r]].l,r);
	for(int i=bel[l]+1;i<bel[r];++i)
	{
		ans+=cnt1*f[i].tot;
		ans+=f[i].ans;
		cnt1+=f[i].sum;
	}
	for(int i=f[bel[r]].l;i<=r;++i)
	{
		if(b[i])
		{
			ans+=cnt1*t[i]*b[i];
		}
	}
	for(int i=bel[r]-1;i>bel[l];--i)
	{
		ans-=cnt2*f[i].tot;
		cnt2+=f[i].sum;
	}
	for(int i=l;i<=f[bel[l]].r;++i)
	{
		if(b[i])
		{
			ans-=cnt2*t[i]*b[i];
		}
	}
	return ans;
}
int main()
{
//    freopen("point.in","r",stdin);
//    freopen("point.out","w",stdout);
	int n;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		ttmp[i]=a[i];
		t[++pos]=a[i];
	}
	int _;
	read(_);
	for(int i=1;i<=_;++i)
	{
		read(opt[i]);
		read(l[i]);
		read(r[i]);
		if(opt[i]==1)
		{
			ttmp[l[i]]+=r[i];
			t[++pos]=ttmp[l[i]];
			r[i]=ttmp[l[i]];
		}
		else
		{
			t[++pos]=l[i];
			t[++pos]=r[i];
		}
	}
	std::sort(t+1,t+pos+1);
	int len=std::unique(t+1,t+pos+1)-t-1;
	for(int i=1;i<=n;++i)
	{
		a[i]=std::lower_bound(t+1,t+len+1,a[i])-t;
		++b[a[i]];
	}
	for(int i=1;i<=_;++i)
	{
		if(opt[i]==1)
		{
			r[i]=std::lower_bound(t+1,t+len+1,r[i])-t;
		}
		else
		{
			l[i]=std::lower_bound(t+1,t+len+1,l[i])-t;
			r[i]=std::lower_bound(t+1,t+len+1,r[i])-t;
		}
	}
	build(len);
	for(int i=1;i<=_;++i)
	{
		if(opt[i]==1)
		{
			Update(a[l[i]],r[i]);
			a[l[i]]=r[i];
		}
		else
		{
			printf("%lld\n",Query(l[i],r[i]));
		}
	}
	return 0;
}
/*
5 
-1 -10 -5 7 7
5
1 2 -5
2 -3 10
1 3 3
2 3 10
1 3 6

8+17+12+8+17+12+4+5+9

*/