#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n;
char a[100010],b[100010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j=0,k=0,l=0,r=0;
	scanf("%d%s%s",&n,&a,&b);
	for(i=0;i<n;i++)
	  if(b[i]=='0')
	    if(a[i]=='0')
	      j++;
	    else
	      k++;
	  else
	    if(a[i]=='0')
	      l++;
	    else
	      r++;
	cout<<(L)j*k+(L)j*r+(L)k*l;
	return 0;
}