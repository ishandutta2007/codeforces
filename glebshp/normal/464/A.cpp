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

int n, p;
string str;
char final;

bool couldinc(string str) {
	for (int i = 0; i < (int) str.size(); i++)
  		if (str[i] != final)
	    	return true;
    return false;
}

void doinc(string& str) {
	for (int i = (int) str.size() - 1; i >= 0; i--) {
 		if (str[i] == final) {
 			str[i] = 'a';
 		} else {
 			str[i]++;
 			return;
 		}
  	}
}

bool check(string& str) {
	for (int i = 0; i < (int) str.size() - 1; i++) {
		if (str[i] == str[i + 1])
			return false;
		if (i > 0 && str[i - 1] == str[i + 1])
			return false;
	}

	return true;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    cin >> n >> p >> str;
    for (int i = n - 1; i >= 0; i--) {
    	for (int j = 0; j < p; j++) {
    		if (j > str[i] - 'a' && (i == 0 || j != str[i - 1] - 'a') && (i <= 1 || j != str[i - 2] - 'a')) {
    			str[i] = char('a' + j);
    			for (int k = i + 1; k < n; k++) {
    				for (int j = 0; j < p; j++) {
    					if ((k == 0 || j != str[k - 1] - 'a') && (k <= 1 || j != str[k - 2] - 'a')) {
    		            	str[k] = char('a' + j);
    		            	break;
    		            }
    				}
    			}	
    			cout << str << endl;
    			return 0;
    		}
    	}
    }

    cout << "NO" << endl;

    return 0;
}