#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);

	int N;
	cin >> N;
	int a[100];
	int stor;

	for(int i = 0; i < N;i++)
		cin >> a[i];

	for(int i = 0; i < N;i++)
	{
		for(int j = 0; j < N-1;j++)
		{
			if(a[j] > a[j+1])
			{
				cout << j+1 << " " << j+2 << endl;
				stor = a[j];
				a[j] = a[j+1];
				a[j+1] = stor;
			}
		}
	}

	cout.flush();
	return 0;
}