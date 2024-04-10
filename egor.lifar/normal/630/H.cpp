#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <vector>
#include <bitset>


using namespace std;



int main() {
	unsigned long long n;
	cin >> n;	
	cout << n * n * (n - 1) * (n - 1) / 4LL * (n - 2) * (n - 2) / 3LL * (n - 3) * (n - 3) * (n - 4) / 5LL * (n - 4) / 2LL << endl;  
	return 0;
}
//1 1 3
//1 3 1
//3 1 1
//1 2 2