#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		long long n,k;
		cin>>n>>k;
		k=n*(n-1)/2-k+1;
		for(int i=0;i<=n-2;i++)
		{
			if(k>n-i-1)
				k-=n-i-1;
			else
			{
				for(int j=0;j<i;j++)
					cout<<"a";
				cout<<"b";
				for(int j=0;j<k-1;j++)
					cout<<"a";
				cout<<"b";
				for(int j=0;j<n-i-k-1;j++)
					cout<<"a";
				cout<<endl;
				break;
			}
		}
	}
	return 0;
}