#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define PI 3.1415926535897932384626433832795

const long long inf = 1000ll * 1000 * 1000 * 10;

vector <long long> luck;

void genthemall(long long ln)
{
	if (ln > inf)
		return;
	luck.pb(ln);
	genthemall(ln * 10ll + 4);
	genthemall(ln * 10ll + 7);
}

int main()
{
    long long l, r, lb, rb;
	int i;
	long long ans = 0;
	
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	cin >> l >> r;
	genthemall(0);

	sort(luck.begin(), luck.end());
	//cout << r - l << endl;
	for (i = 1; i < luck.size(); i++)
	{
		lb = max(l, luck[i - 1] + 1);
		rb = min(r, luck[i]);
		//if (rb >= lb)
		//	cerr << "opa!" << endl;
		ans += luck[i] * (max(0ll, rb - lb + 1));
	}
	cout << ans << endl;


    return 0;
}