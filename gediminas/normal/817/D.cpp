/*input
3
1 4 1

*/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

int main () {
	int n;
	cin >> n;
	long long mas[n] = {};

	for (int i = 0; i < n; i++)
		cin >> mas[i];

	stack<int> S;
	long long prevSmal[n] = {};

	for (int i = 0; i < n; i++) {
		while (!S.empty() && mas[S.top()] >= mas[i])
			S.pop();

		if (S.empty())
			prevSmal[i] = -1;
		else
			prevSmal[i] = S.top();

		S.push(i);
	}
	S=stack<int>();
	long long nextSmal[n] = {};

	for (int i = n - 1; i >= 0; i--) {
		while (!S.empty() && mas[S.top()] > mas[i])
			S.pop();

		if (S.empty())
			nextSmal[i] = n;
		else
			nextSmal[i] = S.top();

		S.push(i);
	}

	S=stack<int>();
	long long prevBig[n] = {};

	for (int i = 0; i < n; i++) {
		while (!S.empty() && mas[S.top()] <= mas[i])
			S.pop();

		if (S.empty())
			prevBig[i] = -1;
		else
			prevBig[i] = S.top();

		S.push(i);
	}

	S=stack<int>();
	long long nextBig[n] = {};

	for (int i = n - 1; i >= 0; i--) {
		while (!S.empty() && mas[S.top()] < mas[i])
			S.pop();

		if (S.empty())
			nextBig[i] = n;
		else
			nextBig[i] = S.top();

		S.push(i);
	}

	long long ats = 0;

	for (int i = 0; i < n; i++) {
		ats -= mas[i]*(nextSmal[i]-i)*(i-prevSmal[i]);
		ats += mas[i]*(nextBig[i]-i)*(i-prevBig[i]);
	}
	cout << ats << endl;

	return 0;
}