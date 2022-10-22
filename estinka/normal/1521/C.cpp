#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <iostream>
//#define LOCAL
typedef long long ll;
using namespace std;

int p[10003], h[10003];
int ask(int t, int i, int j, int x)
{
	cout << "? " << t << " " << i + 1 << " " << j + 1 << " " << x << endl;
#ifdef LOCAL
	int l = 0;
	if (t == 1) l = max(min(x, h[i]), min(x + 1, h[j]));
	if (t == 2) l = min(max(x, h[i]), max(x + 1, h[j]));
	//cout << " = " << l << endl;
	return l;
#endif
	cout.flush();
	int ans; cin >> ans;
	if (ans == -1) 
		exit(0);
	return ans;
}
int n;
void determine(int i, int j)
{
	// a <= b
	int a = ask(2, i, j, 1), b = ask(1, i, j, n - 1);
	if (a <= 2 || b >= n - 1) // this can only happen with 4 pairs
	{
		a = min(a, ask(2, j, i, 1));
		b = max(b, ask(1, j, i, n - 1));
	}
	int c = ask(2, i, j, a);
	if (c == a) p[i] = a, p[j] = b;
	else p[i] = b, p[j] = a;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; 
	cin >> t;
	while (t--)
	{
		cin >> n;
#ifdef LOCAL
		for (int i = 0; i < n; i++)
			cin >> h[i];
#endif
		for (int i = 0; i < n; i += 2)
		{
			determine(i, (i + 1) % n);
		}
		cout << "! ";
		for (int i = 0; i < n; i++)
			cout << p[i] << " ";
		cout << endl; cout.flush();
	}
	return 0;
}