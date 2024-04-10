#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>


using namespace std;



int n, m;
queue<int> q;
int d[100001];
bool used[100001];


int main() {
	cin >> n >> m;
	q.push(n);
	used[n] = true;
	memset(d, 0, sizeof(d));
	d[n] = 0;
	while (!used[m]) {
		int l = q.front();
		q.pop();
		if (l >= 1) {
			if (!used[l - 1]) {
				d[l - 1] = d[l] + 1;
				used[l - 1] = true;
				q.push(l - 1); 
			}
		} 
		if (l * 2 <= 100000) {
			if (!used[l * 2]) {
				d[l * 2] = d[l] + 1;
				used[l * 2] = true;
				q.push(l * 2);
			}
		}
	}
	cout << d[m] << endl;
    return 0;
}