#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int ans[100001];
char c[100001];
int i,j,m,n,p,k,ps;
void pt()
{ printf("-1\n");
  exit(0);
}
int main()
{ scanf("%s",&c);
  int Len=strlen(c);
  for (i=Len-1;i>=0;i--) if (c[i]=='#') break;
  j=i;
  for(i=j+1;i<Len;i++) 
  {
  if (c[i]=='(') k++; else
  if (!k) ps++; 
  else  k--;
  }
  if (k>0) pt();
  k-=ps;
  for (i=0;i<j;i++) {
  if (c[i]=='(') n++;
  else if(c[i]==')') n--;
  else { ans[++ans[0]]=1; n--; } 
  if (n<0) pt();
}
 if (n+k-1<0) pt();
 ans[++ans[0]]=n+k;
 for (i=1;i<=ans[0];i++) printf("%d\n",ans[i]);
}