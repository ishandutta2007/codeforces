#include<iostream>
using namespace std;
int main()
{
	int x;
	cin>>x;
	for(int n,s,k;x--;)
	{
		cin>>n>>s>>k;
		bool a[2001]={0};
		for(int m;k--;)
		{
			cin>>m;
			if(m-s<=1000&&m-s>=-1000)a[m-s+1000]=1;
		}
		int ans=0;
		for(;((s-ans<1||a[1000-ans])&&(s+ans>n||a[1000+ans]));ans++);
		cout<<ans<<endl;
	}
	return 0;
}