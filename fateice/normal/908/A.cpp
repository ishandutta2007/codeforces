#include<bits/stdc++.h>
using namespace std;
int n;
char s[100];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,k=0;
	cin>>s;
	n=strlen(s);
	for(i=0;i<n;i++)
	  if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='1' || s[i]=='3' || s[i]=='5' || s[i]=='7' || s[i]=='9')
	    k++;
	cout<<k;
	return 0;
}