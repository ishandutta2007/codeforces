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

map <string, int> ans;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    int ansval = 1;

    ans["polycarp"] = 1;
    for (int i = 0; i < n; i++) {
    	string s1, s2, h;
    	cin >> s1 >> h >> s2;
    	for (int j = 0; j < (int) s1.size(); j++)
    		s1[j] = tolower(s1[j]);
    	for (int j = 0; j < (int) s2.size(); j++)
    		s2[j] = tolower(s2[j]);
    
    	ans[s1] = ans[s2] + 1;
    	ansval = max(ansval, ans[s1]);
    }

    cout << ansval << endl;

    return 0;
}