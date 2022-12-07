#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
using namespace std;
string a,b;
int main()
{
	cin>>a>>b;
	for(int i=0;i<a.length();i++)
		if(a[i]>='A' && a[i]<='Z')
			a[i]=char(a[i]+32);
	for(int i=0;i<b.length();i++)
		if(b[i]>='A' && b[i]<='Z')
			b[i]=char(b[i]+32);		
	if(a==b)cout<<0;
	if(a<b)cout<<-1;
	if(a>b)cout<<1;
	cout<<endl;
	return 0;
}