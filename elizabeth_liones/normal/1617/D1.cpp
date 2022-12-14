#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <iomanip>
typedef long long ll;
using namespace std;

//vector<int> h(10005);
//int num = 0;
int query(int a, int b, int c)
{
	cout << "? " << a + 1 << " " << b + 1 << " " << c + 1 << endl;
	//int val = (h[a] + h[b] + h[c]) >= 2;
	//cout << val << "\n";
	int val;
	cin >> val;
	//num++;
	if (val == -1) exit(0);
	return 1 - val;
}
vector<int> ans;
void determine(int my, vector<int> v, int op)
{
	if (query(v[0], v[1], op) == my)
	{
		ans[v[0]] = my; ans[v[1]] = my;
		ans[v[2]] = query(v[0], v[2], op);
	}
	else if (query(v[0], v[2], op) == my)
	{
		ans[v[0]] = my; ans[v[1]] = 1 - my; ans[v[2]] = my;
	}
	else
	{
		ans[v[0]] = 1 - my; ans[v[1]] =my; ans[v[2]] = my;
	}
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		//num = 0;
		int n;
		cin >> n;
		ans.assign(n, -1);
		//for (int i = 0; i < n; i++) cin >> h[i];
		vector<int> v3(n / 3);
		vector<int> s0, s1;
		for (int i = 0; i < n; i += 3)
		{
			v3[i / 3] = query(i, i + 1, i + 2);
			if (v3[i / 3] == 0 && s0.empty()) s0 = { i, i + 1, i + 2 };
			if (v3[i / 3] == 1 && s1.empty()) s1 = { i, i + 1, i + 2 };
		}
		int i0 = -1, i1 = -1;
		if (query(s0[0], s0[1], s1[0]) == 0 && query(s0[0], s0[1], s1[1]) == 0)
		{
			ans[s0[0]] = 0; ans[s0[1]] = 0;
			if (query(s0[0], s0[2], s1[0]) == 0 && query(s0[0], s0[2], s1[1]) == 0) ans[s0[2]] = 0;
			else ans[s0[2]] = 1;
		}
		else if (query(s0[0], s0[2], s1[0]) == 0 && query(s0[0], s0[2], s1[1]) == 0)
		{
			ans[s0[0]] = 0; ans[s0[1]] = 1; ans[s0[2]] = 0;
		}
		else
		{
			ans[s0[0]] = 1; ans[s0[1]] = 0; ans[s0[2]] = 0;
		}
		i0 = find(ans.begin(), ans.end(), 0) - ans.begin();
		determine(1, s1, i0);
		i1 = find(ans.begin(), ans.end(), 1) - ans.begin();
		for (int i = 0; i < n; i += 3) if (ans[i] == -1)
		{
			if (v3[i / 3] == 0) determine(0, { i, i + 1, i + 2 }, i1);
			if (v3[i / 3] == 1) determine(1, { i, i + 1, i + 2 }, i0);
		}
		vector<int> bad;
		for (int i = 0; i < n; i++) if (ans[i]) bad.push_back(i);
		cout << "! " << bad.size();
		for (int i : bad) cout << " " << i + 1;
		cout << endl;
		//cout << num << endl;
	}
	return 0;
}