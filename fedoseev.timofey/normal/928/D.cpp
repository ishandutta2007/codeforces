#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

int ans = 0;

struct node {
    node *next[26];

    int strings;
    bool end;
    node() {
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
        strings = 0;
        end = false;
    }
};

node *root = new node();

void add(const string& s) {
    node *cur_v = root;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (cur_v->next[c - 'a'] == nullptr) {
            cur_v->next[c - 'a'] = new node();
        }
        cur_v = cur_v->next[c - 'a'];
        ++cur_v -> strings;
    }

    cur_v->end = true;
}

bool has(const string& s) {
    node *cur_v = root;
    for (int i = 0; i < s.size(); i++) {
        cur_v = cur_v->next[s[i] - 'a'];
        if (cur_v == nullptr) {
            return false;
        }
    }

    return cur_v->end;
}

void count(const string &s) {
	bool used = false;
	node *cur_v = root;
	for (int i = 0; i < s.size(); ++i) {
		++ans;
		if (cur_v->next[s[i] - 'a']){
			cur_v = cur_v->next[s[i] - 'a'];
		}
		else {
			ans += s.size() - i - 1;
			break;
		}
		if (cur_v->strings == 1 && !cur_v->end && !used) {
			node *tmp = cur_v;
			bool fl = true;
			for (int j = i + 1; j < s.size(); ++j) {
				if (cur_v->next[s[j] - 'a']) {
					cur_v = cur_v->next[s[j] - 'a'];
				}
				else if (cur_v->end) {
					i = j - 1;
					++ans;
					fl = false;
					break;
				}
				else {
					cur_v = tmp;
					fl = false;
					break;
				}
			}
			if (fl && cur_v->end) {
				++ans;
				break;
			}
			used = 1;
		}
	}
	if (!has(s)) {
		add(s);
	}
}

bool separator(char c) {
	if (c == '.' || c == ',' || c == '?' || c == '!' || c == '\'' || c == '-' || c == ' ') {
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	string buffer;
	vector <string> a;
	while (getline(cin, buffer)) {
		++ans;
		a.push_back(buffer);
	}
	vector <string> words;
	for (auto &s : a) {
		int l = 0;
		for (int r = 0; r < s.size(); ++r) {
			if (separator(s[r])) {  
				string cur = s.substr(l, r - l);
				if (cur.size() != 0) {
					words.push_back(cur);
				}
				++ans;
				l = r + 1;
			}
		}
		string cur = s.substr(l, s.size() - l);
		if (cur.size() != 0) {
			words.push_back(cur);
		}
	}
	for (auto s : words) {
		count(s);
	}
	cout << ans << endl;
}