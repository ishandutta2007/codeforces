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
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const int N = 1e5;
LL a[N+10];
LL gcd(LL n, LL m)
{
	if(n < m) swap(n,m);
	while(n%m)
	{
		n = n%m;
		swap(n,m);
	}
	return m;
}
int main()
{
//	freopen("input.txt","r",stdin);

	LL n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a,a+n);
	LL ans = 0;
	LL sum = a[0];
	for(int i = 1; i < n; i++)
	{
		ans += a[i] * i - sum;
		sum += a[i];
	}
	ans += ans + sum;
	LL g = gcd(ans,n);
	ans /= g;
	n /= g;
	cout << ans << ' ' << n << endl;
	return 0;


}