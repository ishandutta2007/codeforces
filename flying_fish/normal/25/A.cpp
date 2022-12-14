#include<bits/stdc++.h>
using namespace std;
int n;int oushu=0,jishu=0;
int x[110];int cnt=0;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
		if(x[i]%2==0)oushu++;
		else jishu++;
	}
	if(oushu>jishu)
	{
		for(int i=1;i<=n;i++)
		{
			if(x[i]&1) {cout<<i;return 0;}
		}
	}
	else 
	{
		for(int i=1;i<=n;i++)
	
			if(x[i]%2==0){
				cout<<i;
				return 0;
			}
	}
}