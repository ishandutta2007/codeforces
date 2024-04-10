#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector <bool> used(n + 1);
	for (int i = 0; i < n; i++)
		used[a[i]] = true;
	int nech = 0, chet = 0;
	for (int i = 1; i <= n; i += 2)
		nech += (used[i] == false);
	for (int i = 2; i <= n; i += 2)
		chet += (used[i] == false);
	vector <int> nene, chch;
	int cnt = 0;
	int i = 0;
	while (i < n && a[i] == 0)
		i++;
	int left = i;
	i++;
	for (; i < n; i++) {
		if (a[i] == 0)
			continue;
		if (a[i] != 0) {
			if (a[i] % 2 == 1 && a[left] % 2 == 1) {
				nene.push_back(i - left - 1);
				left = i;
				continue;
			}
			if (a[i] % 2 == 0 && a[left] % 2 == 0) {
				chch.push_back(i - left - 1);
				left = i;
				continue;
			}
			left = i;
			cnt++;
		}
	}
	sort(nene.begin(), nene.end());
	sort(chch.begin(), chch.end());
	int uk = 0;
	for (int i = 0; i < nene.size(); i++) {
		if (nech < nene[i]) {
			cnt += (nene.size() - i) * 2;
			break;
		}
		nech -= nene[i];
	}
	for (int i = 0; i < chch.size(); i++) {
		if (chet < chch[i]) {
			cnt += (chch.size() - i) * 2;
			break;
		}
		chet -= chch[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] != 0) {
			if (a[i] % 2 == 0 && chet < i)
				cnt++;
			if (a[i] % 2 == 1 && nech < i)
				cnt++;
			break;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] != 0) {
			if (a[i] % 2 == 0 && chet < n - i - 1)
				cnt++;
			if (a[i] % 2 == 1 && nech < n - i - 1)
				cnt++;
			break;
		}
	}
	if (n == 1)
		cout << 0;
	else
		cout << max(cnt, 1) << endl;
	return 0;
}