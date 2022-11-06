#include<bits/stdc++.h>
using namespace std;
int a,b,n,i;
char x[1002000];
int main()
{
	cin>>n>>a>>b;
	for(i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	if(x[a]==x[b])
		cout<<0<<endl;
	else
		cout<<1<<endl;
	return 0;
}