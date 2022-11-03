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
ifstream fin("ab.txt");
#define MIN(a,b) (a) < (b) ? (a) : (b)
#define MAX(a,b) (a) > (b) ? (a) : (b)
vector<int> v1,v2;
int main()
{
	int n,x;
	cin >> n >> x;
	v1.resize(n);
	v2.resize(n);
	for(int i = 0; i < n; i++) cin >> v1[i];
	for(int i = 0; i < n; i++) cin >> v2[i];
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	int i,j;
	i = 0;
	j = n-1;
	int ans = 0;
	bool flag = 0;
	while(i < n && j >= 0)
	{
		if(v2[j] + v1[i] >= x)
		{
			j--;
			i++;
			ans ++;
		}
		else i++;
	}
	cout << 1 << ' ' << ans << endl;

	return 0;
}