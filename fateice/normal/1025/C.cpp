#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n;
char s[200010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%s",&s);
	n=strlen(s);
	for(i=n;i<2*n;i++)
	  s[i]=s[i-n];
	for(i=1,j=1,k=1;i<2*n;i++)
	  if(s[i]==s[i-1])
	    j=1;
	  else
	    {
         j++;
         k=max(k,j);
        }
	if(k>n)
	  k=n;
	printf("%d\n",k);
	return 0;
}