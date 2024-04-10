#include<bits/stdc++.h>
#define L long long
using namespace std;
char s[1010];
int n;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	cin>>s;
	n=strlen(s);
	cout<<s;
	for(i=n-1;i>=0;i--)
	  cout<<s[i];
	return 0;
}