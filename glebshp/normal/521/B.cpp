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
const long long mdl = 1000 * 1000 * 1000 + 9;

int x[size], y[size];
int under[size];
bool vital[size];
int n;

map <pair <int, int>, int> num;
set <int> could;

void checkvital(int i) {
	vital[i] = false;
	could.erase(i);
	for (int j = -1; j <= 1; j++) {
		if (num.find(mp(x[i] + j, y[i] + 1)) != num.end()) {
			vital[i] = vital[i] || (under[num[mp(x[i] + j, y[i] + 1)]] == 1);
		}     	
	}    


	if (!vital[i]) {
		could.insert(i);
	}
}

void calcunder(int i) {
    under[i] = 0;
  	for (int j = -1; j <= 1; j++) {
   		under[i] += (num.find(mp(x[i] + j, y[i] - 1)) != num.end());
   	}
}


int main() {
/*
    freopen("input.txt", "w", stdout);
    vector <pair <int, int> > cells;
    for (int i = 0; i < 400; i++)
    	for (int j = 0; j < 400; j++) {
    		cells.pb(mp(i, j));
    	}
    random_shuffle(cells.begin(), cells.end());
    printf("%d\n", (int) cells.size());
    for (int i = 0; i < (int) cells.size(); i++)
    	printf("%d %d\n", cells[i].fs, cells[i].sc);
    return 0;
  */ 
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
    	scanf("%d%d", &x[i], &y[i]);

    	num[mp(x[i], y[i])] = i;
    }

    for (int i = 0; i < n; i++) {
    	calcunder(i);
    }

    long long ans = 0;

    for (int i = 0; i < n; i++) {
    	checkvital(i);
    }

    for (int i = 0; i < n; i++) {

    	assert(!could.empty());
    	int cur;
    	if (i % 2 == 0)
    		cur = *could.rbegin();
    	else
    		cur = *could.begin();
//    	cerr << cur << endl;


    	ans = (ans * 1ll * n + cur) % mdl;

		could.erase(cur);
		num.erase(mp(x[cur], y[cur]));

		for (int j = -1; j <= 1; j++) {
			if (num.find(mp(x[cur] + j, y[cur] + 1)) != num.end())
				calcunder(num[mp(x[cur] + j, y[cur] + 1)]);
		}
        for (int j = -2; j <= 2; j++) {
        	if (num.find(mp(x[cur] + j, y[cur])) != num.end())
        		checkvital(num[mp(x[cur] + j, y[cur])]);
        }
        for (int j = -1; j <= 1; j++) {
        	if (num.find(mp(x[cur] + j, y[cur] - 1)) != num.end())
        		checkvital(num[mp(x[cur] + j, y[cur] - 1)]);	
        }
    }

    cout << ans << endl;
    //cerr << (clock() + 0.0) / CLOCKS_PER_SEC << endl; 

    return 0;
}