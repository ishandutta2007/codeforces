/*input
11
5 4 5 5 6 7 8 8 8 7 6
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;

	int sk[n];

	for (int i = 0; i < n; i++)
		cin >> sk[i];

	int p0 = 0, p1 = 0;

	int buv = 0;
	int ats = 0;

	multiset<int> elem;

	while (p0 < n) {
		while (p1 < n and (elem.size()==0 or *(--elem.end()) - *elem.begin() <= 1))
			elem.insert(sk[p1++]);

		//cout << elem.size() << endl;

		ats = max(ats, (int)elem.size()-(*(--elem.end()) - *elem.begin() > 1));
		elem.erase(elem.find(sk[p0++]));

		while (p0<n and elem.size()>0 and * (--elem.end()) - *elem.begin() > 1)
			elem.erase(elem.find(sk[p0++]));
	}

	cout << ats;

	return 0;
}