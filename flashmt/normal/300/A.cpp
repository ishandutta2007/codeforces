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
#include <stack>
#include <sstream>
using namespace std;

int main()
{
	int n, x;
	vector <int> pos, neg, zero;
	cin >> n;
	while (n--)
	{
		cin >> x;
		if (!x) zero.push_back(x);
		else
			if (x > 0) pos.push_back(x);
			else neg.push_back(x);
	}
	
	if (pos.empty()) 
	{
		pos.push_back(neg.back()); neg.pop_back();
		pos.push_back(neg.back()); neg.pop_back();
	}
	
	if (neg.size() % 2 == 0)
	{
		zero.push_back(neg.back()); neg.pop_back();
	}
	
	cout << neg.size() << ' ';
	for (int i = 0; i < int(neg.size()); i++) cout << neg[i] << ' '; puts("");	
	cout << pos.size() << ' ';
	for (int i = 0; i < int(pos.size()); i++) cout << pos[i] << ' '; puts("");
	cout << zero.size() << ' ';
	for (int i = 0; i < int(zero.size()); i++) cout << zero[i] << ' '; puts("");
}