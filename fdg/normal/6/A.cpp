#include <iostream>
#include <algorithm>
#include <vector>

#define dat cin
#define sol cout

using namespace std;

int main()
{
	vector <long> v(4,0);
	bool tr=false,seg=false;
	for(int i=0;i<4;i++)
		dat >> v[i];
	sort(v.begin(),v.end());
	if (v[0]<v[1]+v[2]&&v[0]>=v[1]&&v[0]>=v[2]) tr=true;
	else
		if (v[0]==v[1]+v[2]&&v[0]>=v[1]&&v[0]>=v[2]) seg=true;
	while(next_permutation(v.begin(),v.end()))
	{
		if (v[0]<v[1]+v[2]&&v[0]>=v[1]&&v[0]>=v[2]) tr=true;
		else
			if (v[0]==v[1]+v[2]&&v[0]>=v[1]&&v[0]>=v[2]) seg=true;
	}
	if (tr) sol << "TRIANGLE\n";
	else
		if (seg) sol << "SEGMENT\n";
		else
			sol << "IMPOSSIBLE\n";
	return 0;
}