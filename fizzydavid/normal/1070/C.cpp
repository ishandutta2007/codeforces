// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

LL bit1[1100111],bit2[1100111];
void add(int p,int v)
{
	for(int x=p;x<1100111;x+=x&-x)
	{
		bit1[x]+=v;
		bit2[x]+=(LL)p*v;
	}
}
LL query(int k)
{
	int cur=0;
	LL ret=0;
	for(int i=19;i>=0;i--)
	{
		if(bit1[cur|(1<<i)]<k)
		{
			k-=bit1[cur|(1<<i)];
			ret+=bit2[cur|(1<<i)];
			cur|=(1<<i);
		}
	}
	if(cur<=1000000)ret+=(LL)(cur+1)*k;
	return ret;
}

int n,k,m,p[1000111],v[1000111];
LL ans;
vector<int> vl[1000111],vr[1000111];
int main()
{
	get3(n,k,m);
	for(int i=1,l,r;i<=m;i++)
	{
		get2(l,r);get2(v[i],p[i]);
		vl[l].pb(i);vr[r+1].pb(i);
	}
	for(int i=1;i<=n;i++)
	{
		for(auto&id:vl[i])add(p[id],v[id]);
		for(auto&id:vr[i])add(p[id],-v[id]);
		ans+=query(k);
	}
	printendl(ans);
	return 0;
}