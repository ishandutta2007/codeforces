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
//#include "BigNum.h"
using namespace std;
ifstream fin("aa.txt");


int main()
{
	int n;
	int m;
	int k;
	long double a,b;
	vector<long double> v1,v2,v3;
	cin >> n;
	v1.resize(n);
	for(int i = 0; i < n; i ++) cin >> v1[i];
	cin >> m;
	v2.resize(m);
	for(int i = 0; i < m; i++) cin >> v2[i];
	cin >> k;
	v3.resize(k);
	for(int i = 0; i < k; i++) cin >> v3[i];
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	sort(v3.begin(),v3.end());
	cin >> a >> b;
	
	printf("%.10f\n",sqrt(v2[m-1]/((a/b)*v3[0]+v2[m-1]))*(double)v1[n-1]);
	return 0;
}