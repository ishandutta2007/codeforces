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
	//freopen("aa.txt","r",stdin);
	int n;
	int sum = 0;
	cin >> n;
	int a;
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		sum += a;
	}
	if(sum % n == 0)
	{
		cout << n << endl;
	}
	else cout << n-1 << endl;

		

	return 0;
}