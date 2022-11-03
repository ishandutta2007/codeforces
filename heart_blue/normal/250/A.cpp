#include <cstdlib>    
#include <cctype>   
#include <cstring>   
#include <cstdio>   
#include <cmath>   
#include <algorithm>   
#include <vector>   
#include <string>   
#include <iostream>   
#include <sstream>   
#include <map>   
#include <set>   
#include <queue>   
#include <stack>   
#include <fstream>   
#include <numeric>   
#include <iomanip>   
#include <bitset>   
#include <list>   
#include <stdexcept>   
#include <functional>   
#include <utility>   
#include <ctime>
using namespace std;
ifstream fin("aa.txt");
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MEM(a,b) (memset((a),(b),sizeof(a)))

int main()
{
	int n;
	int a;
	vector<int> v;
	int k;
	cin >> n;
	int t = 0;
	k = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		t ++;
		if(a < 0)
		{
			k++;
			if(k == 3)
			{
				v.push_back(t-1);
				t = 1;
				k = 1;
			}
			
		}
		if(i == n-1)
		{
			v.push_back(t);
		}
	}
	cout << v.size() << endl;
	cout << v[0];
	for(int i = 1; i < v.size(); i++)
	{
		cout << ' ' << v[i];
	}
	cout << endl;

	return 0;
}