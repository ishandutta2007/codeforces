#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,x[200010],l,r,m;
inline int orz(int i)
{
    return x[(i+n/2-1)%n+1]-x[i];
}
inline int ask(int i)
{
    int k;
    cout<<"? "<<(i-1)%n+1<<"\n";
    fflush(stdout);
    cin>>k;
    return k;
}
inline void pri(int i)
{
    cout<<"! "<<i<<"\n";
    fflush(stdout);
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	scanf("%d",&n);
	if(n/2%2)
	  {
       pri(-1);
       return 0;
      }
	x[1]=ask(1);
	x[1+n/2]=ask(1+n/2);
	if(orz(1)==0)
	  {
	   pri(1);
	   return 0;
      }
    if(orz(1)<0)
      l=2,r=n/2;
    else
      l=n/2+2,r=n;
    while(l<=r)
      {
       m=(l+r>>1);
       x[m]=ask(m);
       x[(m+n/2-1)%n+1]=ask(m+n/2);
       if(orz(m)==0)
         {
          pri(m);
          return 0;
         }
       if(orz(m)<0)
         l=m+1;
       else
         r=m-1;
      }
	return 0;
}