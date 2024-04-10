#include<bits/stdc++.h>
using namespace std;
vector<string>ans;
int main()
{
	int h1,a1,c,h2,a2;
	scanf("%d%d%d%d%d",&h1,&a1,&c,&h2,&a2);
	while(1)
	{
		if(h2<=a1)
		{
			ans.push_back("STRIKE");
			break;
		}
		if(h1>a2)
		{
			ans.push_back("STRIKE");
			h2-=a1;
		}
		else
		{
			ans.push_back("HEAL");
			h1+=c;
		}
		h1-=a2;
	}
	printf("%d\n",ans.size());
	for(auto i:ans)
		printf("%s\n",i.c_str());
	return 0;
}