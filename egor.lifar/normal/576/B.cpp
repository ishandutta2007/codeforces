#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <math.h>
#include <string.h>
#include <cstring>


using namespace std;


int n;
int p[100001];
vector<int> v[100001];
bool used[100001];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		p[i]--;
	}
	for (int i = 0; i < n; i++) {
		if (p[i] == i) {
			cout << "YES" << endl;
			for (int j = 0; j < n; j++) {
				if (j != i) {
					printf("%d %d\n", j + 1, i + 1);
				}
			}
			return 0;
		}
	}
	int l = 0;
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			used[i] = true;
			int i1 = i;
			v[l].push_back(i);
			while (p[i1] != i) {
				i1 = p[i1];
				used[i1] = true;
				v[l].push_back(i1);
			}
			l++;
		}
	}
	for (int i = 0; i < l; i++) {
		if ((int)v[i].size() % 2 == 1) {
			cout << "NO" << endl;
			return 0;
		}
	}
	for (int i = 0; i < l; i++) {
		if ((int)v[i].size() == 2) {
			cout << "YES" << endl;
			cout << v[i][0] + 1 << ' ' << v[i][1] + 1 << endl;
			for (int j = 0; j < l; j++) {
				if (j != i) {
					for (int g = 0; g < (int)v[j].size(); g++) {
						int h = v[j][g];
						if (g % 2 == 0) {
							printf("%d %d\n", h + 1, v[i][0] + 1); 
						} else {
							printf("%d %d\n", h + 1, v[i][1] + 1); 
						}
					}
				}
			}
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}