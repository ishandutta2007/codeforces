#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T-->0)
	{
		int n,k;
		cin>>n>>k;
		vector<int> Ans;
		int calc=0;
		for(int i=k+1;i<=n;++i)	Ans.push_back(i),++calc;
		if(k&1)
		{
			for(int i=k-1;i;--i)
			{
				if(i+i+1==k)	break;
				Ans.push_back(i);
				++calc;
			}
		}
		else
		{
			for(int i=k-1;i;--i)
			{
				if(i+i==k)
				{
					Ans.push_back(i);
					++calc;
					break;
				}
				Ans.push_back(i);
				++calc;
			}
		}
		cout<<calc<<endl;
		for(unsigned int i=0;i<Ans.size();++i)	cout<<Ans[i]<<' ';
		cout<<endl;
	}
	return 0;
}