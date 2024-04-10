#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int b,k,p;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d%d",&b,&k);
	for(i=1;i<=k;i++)
	  {
	   scanf("%d",&j);
	   if(j%2 && (i==k || b%2))
	     p^=1;
      }
    if(p)
      cout<<"odd";
    else
      cout<<"even";
	return 0;
}