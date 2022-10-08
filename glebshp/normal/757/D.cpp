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

const int size = 20;
const int lsize = 76;
const int mdl = 1000 * 1000 * 1000 + 7;

int n;
string str;
int ans[lsize][1 << size];
int val[lsize][lsize];

int main () {
	/*
	freopen("input.txt", "w", stdout);
	int n = 75;
	cout << n << endl;
	for (int i = 0; i < n; i++)
		cout << char('0' + rand() % 2);
	cout << endl;
	return 0;
	*/	

//    freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    cin >> n >> str;
    for (int i = 0; i < n; i++)
    	for (int j = 0; j < n; j++)
    		val[i][j] = -1;
    for (int i = 0; i < n; i++) {
    	int num = 0;
    	for (int j = i; j < n; j++) {
    		num = num * 2 + (str[j] - '0');
    		if (num > size)
    			break;
    		if (num > 0)
	    		val[i][j] = num;		 
    	}
    }

    for (int i = 0; i <= n; i++)
    	ans[i][0] = 1;
    for (int i = 0; i <= n; i++) {
    	for (int j = 0; j < (1 << size); j++) {
    		if (ans[i][j]) {
    			for (int k = i + 1; k <= n; k++) {
    				int tval = val[i][k - 1] - 1;
    				if (tval != -2) {
    				    int tmask = j | (1 << tval);    				
    					ans[k][tmask] += ans[i][j];
    					if (ans[k][tmask] >= mdl) {
    						ans[k][tmask] -= mdl;
    					} 
    				}
    			}	
    		}	
    	}
    }

    int rans = 0;
    for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= size; j++) {
//			cerr << i << ' ' << j << ' ' << ans[i][(1 << j) - 1] << endl;
			rans += ans[i][(1 << j) - 1];
			if (rans >= mdl)
				rans -= mdl;			
		}    
    }

    cout << rans << endl;

    return 0;
}