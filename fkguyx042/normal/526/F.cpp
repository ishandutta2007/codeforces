#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 300005

using namespace std;
int A[N],i,j,m,n,p,k,Min[N],Max[N],x,y,Sum[3*N];
long long ans=0;
void ins(int x) { Sum[x+N]++; }
void del(int x)  { Sum[x+N]--; }
void Fen(int l,int r)
{ 
  if (l==r) ans++;
  else 
 {
   int mid=(l+r)>>1;
   Fen(l,mid);
   Fen(mid+1,r);
   Min[mid]=Max[mid]=A[mid]; Max[mid+1]=Min[mid+1]=A[mid+1];
   for (i=mid-1;i>=l;--i) Min[i]=min(Min[i+1],A[i]),Max[i]=max(Max[i+1],A[i]);
   for (i=mid+2;i<=r;++i) Min[i]=min(Min[i-1],A[i]),Max[i]=max(Max[i-1],A[i]);
   for (i=l;i<=mid;++i)
   {
   	    int id=i+Max[i]-Min[i];
   	    if (id>mid&&id<=r&&Max[id]<Max[i]&&Min[id]>Min[i]) ++ans;
   }
   for (i=mid+1;i<=r;++i)
   {
   	    int id=i+Min[i]-Max[i];
   	    if (id<=mid&&id>=l&&Max[id]<Max[i]&&Min[id]>Min[i]) ++ans;
   }
   int L=mid+1,R=mid;
   for (i=mid+1;i<=r;++i)
   {
       while (L>l&&Min[L-1]>=Min[i]) L--,ins(L+Max[L]);
       while (L<=R&&Max[R]<Max[i])   del(R+Max[R]),--R;
       ans+=Sum[i+Min[i]+N];
   }
   for (i=L;i<=R;++i) del(i+Max[i]);
   L=mid,R=mid+1;
   for (i=mid;i>=l;--i)
   {
   	    while (L<r&&Min[L+1]>=Min[i]) L++,ins(L-Max[L]);
   	    while (R<=L&&Max[R]<Max[i]) del(R-Max[R]),++R;
   	    ans+=Sum[i-Min[i]+N];
   }
   for (i=R;i<=L;++i) del(i-Max[i]);
 }
}
inline int read()
{
	  int x=0; char c;
	  while (c=getchar(),c<'0'||c>'9');
	  x=c-'0';
	  while (c=getchar(),c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0';
	  return x;
}
int main()
{
	 scanf("%d",&n);
	 for (i=1;i<=n;++i)
	 { 
	   x=read(); y=read();
	   A[x]=y;
    }
    Fen(1,n);
    printf("%I64d\n",ans);
}