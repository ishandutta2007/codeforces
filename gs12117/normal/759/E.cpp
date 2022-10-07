#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
int n;
int a[300100];
int b[300100];
int cpay[300100];
int ml;
char mip[10100];
vector<int> md;
int sndp[300100];
const int mod = 1000000007;
const int rdx = 1000000000;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d", &a[i]);
	}
	a[n - 1] = 2;
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	scanf("%s", mip);
	ml = strlen(mip);
	int cm = 0;
	vector<int> rmd;
	for (int i = 0; i < ml; i++) {
		cm *= 10;
		cm += mip[i] - '0';
		if ((ml - i - 1) % 9 == 0) {
			rmd.push_back(cm);
			cm = 0;
		}
	}
	for (int i = rmd.size() - 1; i >= 0; i--) {
		md.push_back(rmd[i]);
	}
	for (int i = 0; i < n - 1; i++) {
		if (a[i] == 1)continue;
		vector<int> nmd;
		nmd.resize(md.size());
		long long int t = 0;
		for (int j = md.size() - 1; j >= 0; j--) {
			t *= rdx;
			t += md[j];
			nmd[j] = t / a[i];
			t %= a[i];
		}
		cpay[i] = t;
		md = nmd;
		while (md[md.size() - 1] == 0)md.pop_back();
	}
	if (md.size() > 1) {
		printf("0");
		return 0;
	}
	else if (md.size() == 1) {
		cpay[n - 1] = md[0];
	}
	vector<int> dp;
	dp.push_back(1);
	for (int i = 0; i < n; i++) {
		vector<int> ndp;
		for (int j = 0; j < dp.size() + b[i]; j++) {
			ndp.push_back(0);
		}
		sndp[0] = 0;
		for (int j = 0; j < dp.size(); j++) {
			sndp[j + 1] = (sndp[j] + dp[j]) % mod;
		}
		for (int j = 0; j < ndp.size(); j++) {
			int l, r;
			l = j - b[i];
			r = j + 1;
			if (l < 0)l = 0;
			if (r > dp.size())r = dp.size();
			ndp[j] = (sndp[r] + mod - sndp[l]) % mod;
		}
		if (a[i] == 1)dp = ndp;
		else {
			dp.clear();
			for (long long int j = 0; j*a[i] + cpay[i] < ndp.size(); j++) {
				dp.push_back(ndp[j*a[i] + cpay[i]]);
			}
			if (dp.size() == 0) {
				printf("0");
				return 0;
			}
		}
	}
	if (dp.size() == 0) {
		printf("0");
		return 0;
	}
	printf("%d", dp[0]);
	return 0;
}