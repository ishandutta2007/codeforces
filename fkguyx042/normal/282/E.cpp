#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int Tree[6400001][2],Two[65],top,i,n;
long long b[100005],c[100005],a[100005],ans,Last;
void Got(long long x)
{ memset(Two,0,sizeof(Two));
  for (;x;x/=2ll)
  {  Two[++Two[0]]=x%2; }
}
void ask(int x)
{  Got(b[x]); long long sum=0,i;
   for (Last=0,i=1;i<=64;i++)
   {   if (Tree[Last][1-Two[64-i+1]])
       {   Last=Tree[Last][1-Two[65-i]];
            sum=sum*2+1;
      }
      else {  Last=Tree[Last][Two[65-i]];
              sum*=2;
        }
  }
  ans=max(ans,sum);
}
void update(int x)
{ Got(c[x]); int i;
  for (Last=0,i=1;i<=64;i++)
  {  if (!Tree[Last][Two[65-i]]) Tree[Last][Two[65-i]]=++top;
      Last=Tree[Last][Two[65-i]];
}
}
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++) 
  scanf("%I64d",&a[i]),b[i]=b[i-1]^a[i];
  for (i=n;i;i--)
   c[i]=c[i+1]^a[i];
   update(n+1);
  for (i=n;i>=0;i--)
  {  ask(i);
     update(i);
  }
  printf("%I64d\n",ans);
}