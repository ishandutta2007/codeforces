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

int main () {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string bulb = "Bulbasaur";
    string text;

    map <char, int> cnt;
    cin >> text;
    for (int i = 0; i < (int) text.size(); i++) {
    	cnt[text[i]]++;
    }

    int ans = 0;
    while (true) {
    	bool flag = true;
    	for (int i = 0; i < (int) bulb.size(); i++) {
    		if (cnt[bulb[i]] == 0) {
    			flag = false;
    		}
    		cnt[bulb[i]]--;
    	}

    	if (flag)
	    	ans++;
    	if (!flag)
    		break;
    }

    cout << ans << endl;

    return 0;
}