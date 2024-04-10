#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,a[30],b[30];
char s[300010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k,l=2;
	scanf("%s",&s);
	n=strlen(s);
	for(i=0;i<n;i++)
	  a[s[i]-'a']++;
	scanf("%s",&s);
	for(i=0;i<n;i++)
	  b[s[i]-'a']++;
	for(i=0,j=0,k=25;i<n;i++)
	  {
       while(j<26 && !a[j])
         j++;
       while(k>=0 && !b[k])
         k--;
       if(j>=k && l==2)
         if((i&1)==(n-1&1))
           l=0;
         else
           l=1;
       if((i^l)&1)
         {
          s[i]=k+'a';
          b[k]--;
         }
       else
         {
          s[i]=j+'a';
          a[j]--;
         }
      }
    printf("%s\n",s);
	return 0;
}