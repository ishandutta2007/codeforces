#include <iostream>
#include <cstdio>

#define MAXS 20000006

using namespace std;

typedef long long lint;

int mindiv[MAXS];
char prime[MAXS];
int bla[105];
int n;
lint theval;
lint res;

void go(int i, lint val, int par)
{
	if (val > theval)
		return;
	if (i == n) {
		if (par)
			res += theval/val;
		else
			res -= theval/val;
		return;
	}

	go(i+1, val*bla[i], par^1);
	go(i+1, val, par);
}

int isprime(lint k)
{
	if (k <= 1)
		return 0;
	for (lint k2 = 2; k2*k2 <= k && k2 < k; k2++)
		if (k%k2 == 0)
			return 0;
	return 1;
}

lint solve(lint val, int k)
{
	n = 0;

	for (int i = 2; i < k; i++)
		if (prime[i])
			bla[n++] = i;

	val /= k;
	theval = val;

	res = 0;
	go(0, 1, 0);

	if (res < 0)
		res = -res;

	return res;
}
#if 1
int brute(int a, int b, int k)
{
	int ret = 0;

	for (int i = a; i <= b; i++) {
		if (i%k)
			continue;
		int ok = 1;
		for (int j = 2; j < k; j++)
			if ((i%j) == 0){
				ok = 0;
				break;
			}
		ret += ok;
	}
	return ret;
}
#endif
int main()
{
	for (int i = 0; i < MAXS; i++) {
		prime[i] = 1;
		mindiv[i] = i;
	}
	prime[0] = prime[1] = 0;
	mindiv[1] = 2000000001;

	int i = 2;
		if (prime[i])
			for (lint j = (lint)i*(lint)i; j < (lint)MAXS; j += i) {
				prime[j] = 0;
				mindiv[j] = min(mindiv[j], i);
			}
	for (int i = 3; i < MAXS; i+=2)
		if (prime[i])
			for (lint j = (lint)i*(lint)i; j < (lint)MAXS; j += i) {
				prime[j] = 0;
				mindiv[j] = min(mindiv[j], i);
			}

	lint a, b, k;

	while (cin >> a >> b >> k) {
////printf("Result should be %d\n", brute(a, b, k));
//		printf("%d\n", brute(a,b,k));
//		continue;

		b -= b%k;
		if (a%k) {
			a -= a%k;
			a += k;
		}

		if (!isprime(k)) {
			cout << 0 << endl;
		} else {
			if (k >= 100) {
				int ret = 0;
				a /= k, b /= k;
				for (int i = a; i <= b; i ++)
					if (mindiv[i] >= k)
						ret ++;
				cout << ret << endl;
			} else {
				cout << solve(b,k) - solve(a-1,k) << endl;
			}
		}
	}

	return 0;
}