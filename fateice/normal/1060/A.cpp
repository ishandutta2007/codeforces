#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,m;
char s[200];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	cin>>n>>s;
	for(i=0;i<n;i++)
	  if(s[i]=='8')
	    m++;
	cout<<min(m,n/11);
	return 0;
}