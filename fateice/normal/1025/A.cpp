#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,x[30];
char s[100010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,k=0;
	scanf("%d%s",&n,&s);
	for(i=0;i<n;i++)
	  x[s[i]-'a']++;
	for(i=0;i<=25;i++)
	  if(x[i]>=2)
	    break;
	  else if(x[i])
	    k++;
	if(i==26 && k>1)
	  printf("No\n");
	else
	  printf("Yes\n");
	return 0;
}