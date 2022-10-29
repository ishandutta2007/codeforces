#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
const int Mo=998244353;
const int seed=133;
int i,j,m,n,p,k,x,y,flag,deep[300005],inv[300005],A,B,C,D,E,F,Log[300005],Two[25];
int H[700005];
char c[600005];
vector<int>v[300005];
int fa[300005][21],ans;
int Hash[300005][21],hash[300005][21];
void get(int x)
{ 
   int i,L=Log[deep[x]];
   for (i=1;i<=L;++i) fa[x][i]=fa[fa[x][i-1]][i-1];
      Hash[x][0]=hash[x][0]=(int)(c[x]-'a')+1;
    L=Log[deep[x]+1];
   for (i=1;i<=L;++i)
   {
   	   Hash[x][i]=(1ll*Hash[x][i-1]*inv[1<<(i-1)]%Mo+Hash[fa[x][i-1]][i-1])%Mo;
   	   hash[x][i]=(hash[x][i-1]+1ll*hash[fa[x][i-1]][i-1]*inv[1<<(i-1)]%Mo)%Mo;
   }
}
void dfs(int x)
{
	  int i;
	  get(x);
	  for (i=0;i<v[x].size();++i)
	    if (fa[x][0]!=v[x][i])
	    {
	    	 int p=v[x][i];
	    	 deep[p]=deep[x]+1;
	    	 fa[p][0]=x;
	    	 dfs(p);
	    }
}
int getlca(int x,int y)
{ 
 int i,k;
  if (deep[x]<deep[y]) swap(x,y);
  for (i=18,k=deep[x]-deep[y];i>=0;--i)
   if (k&Two[i]) x=fa[x][i];
   if (x==y) return x;
  for (i=18;i>=0;--i)
    if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
   return fa[x][0];
}
int kth(int x,int y)
{ 
     if (y<0) return -1;
     int i,K=Log[y];
     for (i=K;i>=0;--i) 
        if (y&Two[i]) x=fa[x][i];
     return x;
}
int gethash(int A,int B,int x)
{
	  int y=kth(B,deep[B]-(deep[A]+Two[x]-1));
	  return hash[y][x];
}
void cheat()
{ 
    int i,sum=0;
    int MaxL=Log[min(deep[A]+1,deep[C]+1)];
    int Ax=A,Cx=C;
    for (i=MaxL;i>=0;--i)
      if (Hash[Ax][i]==Hash[Cx][i])
      {
      	   Ax=fa[Ax][i]; Cx=fa[Cx][i]; sum+=Two[i];
      }
    sum=min(sum,min(deep[A]-deep[E],deep[C]-deep[F]));
    ans=sum; A=kth(A,sum); C=kth(C,sum);
    if (A!=E&&C!=F) flag=0;
    else if (A==E&&C==F) flag=2;
    else 
    { 
       if (C==F) swap(A,C),swap(B,D),swap(E,F);flag=1;
    }
}
void cheat_fi()
{
	    int i,sum=0;
	    if (flag!=1) return;
	    int MaxL=Log[min(deep[C]-deep[F],deep[B]-deep[A]+1)];
	    int Cx=C;
	    for (i=MaxL;i>=0;--i)
	      if (deep[Cx]-deep[F]>=Two[i])
	    {
           if (Hash[Cx][i]==gethash(A,B,i)) 
		   Cx=fa[Cx][i],A=kth(B,deep[B]-deep[A]-Two[i]),sum+=Two[i];
            if (A==-1) break;
        }
        if (A==-1) { ans+=sum; flag=0; return; }
        if (sum!=deep[C]-deep[F]) { ans+=sum; flag=0; return; }
        C=F; ans+=sum; flag=2;
} 
void cheat_sec()
{
	  int i,sum=0;
	  if (flag!=2) return;
	  int MaxL=Log[min(deep[D]-deep[C],deep[B]-deep[A])+1];
	  for (i=MaxL;i>=0;--i)
	  if (deep[B]-deep[A]+1>=Two[i]&&deep[D]-deep[C]+1>=Two[i])
	  {
	  	     if (deep[D]-deep[C]-Two[i]>=0&&deep[B]-deep[A]-Two[i]>=0)  
	  	     {
	  	     	    int Ax=kth(B,deep[B]-deep[A]-Two[i]);
	  	     	    int Bx=kth(D,deep[D]-deep[C]-Two[i]);
	  	     	    if (Hash[fa[Ax][0]][i]==Hash[fa[Bx][0]][i]) A=Ax,C=Bx,sum+=Two[i];
	  	     }
	  	     else
	  	    if (gethash(C,D,i)==gethash(A,B,i)) C=kth(D,deep[D]-deep[C]-Two[i]),A=kth(B,deep[B]-deep[A]-Two[i]),sum+=Two[i];
	  	    if (A==-1||C==-1) break;
	  }
	  ans+=sum;
}
inline int read()
{
	  int x=0; char c;
	  while (c=getchar(),c<'0'||c>'9');
	  x=c-'0';
	  while (c=getchar(),c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0';
	  return x;
}
void shi_()
{
    dfs(1);
    scanf("%d",&m);
    for (i=1;i<=m;++i)
    { 
        ans=0; flag=0;
        A=read(); B=read(); C=read();D=read();
        E=getlca(A,B); F=getlca(C,D);
        cheat();
        cheat_fi();
        cheat_sec();
        printf("%d\n",ans);
    }
}
int Get(int x,int y)
{
	  int Cx=(H[x+y-1]-1ll*H[x-1]*inv[y]%Mo+Mo)%Mo;
	  return Cx;
}
void Che() 
{
	  int i;
	  for (i=1;i<=n;++i) c[i+n]=c[n-i+1];
	  for (i=1;i<=2*n;++i) H[i]=(1ll*H[i-1]*seed%Mo+c[i]-'a'+1)%Mo;
	  scanf("%d",&m);
	  for (;m;m--)
	  {
	  	   A=read(); B=read(); C=read();D=read();
	  	   int LenA=abs(A-B)+1,LenB=abs(C-D)+1;
	  	   if (A>B) A=2*n-A+1; if (C>D) C=2*n-C+1;
	  	   if (c[A]!=c[C]) printf("0\n");
	  	   else 
	  	   {
	  	   	   int l=1,r=min(LenA,LenB)+1,mid=0;
	  	   	   for (;mid!=(l+r)>>1;)
	  	   	   {
	  	   	   	 mid=(l+r)>>1;
	  	   	   	 if (Get(A,mid)==Get(C,mid)) l=mid; else r=mid;
	  	   	   }
               printf("%d\n",l);
		  }
      }
}
int main()
{
	scanf("%d",&n); inv[0]=1;  for (i=1;i<=n;++i) inv[i]=1ll*inv[i-1]*seed%Mo; Log[0]=-1;
	Two[0]=1; for (i=1;i<=20;++i) Two[i]=Two[i-1]*2;
	for (i=1;i<=18;++i) Log[Two[i]]=i;
	for (i=2;i<=n;++i) if (!Log[i]) Log[i]=Log[i-1];
	scanf("%s",&c); for (i=n;i;--i) c[i]=c[i-1];
	for (i=1;i<n;++i)
	{ 
	   x=read(); y=read();
	   if (abs(x-y)>1) flag=1;
	   v[x].push_back(y); v[y].push_back(x);
    }
    int start=2;
    if (!flag) Che();
    else 
    shi_();
}