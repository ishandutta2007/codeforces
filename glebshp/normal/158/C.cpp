#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
const double pi = acos(-1.0);

string dirtostring(vector <string> v)
{
	string r = "";
	for (int i = 0; i < v.size(); i++)
		r += "/" + v[i];
	r += "/";
	return r;
}

vector <string> strtodir(string str)
{
	vector <string> v;
	v.clear();
	string h = "";
	int p = str[0] == '/';
	while (p < str.size())
	{
		if (str[p] == '/')
		{
			v.pb(h);
			h = "";
		}
		else
			h += str[p];
		p++;
	}
	if (h != "")
		v.pb(h);
	return v;
}

int main() {
	int n;
	vector <string> dir, h;
	string cmd, str;
	
	//freopen("problem_c.in", "r", stdin);
	//freopen("problem_c.out", "w", stdout);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> cmd;
		if (cmd == "pwd")
			cout << dirtostring(dir) << endl;
		else
		{
			cin >> str;
			h = strtodir(str);
			if (str[0] == '/')
			{
				dir.clear();
			}
			for (int j = 0; j < h.size(); j++)
				if (h[j] == "..")
					dir.pop_back();
				else
					dir.push_back(h[j]);
		}
	}

	return 0;
}