#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 700005

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

using namespace std;
const int maxlen=700000;
int i,j,m,n,p,k,len;
char c[N],s[N];
int sa[N],Rank[N],sum[N],Trk[N],Orz[N],high[N],x,val[N];
int str[N],End[N],Min[N*4],Max[N];
long long Ans[N*4],ans;
void Sort(int j)
{  memset(sum,0,sizeof(sum));
   for (i=1;i<=len;i++) sum[Rank[i+j]]++;
   for (i=1;i<=maxlen;i++) sum[i]+=sum[i-1];
   for (i=len;i;i--)
     Orz[sum[Rank[i+j]]--]=i;
   memset(sum,0,sizeof(sum));
   for (i=1;i<=len;i++) sum[Rank[i]]++;
   for (i=1;i<=maxlen;i++) sum[i]+=sum[i-1];
   for (i=len;i;i--)
   sa[sum[Rank[Orz[i]]]--]=Orz[i];
} 
void get_High()
{  int i,j;
   for (i=1,j=0;i<=len;i++)
   {  if (Rank[i]==1) continue;
      while (c[i+j]==c[sa[Rank[i]-1]+j]) j++;
      high[Rank[i]]=j; if (j>0) j--;
}
}
void get_SA()
{  int i,j,p,k;
   for (i=1;i<=len;i++) Trk[i]=c[i];
   for (i=1;i<=len;i++) sum[Trk[i]]++;
   for (i=1;i<=maxlen;i++) sum[i]+=sum[i-1];
   for (i=len;i;i--) sa[sum[Trk[i]]--]=i; 
   Rank[sa[1]]=1;
   for (i=2,p=1;i<=len;i++) 
   {  if (Trk[sa[i]]!=Trk[sa[i-1]]) p++;
        Rank[sa[i]]=p;
   }
   for (j=1;j<=len;j*=2) {
     Sort(j);
    Trk[sa[1]]=1;
    for (i=2,p=1;i<=len;i++)
    {  if (Rank[sa[i]]!=Rank[sa[i-1]]||Rank[sa[i]+j]!=Rank[sa[i-1]+j]) p++;
       Trk[sa[i]]=p;
    }
    for (i=1;i<=len;i++) Rank[i]=Trk[i];
    j++;j--;
}
}
void build_tree(int l,int r,int t)
{
	 if (l==r) Min[t]=high[l],Ans[t]=val[sa[l]];
	 else 
	 {
	 	   build_tree(l,mid,ls); build_tree(mid+1,r,rs);
	 	   Min[t]=min(Min[ls],Min[rs]); Ans[t]=Ans[ls]+Ans[rs];
	 }
}
long long ask(int ll,int rr,int l,int r,int t)
{
	  if (ll<=l&&r<=rr) return Ans[t];
	  long long sum=0;
	  if (ll<=mid) sum+=ask(ll,rr,l,mid,ls);
	  if (rr>mid)  sum+=ask(ll,rr,mid+1,r,rs);
	  return sum;
}
int Findr(int l,int r,int t)
{
	  if (l==r) return l;
	  if (Min[ls]<p) return Findr(l,mid,ls);
	  return Findr(mid+1,r,rs);
}
int askr(int ll,int rr,int l,int r,int t)
{
	  if (Min[t]>=p) return 0;
	  if (ll<=l&&r<=rr) return Findr(l,r,t);
	  else 
	  {
	  	    int rt;
		    if (ll<=mid)
		    {
		    	rt=askr(ll,rr,l,mid,ls);
		    	if (rt) return rt;
		    }
		    if (rr>mid)
			{
			    rt=askr(ll,rr,mid+1,r,rs);
				if (rt) return rt;
		    }
		    return 0;
	   }
}
int Findl(int l,int r,int t)
{
	  if (l==r) return l;
	  if (Min[rs]<p) return Findl(mid+1,r,rs);
	  return Findl(l,mid,ls);
}
int askl(int ll,int rr,int l,int r,int t)
{
	  if (Min[t]>=p) return 0;
	  if (ll<=l&&r<=rr) return Findl(l,r,t);
	  else 
	  {
	  	    int  rt;
	  	    if (rr>mid)
			{
			    rt=askl(ll,rr,mid+1,r,rs);
				if (rt) return rt;
		    }
		    if (ll<=mid)
		    {
		    	rt=askl(ll,rr,l,mid,ls);
		    	if (rt) return rt;
		    }
		    return 0;
	   }
}
int main()
{ 
   scanf("%d",&n);
   for (i=1;i<=n;++i)
   {
   	  scanf("%s",s);
   	  int L=strlen(s); str[i]=len+1;
   	  for (j=0;j<L;++j) c[++len]=s[j];
   	  End[i]=len;
   	  c[++len]='#';
   	  for (j=str[i];j<=End[i];++j) Max[j]=End[i]-j+1;
   }
   c[++len]='z'+1;
   get_SA();
   get_High(); ans=0;
   for (i=1;i<=len;++i) high[i]=min(high[i],min(Max[sa[i]],Max[sa[i-1]])); 
   for (i=1;i<=n;++i)
   {
   	  scanf("%d",&x);
   	  for (j=str[i];j<=End[i];++j) val[j]=x;
   	  if (max(high[Rank[str[i]]],high[Rank[str[i]]+1])<End[i]-str[i]+1)
   	    ans=max(ans,1ll*x*(End[i]-str[i]+1));
   }
   build_tree(1,len,1);
   for (i=1;i<=len;++i) 
     if (high[i]>0)
     {
     	    p=high[i];
     	    int l=askl(1,i,1,len,1),r=askr(i,len,1,len,1);
     	    ans=max(ans,1ll*ask(l,r-1,1,len,1)*high[i]);
     }
    printf("%I64d\n",ans);
}