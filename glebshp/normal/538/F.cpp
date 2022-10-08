#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 300 * 1000 + 100;

int sum[size];
int heap[size];
int der[size];
int help[size];
int n;

int getstupid(int k) {
	int ans = 0;
	for (int i = 2; i <= n; i++) {
		ans += heap[(i + k - 2) / k] > heap[i];
	}

	return ans;
}

int main() {
/*
	freopen("input.txt", "w", stdout);
	int n = 200 * 1000;
	cout << n << endl;
	for (int i = 0; i < n; i++)
		cout << rand() << ' ';
	cout << endl;
	return 0;
*/
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    	scanf("%d", &heap[i]);

    for (int i = 2; i <= n; i++) {
    	int cnt = 0;
    	int mid = 1;
    	while (i + mid - 2 >= mid * mid)
    		mid++;
    	mid--;

    	for (int j = 1; j <= mid; j++)
    		help[cnt++] = j;
    	for (int j = mid; j >= 1; j--) {
    		int nv = (i + j - 2) / j;
    		if (help[cnt - 1] != nv)
    			help[cnt++] = nv;
    	}

    	int lst = n + 1;
    	for (int j = 0; j < cnt; j++) {
    		int npoint;
            //if (help[j] == 1)
            //	npoint = i - 1;
            //else
      			npoint = (i - 1 + help[j] - 1) / (help[j]);
    		//cerr << i << ' ' << help[j] << ' ' << npoint << ' ' << lst << endl;
    		if (heap[help[j]] > heap[i]) {
    			der[npoint]++;
    			der[lst]--;
    		}
    		lst = npoint;
    	}
    }

    int cur = 0;
    for (int i = 0; i <= n + 1; i++) {
    	cur += der[i];
    	sum[i] = cur;
    }

 //   for (int i = 1; i <= n; i++) {
 //   	printf("%d %d\n", sum[i], getstupid(i));
 //   	assert(sum[i] == getstupid(i));
  //  }
    for (int i = 1; i < n; i++) {
    	printf("%d%c", sum[i], " \n"[i == n]);
    }

    //cerr << (clock() + 0.0) / CLOCKS_PER_SEC << endl;

    return 0;
}