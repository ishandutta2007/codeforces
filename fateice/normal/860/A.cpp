#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n;
char s[3010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%s",&s);
	n=strlen(s);
	for(i=0,j=0,k=0;i<n;i++)
	  {
	   if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
	     j=k=0;
	   else
	     {
		  j++;
		  if(j==1)
		    k=s[i]-'a';
		  else if(k!=s[i]-'a')
		    k=100;
		 }
	   if(j>=3 && k==100)
	     {
		  printf(" ");
		  j=1;
		  k=s[i]-'a';
		 }
	   printf("%c",s[i]);
	  }
	return 0;
}