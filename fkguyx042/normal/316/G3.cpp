#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>

#define maxlen 600000
#define N 600005
#define M 20

using namespace std;
long long ans;
int i,j,m,n,p,k,len,r,Q[N],lx[N],rx[N],lenx[N],Belong[N],L,Sum[15][N],Ansl[N],Ansr[N],Ans[N],x,id[N];
int st[M][N];
char c[N],s[N];
int sa[N],rank[N],sum[N],Trk[N],Orz[N],high[N],Pow[M],Log[N*2];
int getmin(int x,int y)
{
	  if (x==y) return (int)1e9;
	  if (x>y) swap(x,y);
	  ++x; int i=Log[y-x+1];
	  return min(st[i][x],st[i][y-Pow[i]+1]);
}
void Sort(int j)
{  memset(sum,0,sizeof(sum));
   for (i=1;i<=len;i++) sum[rank[i+j]]++;
   for (i=1;i<=maxlen;i++) sum[i]+=sum[i-1];
   for (i=len;i;i--)
     Orz[sum[rank[i+j]]--]=i;
   memset(sum,0,sizeof(sum));
   for (i=1;i<=len;i++) sum[rank[i]]++;
   for (i=1;i<=maxlen;i++) sum[i]+=sum[i-1];
   for (i=len;i;i--)
   sa[sum[rank[Orz[i]]]--]=Orz[i];
} 
void get_High()
{  int i,j;
   for (i=1,j=0;i<=len;i++)
   {  if (rank[i]==1) continue;
      while (c[i+j]==c[sa[rank[i]-1]+j]) j++;
      high[rank[i]]=j; if (j>0) j--;
}
}
void get_SA()
{  int i,j,p;
   for (i=1;i<=len;i++) Trk[i]=c[i];
   for (i=1;i<=len;i++) sum[Trk[i]]++;
   for (i=1;i<=maxlen;i++) sum[i]+=sum[i-1];
   for (i=len;i;i--) sa[sum[Trk[i]]--]=i; 
   rank[sa[1]]=1;
   for (i=2,p=1;i<=len;i++) 
   {  if (Trk[sa[i]]!=Trk[sa[i-1]]) p++;
        rank[sa[i]]=p;
   }
   for (j=1;j<=len;j*=2) {
     Sort(j);
    Trk[sa[1]]=1;
    for (i=2,p=1;i<=len;i++)
    {  if (rank[sa[i]]!=rank[sa[i-1]]||rank[sa[i]+j]!=rank[sa[i-1]+j]) p++;
       Trk[sa[i]]=p;
    }
    for (i=1;i<=len;i++) rank[i]=Trk[i];
}
}

void pre()
{
	 int i,j;
	 for (i=1;i<=len;++i) st[0][i]=high[i];
	 for (i=1;i<M;++i)
	   for (j=1;j<=len;++j)
	       if (j+Pow[i]-1<=len)
	          st[i][j]=min(st[i-1][j],st[i-1][j+Pow[i-1]]);
}
void check(int x,int id)
{
	  int l=1,r=id,mid=0;
	  while ((l+r)>>1!=mid)
	  {
	  	 mid=(l+r)>>1;
	  	 if (getmin(mid,id)>=x) r=mid; else l=mid;
	  }
	  int nel=r,ner;
	  l=1,r=id,mid=0;
	  l=id,r=len+1;
	  while ((l+r)>>1!=mid)
	  {
	  	 mid=(l+r)>>1;
	  	 if (getmin(id,mid)>=x) l=mid; else r=mid;
	  }
	  ner=l;
	  int i;
	  for (i=1;i<=n;++i) Ans[i]=Sum[i][ner]-Sum[i][nel-1];
}
inline bool cmp(int a,int b) { return rank[a]<rank[b]; }
int main()
{ 
   scanf("%s",c);  Pow[0]=1; for (i=1;i<M;++i) Pow[i]=Pow[i-1]*2,Log[Pow[i]]=i;
   for (i=2;i<N;++i) if (!Log[i]) Log[i]=Log[i-1]; 
   len=strlen(c);  L=len;
   for (i=len;i;--i) c[i]=c[i-1]; c[0]='@';
   c[++len]='$'; 
   for (i=0;i<len;++i) Belong[i+1]=-1;
   scanf("%d",&n);
   for (i=1;i<=n;++i)
   {
   	  scanf("%s",s);
   	  scanf("%d%d",&lx[i],&rx[i]);
   	  lenx[i]=strlen(s);
   	  for (j=0;j<lenx[i];++j) Belong[++len]=i,c[len]=s[j];
   	  c[++len]='$';
   }
   get_SA(); get_High(); pre();
   for (i=1;i<=n;++i) for (j=1;j<=len;++j) Sum[i][j]=Sum[i][j-1]+(Belong[sa[j]]==i);
   for (i=1;i<=L;++i)
   {
   	   int l=0,r=L-i+2,mid=0;
   	   for (;(l+r)>>1!=mid;)
   	   {
   	   	  mid=(l+r)>>1;
   	   	  check(mid,rank[i]);
   	   	  for (j=1;j<=n;++j) if (Ans[j]<lx[j]) break;
   	   	  if (j>n) l=mid; else r=mid;
   	   }
   	   Ansr[i]=l;
   	   l=0,r=L-i+2,mid=0;
   	   while ((l+r)>>1!=mid)
   	   {
   	   	  mid=(l+r)>>1;
   	   	  check(mid,rank[i]);
   	   	  for (j=1;j<=n;++j) if (Ans[j]>rx[j]) break;
   	      if (j>n) r=mid; else l=mid;
   	  }
   	  Ansl[i]=max(1,r);
   }
   for (i=1;i<=L;++i) id[i]=i;
   sort(id+1,id+L+1,cmp);
   ans+=max(0,Ansr[id[1]]-Ansl[id[1]]+1);
   for (i=2;i<=L;++i)
   {
   	 x=getmin(rank[id[i]],rank[id[i-1]]);
   	 if (Ansl[id[i]]>Ansr[id[i]]) continue;
   	 ans+=Ansr[id[i]]-Ansl[id[i]]+1;
   	 if (Ansl[id[i-1]]>Ansr[id[i-1]]) continue;
   	 if (Ansl[id[i]]<=Ansr[id[i-1]]&&Ansl[id[i-1]]<=Ansr[id[i]])
   	 {
   	   int samel=max(Ansl[id[i]],Ansl[id[i-1]]);
   	   int samer=min(Ansr[id[i]],Ansr[id[i-1]]);
   	   if (samel<=x) ans-=min(samer,x)-samel+1;
     }
   }
   cout<<ans<<endl;
}