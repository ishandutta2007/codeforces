#include<bits/stdc++.h>
using namespace std;
int n,i,j,ti,su,aa,bb;
char c[100010],a[2]={'r','b'},cc;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>c[i];
	for(i=1;i<=n;i++)
	{
		cc=a[i%2];
		if(cc!=c[i])
		{
			if(cc=='r')
				aa++;
			else
				bb++;
		}
	}
	if(aa>bb)
		swap(aa,bb);
	su=(bb-aa)+aa;
	aa=0;
	bb=0;
	for(i=1;i<=n;i++)
	{
		cc=a[(i+1)%2];
		if(cc!=c[i])
		{
			if(cc=='r')
				aa++;
			else
				bb++;
		}
	}
	//cout<<su<<endl;
	if(aa>bb)
		swap(aa,bb);
	su=min((bb-aa)+aa,su);
	//cout<<aa<<bb;
	cout<<su<<endl;
}