#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,m,x[200010][30];
char s[200010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k,l,r;
	scanf("%s",&s);
	n=strlen(s);
	scanf("%d",&m);
	for(i=0;i<26;i++)
	  x[n][i]=n;
	for(i=n-1;i>=0;i--)
	  {
       for(j=0;j<26;j++)
         x[i][j]=x[i+1][j];
       x[i][s[i]-'a']=i;
      }
    while(m--)
      {
       scanf("%d%d",&l,&r);
       l--;
       r--;
       if(l==r)
         {
          printf("Yes\n");
          continue;
         }
       if(s[l]!=s[r])
         {
          printf("Yes\n");
          continue;
         }
       k=0;
       for(i=0;i<26;i++)
         if(x[l][i]<=r)
           k++;
       if(k>=3)
         {
          printf("Yes\n");
          continue;
         }
       printf("No\n");
      }
	return 0;
}