#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
const int sz = 100000;
int n, m;
string s[sz], t[sz];
int main()
{
    scanf("%i%i",&n,&m);
    for(int i=0;i<n;i++)
	cin >> s[i];
    for(int j=0;j<m;j++)
	cin >> t[j];

    sort(s,s+n);
    sort(t,t+m);
    int i=0, j=0;
    int b = 0;
    while(i<n && j<m)
    {
	if(s[i]==t[j])
	{
	    b++;
	    i++;
	    j++;
	}
	else if(s[i]<t[j])
	    i++;
	else
	    j++;
    }
    if(n-(b/2)>m-b+(b/2))
	printf("YES\n");
    else
	printf("NO\n");
}