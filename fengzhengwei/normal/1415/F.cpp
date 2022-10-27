// LUOGU_RID: 90335979
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
//
// fij0/1  i  clone  j  i  j  
const int xx=5005;
int n;
struct nod{unsigned t;int x;}e[xx];
int id[xx];
unsigned f[xx][xx][2];
void ad(unsigned &a,unsigned b){a=min(a,b);}
char ED;
int main(){
//	cout<<sizeof(f)/1024/1024<<"$\n";// 191 
//	freopen("a.in","r",stdin);
	n=read();
	for(int i=1;i<=n;i++)
		e[i].t=read(),e[i].x=read();
	for(int i=1;i<=n;i++)id[i]=i;
	sort(id+1,id+n+1,[&](int a,int b){return e[a].x<e[b].x;});// i  t  id[i]  
//	memset(f,0x7f,sizeof(f));
	// ( 2e9 ) 
	for(int i=0;i<xx;i++)
		for(int j=0;j<xx;j++)
			f[i][j][0]=f[i][j][1]=2e9+1;
	f[0][0][0]=f[0][0][1]=0,id[0]=0;
	// ber  
	// C  i+1   max(a[i+1],reach j) -> f i+1 j 1 On  On  
	for(int i=0;i<=n;i++)
	{
		
//		for(int j=0;j<=n;j++)
//			for(int op=0;op<=1;op++)
//			{
//				if(f[i][j][op]>1e9)continue;
//				cout<<i<<" "<<j<<" "<<op<<" "<<f[i][j][op]<<"q\n";
//			}
		for(int j=0;j<=n;j++)// C   op =1  
		{
			for(int k=j-1;k>=0;k--)
			{
				if(f[i][id[k]][1]>f[i][id[j]][1]+abs(e[id[j]].x-e[id[k]].x))
					f[i][id[k]][1]=f[i][id[j]][1]+abs(e[id[j]].x-e[id[k]].x);
				else break;
			}
			for(int k=j+1;k<=n;k++)
			{
				if(f[i][id[k]][1]>f[i][id[j]][1]+abs(e[id[j]].x-e[id[k]].x))
					f[i][id[k]][1]=f[i][id[j]][1]+abs(e[id[j]].x-e[id[k]].x);
				else break;
			}
		}// On^2 
		for(int j=0;j<=n;j++)
		{
			for(int op=0;op<=1;op++)
			{
				if(f[i][j][op]>2e9)continue;
//				cout<<i<<" "<<j<<" "<<op<<" "<<f[i][j][op]<<"#\n";
				unsigned nt=f[i][j][op];int np=(op==0?e[i].x:e[j].x);// bot  
				if(j==i+1&&nt<=e[i+1].t)
				{
					if(i==n-1)return puts("YES"),0;
					for(int k=1;k<=n;k++)
					{
//						if(k==3)cerr<<nt<<" "<<np<<" "<<nt+abs(np-e[k].x)<<"   "<<e[k].x<<"@\n";
							ad(f[i+1][k][1],max(e[i+1].t,nt+abs(np-e[k].x)));
					}
					// bot  
				}
				else if(nt+abs(np-e[i+1].x)<=e[i+1].t)
				{
					if(i==n-1)return puts("YES"),0;
					ad(f[i+1][j][0],e[i+1].t);
					ad(f[i+1][i+1][1],e[i+1].t);
				}
			}
		}
	}
	puts("NO");
	pc('1',1);
	return 0;
}

}signed main(){return ifzw::main();}