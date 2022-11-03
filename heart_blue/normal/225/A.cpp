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
#define MEM(a,b) (memset((a),(b),sizeof(a)))
int a[7];
int main()
{
	int n,x;
	cin >> n >> x;
	int b,c;
	int k = 0;
	MEM(a,0);
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> b >> c;
		if(a[b]== 0)
		{
			cnt++;
			a[b] = a[7-b] = 1;
		}
		if(a[c]== 0)
		{
			cnt++;
			a[c] = a[7-c] = 1;
		}
	}
	if(cnt == 3) cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}