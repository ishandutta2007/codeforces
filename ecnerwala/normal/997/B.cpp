#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int res[130] = {1,
 4,
 10,
 20,
 35,
 56,
 83,
 116,
 155,
 198,
 244,
 292,
 341,
 390,
 439,
 488,
 537,
 586,
 635,
 684,
 733,
 782,
 831,
 880,
 929,
 978,
 1027,
 1076,
 1125,
 1174,
 1223,
 1272,
 1321,
 1370,
 1419,
 1468,
 1517,
 1566,
 1615,
 1664,
 1713,
 1762,
 1811,
 1860,
 1909,
 1958,
 2007,
 2056,
 2105,
 2154,
 2203,
 2252,
 2301,
 2350,
 2399,
 2448,
 2497,
 2546,
 2595,
 2644,
 2693,
 2742,
 2791,
 2840,
 2889,
 2938,
 2987,
 3036,
 3085,
 3134,
 3183,
 3232,
 3281,
 3330,
 3379,
 3428,
 3477,
 3526,
 3575,
 3624,
 3673,
 3722,
 3771,
 3820,
 3869,
 3918,
 3967,
 4016,
 4065,
 4114,
 4163,
 4212,
 4261,
 4310,
 4359,
 4408,
 4457,
 4506,
 4555,
 4604,
 4653,
 4702,
 4751,
 4800,
 4849,
 4898,
 4947,
 4996,
 5045,
 5094,
 5143,
 5192,
 5241,
 5290,
 5339,
 5388,
 5437,
 5486,
 5535,
 5584,
 5633,
 5682,
 5731,
 5780,
 5829,
 5878,
 5927,
 5976,
 6025,
 6074};

int main() {
	ll N;
	cin >> N;
	if (N < 100) {
		cout << res[N] << '\n';
	} else {
		cout << res[100] + ll(N - 100) * 49 << '\n';
	}

	return 0;
}