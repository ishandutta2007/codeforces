#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int size = 1000 * 1000 + 100;

int p[size];
int b[size];
int n;
bool used[size];

int main () {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
    	scanf("%d", &p[i]);
    	p[i]--;
    }

    int odd = 0;
    for (int i = 0; i < n; i++) {
    	scanf("%d", &b[i]);
    	odd ^= b[i];
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
		if (!used[i]) {
			used[i] = true;
			int cur = p[i];
			while (cur != i) {
				used[cur] = true;
				cur = p[cur];
			}

			cnt++;
		}    	
    }

    int tojoin = 0;
    if (cnt > 1) {
    	tojoin = cnt;
    }

    cout << tojoin + (1 - odd) << endl;

    return 0;
}