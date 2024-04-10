#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
using namespace std;

int main()
{
	int n, t;
	string s;
	
	cin >> n >> t >> s;
	for (int i = 0; i < t; i++)
		for (int j = 0; j < n - 1; j++)
			if (s[j] == 'B' && s[j + 1] == 'G') swap(s[j], s[j + 1]), j++;
			
	cout << s << endl;
}