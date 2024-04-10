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

const int size = 1000 * 1000 + 100;

int clrs;
int lb[size], rb[size];
int clr[2][size];

set <pair <long long, int> > cs[2];

int w, h, n;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &w, &h, &n);
    
    for (int i = 0; i < w; i++)
    	clr[0][i] = 0;
    for (int i = 0; i < h; i++)
    	clr[1][i] = 1;

    clrs = 2;
    lb[0] = 0;
    rb[0] = w - 1;
    lb[1] = 0;
    rb[1] = h - 1;

    cs[0].insert(mp(w, 0));
    cs[1].insert(mp(h, 1));

    for (int i = 0; i < n; i++) {
    	char tp;
    	int val;
    	scanf(" %c %d", &tp, &val);

    	int ptr = (tp == 'H');
    	int cur = clr[ptr][val];
    	cs[ptr].erase(mp(rb[cur] - lb[cur] + 1, cur));

    	int ncur = clrs++;
    	if (val - lb[cur] > rb[cur] - val + 1) {
    		lb[ncur] = val;
    		rb[ncur] = rb[cur];
    		rb[cur] = val - 1;
    		for (int j = lb[ncur]; j <= rb[ncur]; j++)
    			clr[ptr][j] = ncur;
   		} else {
   			lb[ncur] = lb[cur];
   			rb[ncur] = val - 1;
   			lb[cur] = val;
   			for (int j = lb[ncur]; j <= rb[ncur]; j++)
   				clr[ptr][j] = ncur;
   		}

   		cs[ptr].insert(mp(rb[cur] - lb[cur] + 1, cur));
   		cs[ptr].insert(mp(rb[ncur] - lb[ncur] + 1, ncur));

    	printf("%I64d\n", cs[0].rbegin()->fs * cs[1].rbegin()->fs);
    }

    return 0;
}