
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second


int gd(const string &a, const string &b)
{
	int d = 0;
	for (int i = 0; i < (int)a.size(); i++)
	    if (a[i] != b[i]) d++;
	return d;
}
string a[1005];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int mind = 1000;
	for (int i = 0; i < n; i++)
	  for (int j = i+1; j < n; j++)
	     mind = min(mind, gd(a[i], a[j]));
	cout << min(6, (mind-1)/2) << endl;
	return 0;
}