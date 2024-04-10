#include<cstdlib>
#include<cctype>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<fstream>
#include<numeric>
#include<iomanip>
#include<bitset>
#include<list>
#include<stdexcept>
#include<functional>
#include<utility>
#include<ctime>
using namespace std;
#define MAX (a,b) ((a)>(b)?(a):(b))
#define MIN (a,b) ((a)<(b)?(a):(b))
#define MEM(a,b) memset((a),(b),sizeof(a))
typedef long long LL;
typedef unsigned long long ULL;

int main()
{
	//freopen("input.txt","r",stdin);
	LL a,b,ans;
	ans = 0;
	cin >> a >> b;
	while(1)
	{
		if(a % b == 0)
		{
			ans += a/b;
			break;
		}
		ans += a/b;
		a = a%b;
		swap(a,b);
	}
	cout  << ans << endl;
	
	
	return 0;
}