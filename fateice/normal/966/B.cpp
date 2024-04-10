#include<bits/stdc++.h>
#define L long long
#define aa first
#define bb second
#define pb push_back
using namespace std;
int n,m1,m2;
pair<int,int> a[300010];
vector<int> x,y;
inline void print()
{
    int i;
    printf("Yes\n%d %d\n",(int)x.size(),(int)y.size());
    for(i=0;i<x.size();i++)
      printf("%d ",x[i]);
    printf("\n");
    for(i=0;i<y.size();i++)
      printf("%d ",y[i]);
    printf("\n");
}
inline bool chk()
{
    int i,j;
    for(i=n;i>0;i--)
      if((L)a[i].aa*(n-i+1)>=m1)
        break;
    if(i>0)
      {
       for(j=i-1;j>0;j--)
         if((L)a[j].aa*(i-j)>=m2)
           break;
       if(j>0)
         {
          for(;j<i;j++)
            y.pb(a[j].bb);
          for(;i<=n;i++)
            x.pb(a[i].bb);
          return 1;
         }
       else
         return 0;
      }
    else
      return 0;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k1,k2;
	scanf("%d%d%d",&n,&m1,&m2);
	for(i=1;i<=n;i++)
	  {
	   scanf("%d",&a[i].aa);
       a[i].bb=i;
      }
    sort(a+1,a+n+1);
    if(chk())
      print();
    else
      {
       swap(m1,m2);
       if(chk())
         {
          swap(x,y);
          print();
         }
       else
         printf("No\n");
      }
	return 0;
}