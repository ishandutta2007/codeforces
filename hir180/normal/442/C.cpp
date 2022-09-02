#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int n;
	int num[500005];
	cin >> n;
	for(int i=0;i<n;i++) cin >> num[i];
	vector<int>vec;
	for(int i=0;i<n;i++) vec.push_back(num[i]);
	long long res = 0;
	while(1)
	{
		vector<int>cpy;
		for(int i=0;i<vec.size();i++)
		{
			while(cpy.size() >= 2 && cpy[cpy.size()-2] >= cpy[cpy.size()-1] && cpy[cpy.size()-1] <= vec[i])
			{
				res += min(cpy[cpy.size()-2],vec[i]);
				cpy.pop_back();
			}
			cpy.push_back(vec[i]);
		}
		if(cpy.size() == vec.size()) break;
		vec = cpy;
	}
	sort(vec.begin(),vec.end());
	for(int i=2;i<vec.size();i++)
	{
		res += vec[i-2];
	}
	cout << res << endl;
}