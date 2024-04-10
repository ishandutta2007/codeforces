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

void finish_stannis() {
    cout << "Stannis" << endl;

    exit(0);
}

void finish_deyneris() {
   	cout << "Daenerys" << endl;
   	
   	exit(0);
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n, k, z, sum = 0;
    int odd = 0, even = 0;

    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) {
    	scanf("%d", &z);
    	z %= 2;
    	sum = (sum + z) % 2;

    	if (z)
    		odd++;
    	else
    		even++;
    }

    n -= k;

    if (n == 0) {
    	if (sum % 2 == 0)
    		finish_deyneris();
    	else
    		finish_stannis();
    }
    
    if (even >= n && odd >= n) {
    	if (n % 2 == 1)
    		finish_stannis();
    	else
    		finish_deyneris();
    }

  	even = min(even, n);
   	odd = min(odd, n);
    
    if (n % 2 == 0) {
    	if (even > n / 2 && odd > n / 2)
    		finish_deyneris();
    	else {
    		if (odd <= n / 2) {
    			sum = (sum + odd) % 2;
    			n -= odd;
    			if (sum % 2 == 0)
    				finish_deyneris();
    			else
    				finish_stannis();
    		} else {
    			n -= even;
    			if ((sum + n) % 2 == 0)
    				finish_deyneris();
    			else
    				finish_stannis();	
    		} 
      	}
    } else {
    	if (even > n / 2 && odd > n / 2)
    		finish_stannis();
    	else {
    		if (odd <= n / 2) {
    			sum = (sum + odd) % 2;
    			n -= odd;
    			if (sum % 2 == 0)
    				finish_deyneris();
    			else
    				finish_stannis();
    		} else {
    			n -= even;
    			if ((sum + n) % 2 == 0)
    				finish_deyneris();
    			else
    				finish_stannis();	
    		} 
      	}
    }
    
    return 0;
}