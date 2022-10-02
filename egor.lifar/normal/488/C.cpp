#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <cmath>
#include <set>
#include <map>


using namespace std;


int hpy, atky, defy, hpm, atkm, defm; 
int h, a, d;


int main() {
    cin >> hpy >> atky >> defy >> hpm >> atkm >> defm;
    cin >> h >> a >> d;
    int ans = 1000000000;
    for (int i = 0; i <= 1000; i++) {
    	for (int j = 0; j <= 200; j++) {
    		for (int k = 0; k <= 200; k++) {
    			hpy += i;
    			atky += j;
    			defy += k;
    			int hpy1 = hpy;
    			int hpm1 = hpm;
    			while (hpy1 > 0 && hpm1 > 0) {
    				hpy1 -= max(0, atkm - defy);
    				hpm1 -= max(0, atky - defm);
    				if (max(0, atky - defm) == 0) {
    					break;
    				}
    			} 
    			if (hpy1 > 0 && hpm1 <= 0) {
    				ans = min(ans, h * i + a * j + d * k);
    			}
    			hpy -= i;
    			atky -= j;
    			defy -= k;
    		}
    	}
    }
    cout << ans << endl;
    return 0;
}