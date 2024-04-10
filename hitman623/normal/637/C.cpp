#include <bits/stdc++.h>
using namespace std;
int cmp(string a,string b)
{
	int c=0;
	for(int i=0;i<6;i++)
	if(a[i]!=b[i]) c++;
	return c;
}
int main()
{
    int n,m=6,i,j,a;
    string s[1003];
    cin>>n;
    for(i=0;i<n;++i)
    cin>>s[i];
    for(i=0;i<n;i++)
    for(j=i+1;j<n;j++)
    {a=cmp(s[i],s[j]);
    m=min(m,a/2-!(a%2));}
    cout<<m;
    return 0;
}