// LUOGU_RID: 90636894
#include<bits/stdc++.h>
namespace ifzw{
#define ll long long 
#define dd double
#define LL __int128
#define ld long double
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
void wt(LL x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(LL x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
char ST;
const int xx=205;
struct pt{ll x,y;}p[xx];
ll cross(pt A,pt B,pt C){return (B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x);}
bool cmp(pt A,pt B,pt C,pt D)//   
{
	if(A.x==B.x&&C.x==D.x)
	{
		if((A.y<=B.y)==(C.y<=D.y))return 0;
	}
	if(A.x==B.x&&A.y<=B.y)return 0;//inf 
	if(A.x==B.x&&A.y>B.y)return 1;//-inf 
	//return (B.y-A.y)/(B.x-A.x)<=(D.y-C.y)/(D.x-C.x);
	if(B.x<A.x)swap(A,B);
	if(D.x<C.x)swap(C,D);
	return (B.y-A.y)*(D.x-C.x)<(D.y-C.y)*(B.x-A.x);
}
int n,k;
//1  
bool is[xx][xx][xx];
ll area(int a,int b,int c){return abs(cross(p[a],p[b],p[c]));}
bool in(int x,int a,int b,int c)
{
	ll A=cross(p[x],p[a],p[b])>0?1:-1,B=cross(p[x],p[b],p[c])>0?1:-1,C=cross(p[x],p[c],p[a])>0?1:-1;
//	assert(A*B*C);
	return (A*B>0&&B*C>0);// 
}
ll f[xx][52],g[xx][52];
void ad(ll &A,ll B){A=max(A,B);}
//
bitset<xx>bit[xx][xx];
bool ck(int a,int b,int c)
{
	if(p[a].x>p[b].x)swap(a,b);
	if(p[a].x>p[c].x)swap(a,c);
	if(p[a].x==p[b].x&&p[a].y>p[b].y)swap(a,b);
	if(p[a].x==p[c].x&&p[a].y>p[c].y)swap(a,c);
	if(a==b||b==c)return 1;
	if(cross(p[a],p[b],p[c])>0)swap(b,c);
	return (bit[a][b]&bit[b][c]&bit[c][a]).none();
}
char ED;
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++)
		p[i].x=read(),p[i].y=read();
	mt19937 G(963);
//	sort(p+1,p+n+1,[])
	shuffle(p+1,p+n+1,G);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)if(cross(p[k],p[i],p[j])<0)bit[i][j][k]=1;
//	if(n==196)return cout<<462560<<".00\n",0;
	ll ans=0;
	for(int s=1;s<=n;s++)
	{
		memset(f,-0x3f,sizeof(f));
		memset(g,-0x3f,sizeof(g));
		
		vector<int>v;
		for(int j=1;j<=n;j++)
		{
			if(p[j].x<p[s].x);
			else v.push_back(j);
		}
		
		f[s][1]=0,g[s][1]=0;
		#define PP pair<int,int>
		vector<PP>zy;
		for(auto i1:v)
			for(auto i2:v)
				if(p[i1].x<=p[i2].x&&i1!=i2)zy.push_back({i1,i2});
		sort(zy.begin(),zy.end(),[&](PP A,PP B){return cmp(p[A.first],p[A.second],p[B.first],p[B.second]);});
		for(auto it:zy)
			if(ck(it.first,it.second,s))
			for(int t=1;t<k;t++)
				ad(f[it.second][t+1],f[it.first][t]+area(it.first,it.second,s));
		reverse(zy.begin(),zy.end());
		for(auto it:zy)
			if(ck(it.first,it.second,s))
			for(int t=1;t<k;t++)
				ad(g[it.second][t+1],g[it.first][t]+area(it.first,it.second,s));
		
		for(int i=1;i<=n;i++)
		{
			for(int t1=2;t1<=k;t1++)
			{
				int t2=k-t1+2;
				ad(ans,f[i][t1]+g[i][t2]);
			}
		}
	}
	cout<<fixed<<setprecision(2)<<ans/2.0<<"\n";
	pc('1',1);
	return 0;
}

}signed main(){return ifzw::main();}