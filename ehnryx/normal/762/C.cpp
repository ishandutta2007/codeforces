#include <bits/stdc++.h>
using namespace std;

int main() {
	string a, b;
	cin >> a;
	cin >> b;
	//
	
	vector<int> forward;
	vector<int> backward;
	int frontp, backp, frontlen, backlen;
	frontp = 0; backp = a.size()-1;
	for (int i = 0; i < b.size(); i++) {
		while (a[frontp] != b[i] && frontp < a.size())
			frontp++;
		if (frontp == a.size())
			break;
		else {
			forward.push_back(frontp);
			frontp++;
		}
	}
	for (int i = b.size()-1; i >= 0; i--) {
		while (a[backp] != b[i] && backp >= 0)
			backp--;
		if (backp < 0)
			break;
		else {
			backward.push_back(backp);
			backp--;
		}
	}
	frontlen = forward.size();
	backlen = backward.size();
	frontp = 0; backp = backlen-1;
	int maxfpos, maxbpos, maxsize;
	if (frontlen > backlen) {
		maxsize = frontlen;
		maxfpos = frontlen-1;
		maxbpos = -1;
	} 
	else {
		maxsize = backlen;
		maxfpos = -1;
		maxbpos = backlen-1;
	}
	while (frontp < frontlen) {
		while (backp >= 0 && forward[frontp] >= backward[backp])
			backp--;
		if (backp < 0)
			break;
		else {
			if (frontp + backp + 2 > maxsize) {
				maxsize = frontp + backp + 2;
				maxfpos = frontp;
				maxbpos = backp;
			}
		}
		frontp++;
	}
	if (maxsize == 0) {
		cout << "-" << endl;
	}
	else if (maxsize > b.size()) {
		cout << b << endl;
	}
	else {
		for (int i = 0; i <= maxfpos; i++)
			cout << a[forward[i]];
		for (int i = maxbpos; i >= 0; i--) 
			cout << a[backward[i]];
		cout << endl;
	}
	
	return 0;
}