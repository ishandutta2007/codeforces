#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int MinL,MinR,MaxL,MaxR,n,i;
char c;
int main()
{  scanf("%d",&n);
   MinL=MinR=n+1; c=getchar();
   for (i=1;i<=n;i++) { 
   c=getchar();
   if (c=='R') MinR=min(MinR,i),MaxR=max(MaxR,i);
   if (c=='L') MinL=min(MinL,i),MaxL=max(MaxL,i);
}
if (!MaxR) printf("%d %d\n",MaxL,MinL-1);
else if (!MaxL) printf("%d %d\n",MinR,MaxR+1);
else printf("%d %d\n",MaxL,MaxR+1);
}