#include<bits/stdc++.h>
#include<vector>
using namespace std;
#define ll long long
main()
{
	ll mark, lol,n,sum=0;
	cin>>n;
	char a[n+1],b[n+1];
	cin>>a>>b;
	vector<int>ans;
	for(ll i=0;i<n/2;i++)
	{
		
		ans.clear();
		ans.push_back(int(a[i])-97);
		ans.push_back(int(b[i])-97);
		ans.push_back(int(a[n-1-i])-97);
		ans.push_back(int(b[n-1-i])-97);
		sort(ans.begin(),ans.end());
		lol=0;
		//for(int j=0;j<ans.size();j++)cout<<ans[j]<<" ";cout<<endl;
		for(int j=1;j<ans.size();j++)
		{
			if(ans[j]!=ans[j-1])
			lol++;
		}
		if(lol==1)
		{
			if(ans[2]==ans[1])
			sum+=1;
		}
		else if(lol==2)
		{
			if(a[i]==a[n-1-i])
			sum+=2;
			else sum+=1;
		}
		else if(lol==3)sum+=2;
		//cout<<sum<<endl;
	}
	if(n%2==1)
	{
		sum+=(a[n/2]==b[n/2])?0:1;
	}
	cout<<sum;
}