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
	int s,f;
	int n,m;
	cin >> n >> m >> s >> f;
	int t,l,r;
	int ad;
	char c;
	if(s > f) ad = -1,c = 'L';
	else ad = 1,c = 'R';
	int cur = 1;
	int flag = 0;
	while(m--)
	{
		cin >> t >> l >> r;
		if(flag) continue;
		for(cur = cur; cur < t; cur++)
		{
			s += ad;
			cout << c;
			if(s == f)
			{
				flag = 1;
				break;
			}
		}
		cur = t+1;
		if(flag) break;
		int y = s+ad;
		if((s >= l && s <= r) || (y >= l && y <= r)) { cout << 'X';continue;}
		s = y;
		cout << c;
		if(s == f) {flag = 1; continue;}
	}
	int tmp = abs(s-f);
	while(tmp--) cout << c;
	cout << endl;





	return 0;
}