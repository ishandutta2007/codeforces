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

const int size = 2000 * 1000 + 100;
const long long mdl = 1000 * 1000 * 1000 + 7;

int n, m;
set <int> eq[size];
int myclass[size];
long long fact[size];

int main () {
	fact[0] = 1;
	for (int i = 1; i < size; i++) {
		fact[i] = (fact[i - 1] * i) % mdl;
	}

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);
    
    for (int i = 0; i < m; i++) {
    	myclass[i] = 0;
    	eq[0].insert(i);
    }
    int cur = 1;

    for (int i = 0; i < n; i++) {
    	int k;
   		scanf("%d", &k);	 	
   		map <int, int> cnt;
   		for (int j = 0; j < k; j++) {
   			int d;
   			scanf("%d", &d);
   			d--;
   			cnt[d]++;
   		}
   		map <int, vector <int> > tosplit;
   		for (auto& e : cnt) {
   			tosplit[e.sc].pb(e.fs);
   		}

   		for (auto& e : tosplit) {
   			map <int, vector <int> > help;
   			for (int i = 0; i < (int) e.sc.size(); i++) {
   				help[myclass[e.sc[i]]].pb(e.sc[i]);
   			}	
   			for (auto& e2 : help) {
   				for (auto& num : e2.sc) {
   					eq[myclass[num]].erase(num);
   					myclass[num] = cur;
					eq[cur].insert(num);   					
   				}
   				cur++;
   			}
   		}
    }

    long long rans = 1;
    for (int i = 0; i < cur; i++) {
    	rans = (rans * fact[eq[i].size()]) % mdl;
    }

    cout << rans << endl;

    return 0;
}