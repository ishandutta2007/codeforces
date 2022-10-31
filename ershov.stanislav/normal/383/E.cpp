#include <iostream>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

int n, cnt[1<<24], res;
char c[4];

int main() {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin>>c;
		int mask=0;
		for (int j=0; j<3; j++) mask|=1<<(c[j]-'a');
		cnt[mask]++;
	}
	for (int i=0; i<24; i++) for (int j=0; j<(1<<24); j++) if (j&(1<<i)) cnt[j]+=cnt[j^(1<<i)];
	for (int i=0; i<(1<<24); i++) res^=(n-cnt[i])*(n-cnt[i]);
	cout << res;
	return 0;
}