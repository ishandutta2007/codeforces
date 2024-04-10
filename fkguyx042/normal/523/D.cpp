#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int i,j,m,n,p,k,x,y;
long long R;
priority_queue<long long,vector<long long>,greater<long long> >Q;
int main()
{ scanf("%d%d",&n,&k);
  for (;n--;)
  { 
      scanf("%d%d",&x,&y);
      if(k)
      { 
	    k--;
        Q.push(x+y);
        printf("%d\n",x+y);
      }
      else 
      { R=Q.top(); Q.pop();
         if (R>=x) printf("%I64d\n",R+y),Q.push(R+y);
         else printf("%I64d\n",(long long)(x+y)),Q.push(x+y);
     }
}
}