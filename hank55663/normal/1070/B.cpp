#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
struct node {
	int tp;
	node* ch[2];
	node() {
		tp = 0;
		ch[0] = ch[1] = NULL;
	}
};
struct IP {
	unsigned int ip;
	int tp, ms;
} ips[N];
vector<pair<unsigned int, int>> ans;
int insert(node*& now, const IP& ip, int dep) {
//	cout << "ins " << dep << endl;
	if (now == NULL) {
		now = new node();
	}
//	cout << "ins2 " << dep << endl;
	if (now->tp && now->tp != ip.tp) {
		return 0;
	}
//	cout << "ins3 " << dep << endl;
	if (dep == ip.ms) {
		now->tp = ip.tp;
		return 1;
	}
//	cout << "ins4 " << dep << endl;
	int nx = ((ip.ip >> (31-dep)) & 1);
	return insert(now->ch[nx], ip, dep+1);
}
int getTp(node* now) {
	if (!now)
		return 0;
	return now->tp;
}
int merge(node* now, unsigned int ip, int ms) {
//	cout << "meg " << ms <<endl;
	if (!now || now->tp)
		return 0;
	merge(now->ch[0], ip, ms + 1);
	merge(now->ch[1], ip | (1 << (31-ms)), ms + 1);
	int tp0 = getTp(now->ch[0]);
	int tp1 = getTp(now->ch[1]);
	if (tp0 == 0 && tp1 == 0) {
		return 0;
	}
	if (tp0 != 0 && tp1 != 0) {
		if (tp0 != tp1) {
			now->tp = 1; // good
			if (tp0 == 2) {
				ans.push_back(make_pair(ip, ms+1));
			} else {
				ans.push_back(make_pair(ip| (1 << (31-ms)), ms+1));
			}
		} else {
			now->tp = tp0;
		}
		return 0;
	}
	now->tp = (tp0 != 0 ? tp0 : tp1);
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
//	cout << "st" << endl;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
	//	cout << "in : " << s << endl;
		stringstream ss(s);
		char c;
		ss >> c;
		ips[i].tp = (c == '+' ? 1 : 2);
		ips[i].ip = 0;
		for (int j = 3; j >= 0; --j) {
			unsigned int x;
			ss >> x;
			ips[i].ip |= (x << (8*j));
			ss >> c;
		}
		ips[i].ms = 32;
		if (ss) {
			ss >> ips[i].ms;
		}
	}
//	cout << "inped" << endl;
	sort(ips, ips+n, [](const IP&a,const IP&b) {
		return a.ms == b.ms ? a.ip < b.ip : a.ms < b.ms;
	});
//	cout << "sored" << endl;
	node* root = NULL;
	int flag = 0;
	for (int i = 0; i < n; ++i) {
		if (insert(root, ips[i], 0) == 0) {
			flag = 1;
			break;
		}
	}
//	cout << "insed" << endl;
	if (!flag) {
		ans.clear();
		merge(root,0,0);
	//	cout << "meged" << endl;
		// bad
		if (root->tp == 2) {
			ans.push_back(make_pair(0,0));
		}
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); ++i) {
			unsigned int ip = ans[i].first;
			int ms = ans[i].second;
			cout << (ip>>24) << "." << ((ip >> 16) & 0xff) << "."
				 << ((ip >> 8 ) & 0xff) << "." << (ip & 0xff) << "/"
				 << ms << "\n";
		}
	} else {
		cout << -1 << endl;
	}
}