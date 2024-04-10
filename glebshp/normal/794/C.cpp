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

int cfirst[size];
int csecond[size];

char ans[size];
char buf1[size];
char buf2[size];

char getminfirst() {
	for (char c = 'a'; c <= 'z'; c++)
		if (cfirst[c] > 0)
			return c;

	return 'z';
}

char getminsecond() {
	for (char c = 'a'; c <= 'z'; c++)
		if (csecond[c] > 0)
			return c;

	return 'z';
}

char getmaxfirst() {
	for (char c = 'z'; c >= 'a'; c--)
		if (cfirst[c] > 0)
			return c;

	return 'z';
}

char getmaxsecond() {
	for (char c = 'z'; c >= 'a'; c--) {
	//	cerr << c << ' ' << csecond[c] << endl;
		if (csecond[c] > 0)
			return c;
	}

	return 'z';
}


int main () {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%s", buf1);
    int n = strlen(buf1);
    scanf("%s", buf2);
    for (int i = 0; i < n; i++) {
    	cfirst[buf1[i]]++;
    	csecond[buf2[i]]++;
    }

    set <int> freepos;
    for (int i = 0; i < n; i++) {
    	freepos.insert(i);
    }

    int cnt = 0;

    int firsttoplace = n / 2;
    for (char c = 'z'; c >= 'a'; c--) {
    	while (firsttoplace > 0 && cfirst[c] > 0) {
    		firsttoplace--;
    		cfirst[c]--;
    	}
    }

    int secondtoplace = (n + 1) / 2;
    for (char c = 'a'; c <= 'z'; c++) {
    	while (secondtoplace > 0 && csecond[c] > 0) {
    		secondtoplace--;
    		csecond[c]--;
    	}
    }


    for (int i = 0; i < n; i++) {
    	char c1 = getminfirst();
    	char c2 = getmaxsecond();
  //  	cerr << c1 << ' ' << c2 << endl;

    	if (c1 < c2) {
    		ans[*freepos.begin()] = c1;
    		cfirst[c1]--;
    		freepos.erase(freepos.begin());
    	} else {
    		c1 = getmaxfirst();
    		ans[*freepos.rbegin()] = c1;
    		cfirst[c1]--;
    		freepos.erase(*freepos.rbegin());
    	}

    	cnt++;
    	if (cnt == n)
    		break;

    	c1 = getminfirst();
    	c2 = getmaxsecond();

//    	cerr << c1 << ' ' << c2 << endl;
    	if (c2 > c1) {
    		ans[*freepos.begin()] = c2;
    		csecond[c2]--;
    		freepos.erase(freepos.begin());
    	} else {
    		c2 = getminsecond();
    		ans[*freepos.rbegin()] = c2;
    		csecond[c2]--;
    		freepos.erase(*freepos.rbegin());
    	}

    	cnt++;
    	if (cnt == n)
    		break;
    }

    printf("%s\n", ans);

    return 0;
}