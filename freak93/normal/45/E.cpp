#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string a[500],b[500];

int i,n,j,with[500],use[500],nev[500],k,hav[500];

int main()
{
	cin>>n;
	for(i=1;i<=n;++i)
		cin>>a[i];
	for(i=1;i<=n;++i)
		cin>>b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for(i=1;i<=n;++i)
		++nev[a[i][0]],++hav[b[i][0]];
	j=1;k=1;
	for(i=1;i<=n;++i)
	{
       for(j=1;j<=n;++j)
		   if(use[j]==0&&(nev[b[j][0]]<hav[b[j][0]]||a[i][0]==b[j][0]))
			   if(b[j][0]<a[i][0]&&hav[a[i][0]]>=nev[a[i][0]]);
	  			else
			   break;
	   with[i]=j;use[j]=1;hav[b[j][0]]--;--nev[a[i][0]];
	}
	cout<<a[1]<<" "<<b[with[1]];
	for(i=2;i<=n;++i)
		cout<<", "<<a[i]<<" "<<b[with[i]];
}