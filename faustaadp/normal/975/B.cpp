#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll i,a[1010],hz,j,tem[1010],has;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(i=0;i<14;i++)
		cin>>a[i];
	for(i=0;i<14;i++)
	{
		if(a[i]!=0)
		{
			hz=0;
			for(j=0;j<14;j++)
				tem[j]=a[j]+a[i]/14;
			tem[i]-=a[i];
			for(j=i+1;j<=i+a[i]%14;j++)
				tem[j%14]++;
			for(j=0;j<14;j++)
				if(tem[j]%2==0)
					hz+=tem[j];
		//		cout<<tem[j]<<" ";
		//	cout<<"\n";
			has=max(has,hz);
		}
	}
	cout<<has<<"\n";
}