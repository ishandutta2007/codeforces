#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 1000 + 5

int Case, n, cnt, A[N], Ans[N][3];

int main()
{
	for (cin >> Case; Case; Case --)
	{
		cin >> n;
		for (int i = 1; i <= n; i ++)
			cin >> A[i];
		cnt = 0;
		for (int i = 1; i <= n; i ++)
		{
			int mn = i;
			for (int j = i; j <= n; j ++)
				if (A[j] < A[mn])
					mn = j;
			if (mn == i)
				continue ;
			cnt ++;
			Ans[cnt][0] = i, Ans[cnt][1] = mn, Ans[cnt][2] = mn - i;
			int mn_val = A[mn];
			for (int j = mn; j > i; j --)
				A[j] = A[j - 1];
			A[i] = mn_val;
		}
		cout << cnt << endl;
		for (int i = 1; i <= cnt; i ++)
			cout << Ans[i][0] << ' ' << Ans[i][1] << ' ' << Ans[i][2] << endl;
	}
	return 0;
}