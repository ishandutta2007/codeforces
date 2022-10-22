#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<int>ans;
		if(n/1000)
			ans.push_back(n/1000*1000);
		n%=1000;
		if(n/100)
			ans.push_back(n/100*100);
		n%=100;
		if(n/10)
			ans.push_back(n/10*10);
		n%=10;
		if(n/1)
			ans.push_back(n/1*1);
		n%=1;
		printf("%d\n",ans.size());
		for(auto i:ans)
			printf("%d ",i);
		puts("");
	}
	return 0;
}