/*input
6 10
7 4 7
5 8 8
12 5 8
6 11 6
3 3 7
5 9 6
*/
#include <bits/stdc++.h>

using namespace std;

struct zmog {
	long long s, a, b;
};

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0);
	long long n, s;
	cin >> n >> s;
	long long sum = 0;
	zmog mas[n];

	for (int i = 0; i < n; i++) {
		cin >> mas[i].s >> mas[i].a >> mas[i].b;
		sum += mas[i].s;
	}

	long long m = sum / s;

	if (sum % s > 0)
		m++;

	long long galim = m * s - sum;

	sort(mas, mas + n, [](const auto & i, const auto & j) -> bool {
		return i.a - i.b > j.a - j.b;
	});

	long long ats1 = 0;
	long long lik = 0;
	int i = 0;

	while (i < n and mas[i].a > mas[i].b) {
		ats1 += mas[i].s * mas[i].a;

		if ((mas[i].s - lik + s) % s > 0)
			lik = s - (mas[i].s - lik + s) % s;
		else
			lik = 0;

		i++;
	}

	while (i < n and lik > galim) {
		if (mas[i].s < lik - galim) {
			ats1 += mas[i].s * mas[i].a;
			lik = lik - mas[i].s;
		}
		else {
			ats1 += (lik - galim) * mas[i].a;
			ats1 += (mas[i].s - lik + galim) * mas[i].b;
			lik = 0;
		}

		i++;
	}

	while (i < n) {
		ats1 += mas[i].s * mas[i].b;
		i++;
	}

	lik = 0;
	long long ats3 = 0;
	i = 0;

	while (i < n and mas[i].a >= mas[i].b) {
		ats3 += mas[i].s * mas[i].a;

		if ((mas[i].s - lik + s) % s > 0)
			lik = s - (mas[i].s - lik + s) % s;
		else
			lik = 0;

		i++;
	}

	while (i < n and lik > galim) {
		if (mas[i].s < lik - galim) {
			ats3 += mas[i].s * mas[i].a;
			lik = lik - mas[i].s;
		}
		else {
			ats3 += (lik - galim) * mas[i].a;
			ats3 += (mas[i].s - lik + galim) * mas[i].b;
			lik = 0;
		}

		i++;
	}

	while (i < n) {
		ats3 += mas[i].s * mas[i].b;
		i++;
	}

	for (int i = 0; i < n; i++)
		swap(mas[i].a, mas[i].b);

	sort(mas, mas + n, [](const auto & i, const auto & j) -> bool {
		return i.a - i.b > j.a - j.b;
	});

	long long ats2 = 0;
	lik = 0;
	i = 0;

	while (i < n and mas[i].a > mas[i].b) {
		ats2 += mas[i].s * mas[i].a;

		if ((mas[i].s - lik + s) % s > 0)
			lik = s - (mas[i].s - lik + s) % s;
		else
			lik = 0;

		i++;
	}

	while (i < n and lik > galim) {
		if (mas[i].s < lik - galim) {
			ats2 += mas[i].s * mas[i].a;
			lik = lik - mas[i].s;
		}
		else {
			ats2 += (lik - galim) * mas[i].a;
			ats2 += (mas[i].s - lik + galim) * mas[i].b;
			lik = 0;
		}

		i++;
	}

	while (i < n) {
		ats2 += mas[i].s * mas[i].b;
		i++;
	}

	lik = 0;
	long long ats4 = 0;
	i = 0;

	while (i < n and mas[i].a >= mas[i].b) {
		ats4 += mas[i].s * mas[i].a;

		if ((mas[i].s - lik + s) % s > 0)
			lik = s - (mas[i].s - lik + s) % s;
		else
			lik = 0;

		i++;
	}

	while (i < n and lik > galim) {
		if (mas[i].s < lik - galim) {
			ats4 += mas[i].s * mas[i].a;
			lik = lik - mas[i].s;
		}
		else {
			ats4 += (lik - galim) * mas[i].a;
			ats4 += (mas[i].s - lik + galim) * mas[i].b;
			lik = 0;
		}

		i++;
	}

	while (i < n) {
		ats4 += mas[i].s * mas[i].b;
		i++;
	}


	cout << max({ats1, ats2, ats3, ats4});



	return 0;
}