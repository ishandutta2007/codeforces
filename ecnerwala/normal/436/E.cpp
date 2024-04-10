#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
#define A first
#define B second

const int MAXN = 6e5;

const int S = 2;

int N;
int W;
pii cost[MAXN];

long long totCost = 0;
int res[MAXN];

priority_queue<pii> downgrade;
priority_queue<pii, vector<pii>, greater<pii> > upgrade, insert;

int main() {
	cin >> N >> W;
	for(int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		cost[i] = pii(a, b);
	}

	for(int i = 0; i < N; i++) {
		upgrade.push(pii(cost[i].A, i));
		insert.push(pii(cost[i].B, i));
	}

	for(int i = 0; i < W; i++) {
		while(!upgrade.empty()) {
			int t = upgrade.top().B;
			int c = upgrade.top().A;
			if(res[t] == 2) {
				upgrade.pop();
				continue;
			} else if(res[t] == 1) {
				if(c != cost[t].B - cost[t].A) {
					upgrade.pop();
					continue;
				}
			} else {
				if(c != cost[t].A) {
					upgrade.pop();
					continue;
				}
			}
			break;
		}
		while(!insert.empty()) {
			int t = insert.top().B;
			int c = insert.top().A;
			if(res[t] != 0) {
				insert.pop();
				continue;
			} else {
				if(c != cost[t].B) {
					insert.pop();
					continue;
				}
			}
			break;
		}
		while(!downgrade.empty()) {
			int t = downgrade.top().B;
			int c = downgrade.top().A;
			if(res[t] == 0) {
				downgrade.pop();
				continue;
			} else if(res[t] == 2) {
				if(c != cost[t].B - cost[t].A) {
					downgrade.pop();
					continue;
				}
			} else {
				if(c != cost[t].A) {
					downgrade.pop();
					continue;
				}
			}
			break;
		}
		bool upg = true;
		int cst = upgrade.top().A;
		if(!downgrade.empty() && !insert.empty()) {
			int cnd = insert.top().A - downgrade.top().A;
			if(cnd < cst) cst = cnd, upg = false;
		}
		totCost += cst;
		if(upg) {
			downgrade.push(upgrade.top());
			int t = upgrade.top().B;
			upgrade.pop();
			res[t] ++;
			if(res[t] == 1) {
				upgrade.push(pii(cost[t].B - cost[t].A, t));
			}
			//cerr << "insert " << t << '\n';
		} else {
			upgrade.push(downgrade.top());
			int d = downgrade.top().B;
			downgrade.pop();
			res[d] --;
			if(res[d] == 0) {
				insert.push(pii(cost[d].B, d));
			}

			int t = insert.top().B;
			assert(res[t] == 0);
			res[t] += 2;
			downgrade.push(pii(cost[t].B - cost[t].A, t));
			//cerr << "insert " << t <<  " remove " << d << '\n';
		}
	}

	cout << totCost << '\n';
	for(int i = 0; i < N; i++) {
		cout << res[i];
	}
	cout << '\n';
	return 0;
}