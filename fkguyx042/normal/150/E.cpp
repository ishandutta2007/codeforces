#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 100005
using namespace std;
const int inf=(int)1e9;
int i,j,m,n,p,k,fox[N],Q[N],k1,L,R,x,y,z,Max,ansx,ansy,idx,idy,Sum[N],Ql,Qr;
int vis[N],Rt[N],b[N],fa[N],size[N],Relx,deep[N],sum[N],Maxdeep[N];
int sky[N],id[N],Supper[N],Sup[N],Que[N],NowAns;
struct Node{
	   int ed,before,cost;
}s[N*2];
void add(int x,int y,int z)
{
	 s[++k1].ed=y; s[k1].before=fox[x]; fox[x]=k1; s[k1].cost=z;
}
int getroot(int x)
{ 
   Q[Q[0]=1]=x; Rt[x]=1; fa[x]=0; 
   for (int i=1;i<=Q[0];i++)
  {
       int p=Q[i];
       for (int j=fox[p];j;j=s[j].before)
       { 
            int A=s[j].ed;
             if (vis[A]||Rt[A]) continue;
            Q[++Q[0]]=A;
            fa[A]=p;
            Rt[A]=1;
       }
  }
  int A1=0,A2=1000000;
  for (int i=Q[0];i;i--)
{ 
    int p=Q[i]; size[p]=1; int Max=-1;
    for (int j=fox[p];j;j=s[j].before)
   { 
        int A=s[j].ed;
        if (vis[A]||fa[p]==A) continue;
        Max=max(Max,size[A]);
        size[p]+=size[A];
   }
   Max=max(Max,Q[0]-size[p]);
   if (Max<A2)
   { 
     A1=p; A2=Max; 
   }
}
for (int i=1;i<=Q[0];i++) Rt[Q[i]]=0;
return A1;
}
void bfs(int x)
{
	  int i,j;
   Q[Q[0]=1]=x; Rt[x]=1; deep[x]=0; sum[x]=0; fa[x]=0;
   for (i=1;i<=Q[0];i++)
   { 
      int p=Q[i];
      for (j=fox[p];j;j=s[j].before)
        if (!(vis[s[j].ed]||Rt[s[j].ed]))
        {   
              int A=s[j].ed;
              deep[A]=deep[p]+1;
              fa[A]=p;
              sum[A]=sum[p]+(s[j].cost>=Relx?1:-1);
              Q[++Q[0]]=A;
              Rt[A]=1;
        }
   }
      for (i=Q[0];i;--i)
      {
      	  Maxdeep[Q[i]]=deep[Q[i]];
          for (j=fox[Q[i]];j;j=s[j].before)
            if (fa[s[j].ed]==Q[i])
             Maxdeep[Q[i]]=max(Maxdeep[Q[i]],Maxdeep[s[j].ed]);
      }
      for(i=1;i<=Q[0];++i) Rt[Q[i]]=fa[Q[i]]=0;
}
inline bool cmp(int a,int b) { 
  return Maxdeep[a]<Maxdeep[b];
}
void checkin(int x)
{
	  int y=deep[x];
	  if (Supper[y]<sum[x]) Supper[y]=sum[x],Sup[y]=x;
}
int Get(int x)
{
	  int i,j;
   Q[Q[0]=1]=x; Rt[x]=1;
   for (i=1;i<=Q[0];i++)
   { 
      int p=Q[i]; checkin(p);
      for (j=fox[p];j;j=s[j].before)
        if (!(vis[s[j].ed]||Rt[s[j].ed]))
        {   
              int A=s[j].ed;
              Q[++Q[0]]=A;
              Rt[A]=1;
        }
   }
      for(i=1;i<=Q[0];++i) Rt[Q[i]]=fa[Q[i]]=0;
      return deep[Q[Q[0]]];
}
void Up(int x,int y,int z)
{
	  if (x>Max) 
	  {
	  	Max=x; idx=y; idy=z;
	  }
}
void insert(int x)
{
	  while (Ql<=Qr&&Sum[x]>Sum[Que[Qr]]) --Qr;
	  Que[++Qr]=x;
}
void Fen(int x)
{
	  int i,j;
	int root=getroot(x);
	vis[root]=1;
	int l=NowAns,r=b[0]+1,mid=0;
	while ((l+r)>>1!=mid)
{
	mid=(l+r)>>1;Max=-1; Relx=b[mid];
	bfs(root);
	sky[0]=0;
	for (i=fox[root];i;i=s[i].before)
	  if (!vis[s[i].ed]) sky[++sky[0]]=s[i].ed;
	sort(sky+1,sky+sky[0]+1,cmp);
	int realsum=0,nowl,reall;
	for (i=1;i<=sky[0];++i)
    { 
        reall=realsum;
        int Rec=Get(sky[i]);
        for (j=L;j<=R;++j) if (j>Rec) break;
        else Up(Supper[j],Sup[j],root);
        Ql=1,Qr=0;
        for (j=1;j<=Rec;++j)
        {
        	   while (reall&&reall+j>=L) insert(reall--);
        	   while (Ql<=Qr&&Que[Ql]+j>R) ++Ql;
        	   if (Ql>Qr) continue;
        	   Up(Sum[Que[Ql]]+Supper[j],Sup[j],id[Que[Ql]]);
		}
		for (j=1;j<=Rec;++j)
	    {
		    if (Sum[j]<Supper[j])
        	   {
        	   	  Sum[j]=Supper[j];
        	   	  id[j]=Sup[j];
			   }
			   Supper[j]=-inf;
		}
		realsum=Rec;
	}
	for (i=1;i<=realsum;++i) Sum[i]=-inf;
	if (Max>=0) { l=mid; ansx=idx; ansy=idy; }
	else r=mid;
}
  NowAns=l;
	for (i=fox[root];i;i=s[i].before)
	  if (!vis[s[i].ed]) Fen(s[i].ed);
}
int read()
{
      int x=0; char c;
      while (c=getchar(),(c<'0'||c>'9'));
      x=c-'0';
      while (c=getchar(),(c>='0'&&c<='9')) x=x*10+c-'0';
      return x;
}
int main()
{
	 scanf("%d%d%d",&n,&L,&R);
	 for (i=1;i<=n;++i) Sum[i]=Supper[i]=-inf;
	 for (i=1;i<n;++i)
	 {
	 	  x=read(); y=read(); z=read();
	 	  add(x,y,z); add(y,x,z);
	 	  b[++b[0]]=z;
	 }
	 sort(b+1,b+b[0]+1);
	 b[0]=unique(b+1,b+b[0]+1)-(b+1);
	 Fen(1);
	 printf("%d %d\n",ansx,ansy);
}