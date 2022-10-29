#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char c[100001],tp[100001];
int sum,i,tot;
int main()
{ scanf("%s",&c);
  int Len=strlen(c);
  for (i=0;i<Len;i++)
 {   if (!sum) tp[++sum]=c[i];
    else {if (tp[sum]==c[i]) sum--; else tp[++sum]=c[i]; }
 }
 if (sum) printf("No\n");
 else printf("Yes\n");
}