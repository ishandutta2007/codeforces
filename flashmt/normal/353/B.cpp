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
	int n, cnt[111] = {0}, x, ans[222];
	vector <int> id[111];
	
	cin >> n;
	for (int i = 0; i < n * 2; i++) cin >> x, id[x].push_back(i);
	
	set <int> heap1, heap2;
	int turn = 1;
	for (int i = 10; i < 100; i++)
		if (id[i].size() >= 2)
		{
			heap1.insert(i);
			ans[id[i].back()] = 1;
			id[i].pop_back();
			heap2.insert(i);
			ans[id[i].back()] = 2;
			id[i].pop_back();
		}
		else
			if (id[i].size() == 1)
			{
				if (turn == 1) heap1.insert(i), ans[id[i][0]] = 1;
				else heap2.insert(i), ans[id[i][0]] = 2;;
				turn = 3 - turn;
				id[i].pop_back();
			}
		
	for (int i = 10; i < 100; i++)
		while (!id[i].empty())
		{
			if (turn == 1) heap1.insert(i), ans[id[i].back()] = 1;
			else heap2.insert(i), ans[id[i].back()] = 2;
			turn = 3 - turn;
			id[i].pop_back();
		}
		
	cout << heap1.size() * heap2.size() << endl;
	for (int i = 0; i < n * 2; i++) cout << ans[i] << ' ';
}