#include<cstdio>
#include<algorithm>
#define N 1<<18
#define O 1<<21
char in[O],*S=in;
char ch;bool f;void re(int& x)
{
	while(ch=*S++,ch<33);
	if(ch=='-')f=1,x=0;else f=0,x=ch-48;
	while(ch=*S++,33<ch)x=(x<<1)+(x<<3)+ch-48;
	if(f)x=-x;
}
char out[O],*T=out;
void divide(int x)
{
    if(x<10)
    {
        *T++=x+48;
        return;
    }
    divide(x/10);
    *T++=x%10+48;
}
using namespace std;
int n,m,l[N],r[N],s[100001];
int top,st[333];
bool rev[N];
struct node
{
	int m,ml,mr,sum;
	int l,r,pl,pr;
	void set(int x){m=ml=mr=sum=s[x];l=r=pl=pr=x;}
	void fix(){m=-m,ml=-ml,mr=-mr,sum=-sum;}
	node operator + (const node& a)const
	{
		node tmp=
		{
			mr+a.ml,
			ml,a.mr,
			sum+a.sum,
			pr,a.pl,
			pl,a.pr
		};
		if(tmp.m < m)tmp.m=m,tmp.l=l,tmp.r=r;
		if(tmp.m < a.m)tmp.m=a.m,tmp.l=a.l,tmp.r=a.r;
		if(tmp.ml < sum+a.ml)tmp.ml=sum+a.ml,tmp.pl=a.pl;
		if(tmp.mr < a.sum+mr)tmp.mr=a.sum+mr,tmp.pr=pr;
		return tmp;		
	}
}mx[N],mn[N];
void upd(int k)
{
	mx[k]=mx[k<<1]+mx[k<<1|1];
	mn[k]=mn[k<<1]+mn[k<<1|1];	
}
void push(int k)
{
	if(rev[k])
	{
		rev[k]=0,rev[k<<1]^=1,rev[k<<1|1]^=1;
		swap(mx[k<<1],mn[k<<1]);
		swap(mx[k<<1|1],mn[k<<1|1]);
	}
}
void build(int k,int a,int b)
{
	l[k]=a,r[k]=b;
	if(a == b)
	{
		mx[k].set(a);
		mn[k].set(a);
		mn[k].fix();
		return;
	}
	build(k<<1,a,a+b>>1);
	build(k<<1|1,(a+b>>1)+1,b);
	upd(k);
}
void change(int k,int a)
{
	if(l[k] == r[k])
	{
		mx[k].set(a);
		mn[k].set(a);
		mn[k].fix();
		return;
	}
	push(k);
	if(a <= l[k]+r[k]>>1)change(k<<1,a);
	else change(k<<1|1,a);
	upd(k);
}
void rever(int k,int a,int b)
{
	if(a>r[k] || b<l[k])return;
	if(a<=l[k] && b>=r[k])
	{
		rev[k]^=1;st[++top]=k;
		swap(mx[k],mn[k]);
		return;
	}
	push(k);
	rever(k<<1,a,b);
	rever(k<<1|1,a,b);
	upd(k);
}
node solmx(int k,int a,int b)
{
	if(a<=l[k] && b>=r[k])return mx[k];
	int mid=l[k]+r[k]>>1;push(k);
	if(b <= mid)return solmx(k<<1,a,b);
	if(a > mid)return solmx(k<<1|1,a,b);
	return solmx(k<<1,a,b)+solmx(k<<1|1,a,b);
}
int main()
{
	fread(in,1,O,stdin);
	re(n);
	for(int i=1;i<=n;++i)re(s[i]);
	build(1,1,n);
	re(m);
	int opt,a,b,c,ans;
	node tmp;
	while(m--)
	{
		re(opt),re(a),re(b);
		if(opt)
		{
			re(c);ans=0;
			while(c--)
			{
				tmp=solmx(1,a,b);
				if(tmp.m <= 0)break;
				ans+=tmp.m;
				rever(1,tmp.l,tmp.r);
			}
			while(top)
			{
				c=st[top];
				rev[c]^=1;
				swap(mx[c],mn[c]);
				while(c>>=1)upd(c);
				--top;
			}
			divide(ans);
			*T++='\n';
		}
		else s[a]=b,change(1,a);
	}
	fwrite(out,1,T-out,stdout);
}