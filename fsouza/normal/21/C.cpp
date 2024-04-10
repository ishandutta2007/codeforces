#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <numeric>

typedef long long lint;

using namespace std;

int main()
{
	int n;
	
	cin >> n;

	vector <int> A(n);

	for (int i = 0; i < n; i++)
		cin >> A[i];

	int S = accumulate(A.begin(), A.end(), 0);
	lint ret = 0;
	map <int, int> manyway;

	int s = 0;
	for (int j = 0; j+1 < n; j++) {
		s += A[j];

		if ((s%2) == 0 && s/2 == (S-s))
			ret += manyway[s/2];

		manyway[s] ++;
	}

	cout << ret << endl;

	return 0;
}