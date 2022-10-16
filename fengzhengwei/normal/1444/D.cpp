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
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(ll x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(ll x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
char ST;
const int xx=1005;
int a[xx],b[xx],ua[xx],ub[xx];
#define pr pair<int,int>
#define fi first
#define se second
int fa[xx*xx],fb[xx*xx];
bitset<xx*xx>bit,lst,lin;
#define wa {puts("No");return;}
void run(int n,int *a,int *fa)
{
	bit.reset(),bit[0]=1;
	for(int i=1;i<=n;i++)
	{
		lst=bit,lst<<=a[i],lst|=bit;
		(lin=lst)^=bit;
		swap(lst,bit);
		for(int j=lin._Find_first();j!=xx*xx;j=lin._Find_next(j))fa[j]=i;
	}
}
int n,m;
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	m=read();
	for(int i=1;i<=m;i++)b[i]=read();
	if(n!=m)wa;
	for(int i=1;i<=n*xx;i++)fa[i]=0;
	for(int i=1;i<=m*xx;i++)fb[i]=0;
	int sum=0;
	for(int i=1;i<=n;i++)sum+=a[i];
	run(n,a,fa),run(m,b,fb);
	for(int i=1;i<=n;i++)ua[i]=0,ub[i]=0;
	if((sum&1)||!fa[sum/2])wa;
	int x=sum/2;
	while(x)ua[fa[x]]=1,x-=a[fa[x]];
	sum=0;
	for(int i=1;i<=m;i++)sum+=b[i];
	if((sum&1)||!fb[sum/2])wa;
	x=sum/2;
	while(x)ub[fb[x]]=1,x-=b[fb[x]];
	puts("Yes");
	vector<int>L,R,l,r;
	for(int i=1;i<=n;i++)if(ua[i]==0)L.push_back(a[i]);else R.push_back(a[i]);
	sort(L.begin(),L.end()),sort(R.begin(),R.end());
	if(L.size()>R.size())swap(L,R);
	for(int i=1;i<=n;i++)if(ub[i]==0)l.push_back(b[i]);else r.push_back(b[i]);
	sort(l.begin(),l.end(),[&](int a,int b){return a>b;}),sort(r.begin(),r.end(),[&](int a,int b){return a>b;});
	if(l.size()<r.size())swap(l,r);
	int nx=0,ny=0;
	int op=0;
	while(1)
	{
		if(op==0)
		{
			if(L.size())nx+=*--L.end(),L.pop_back();
			else if(R.size())nx-=*--R.end(),R.pop_back();
			else break;
		}
		else 
		{
			if(l.size())ny+=*--l.end(),l.pop_back();
			else if(r.size())ny-=*--r.end(),r.pop_back();
			else break;
		}
		cout<<nx<<" "<<ny<<"\n";
		op^=1;
	}
	
}
char ED;
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	int T=read();
	while(T--)solve();
	pc('1',1);
	return 0;
}