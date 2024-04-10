#include<cstdio>
#include<vector>
using namespace std;
int T,n;
vector<int> vec;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int tmp=0;
		vec.clear();
		while(tmp*tmp<n)
		{
			vec.push_back(tmp);
			tmp++;
		}
		if(tmp*tmp==n) 
		{
			if(vec[vec.size()-1]!=tmp) vec.push_back(tmp);
		}
		while(tmp>1)
		{
			tmp--;
			if(vec[vec.size()-1]!=n/tmp) vec.push_back(n/tmp);
		}
		printf("%d\n",vec.size());
		for(int i=0;i<vec.size();i++)
		{
			printf("%d ",vec[i]);
		}
		printf("\n");
	}
	return 0;
}