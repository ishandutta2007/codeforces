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
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MEM(x,y) (memset((x),(y),sizeof(x)))
const  int INF = 0x7fffffff;

int main()
{
	int x,y,z,dx,dy,dz;
	int sum = 0;
	int a,b,c,d,e,f;
	cin >> x >> y >> z >> dx >> dy >> dz;
	cin >> a >> b >> c >> d >>e >> f;
	if(x > dx) sum += f;
	if(x < 0) sum += e;
	if(y > dy) sum += b;
	if(y < 0) sum += a;
	if(z > dz) sum += d;
	if(z < 0) sum += c;
	cout << sum << endl;
	return 0;
	
}