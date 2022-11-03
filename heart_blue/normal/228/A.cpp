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
map <int,int> mp;
int main()
{
	int a,b,c,d;
	mp.clear();
	cin >> a >> b >> c >> d;
	int cnt = 1;
	mp[a] = 1;
	if(!mp[b]) cnt++,mp[b] = 1;
	if(!mp[c]) cnt++,mp[c] = 1;
	if(!mp[d]) cnt++,mp[d] = 1;
	cout << 4-cnt << endl;
	return 0;
}