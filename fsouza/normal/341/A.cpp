#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/3)
#define MAXN 100000

typedef long long lint;

using namespace std;

lint A[MAXN];

lint gcd(lint a, lint b)
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main(int argc, char ** argv)
{
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> A[i];

	sort(A, A+n);


	lint plusA = 0;
	lint plusB = n;

	for (int i = 0; i < n; i++)
		plusA += A[i]-A[0];


	lint many = n*(n-1)/2;

	lint sum = 0.0;
	lint dsum = 0.0;
	for (int i = 1; i < n; i++) {
		dsum += i * (A[i]-A[i-1]);
		sum += dsum;
	}
	
	double result;

	lint up = (A[0] * n + plusA + 2*sum);
	lint down = n;

	lint g = gcd(up, down);

	up /= g;
	down /= g;

	cout << up << " " << down << endl;

	return 0;
}