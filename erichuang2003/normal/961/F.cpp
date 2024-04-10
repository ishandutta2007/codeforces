#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 4000000 + 1000;

int n;
char ss[MAXN], s[MAXN];
int mat[MAXN], tag[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);

	cin >> n;
	cin >> (ss + 1);
	for(int i = 1; i <= n; i++)
		s[2 * i - 1] = ss[i];
	for(int i = 1; i <= n; i++)
		s[2 * i] = ss[n - i + 1];
	for(int i = 1; i <= 2 * n; i++)
		ss[i] = s[i];
	for(int i = 1; i <= 2 * n; i++)
		s[2 * i] = ss[i];
	for(int i = 1; i <= 4 * n + 1; i += 2)
		s[i] = '#';

	int id = 1, mx = 1;
	for(int i = 2; i <= 4 * n; i++)
	{
		int t = max(0, min(mat[2 * id - i], mx - i));
		while(i - t - 1 >= 1 && i + t + 1 <= 4 * n + 1 && s[i - t - 1] == s[i + t + 1])
			t++;
		mat[i] = t;
		if(i + mat[i] > mx)
			mx = i + mat[i], id = i;
	}
	// for(int i = 1; i <= 4 * n + 1; i++)
	// 	cerr << s[i] << ' ';
	// cerr << endl;
	// for(int i = 1; i <= 4 * n + 1; i++)
	// 	cerr << mat[i] << ' ';
	// cerr << endl;
	for(int i = 1; i <= 2 * n; i += 2)
	{
		int t = mat[i];
		if(t == 0) continue;
		if(t % 4 == 0) t -= 2;
		tag[i - t + 1] = max(tag[i - t + 1], t / 2);
		// cerr << i << ' ' << t << ' ' << i - t + 1 << ' ' << t / 2 << endl;
	}
	for(int i = 2; i <= 2 * n; i += 2)
		tag[i + 4] = max(tag[i + 4], tag[i] - 2);
	for(int i = 2; i <= 2 * n; i += 4)
		if(tag[i] == 0)
			cout << -1 << ' ';
		else
			cout << tag[i] << ' ';
	cout << endl;




	return 0;
}