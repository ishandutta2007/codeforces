#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <assert.h>


using namespace std;


int a[100];


int main(){
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ans = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int ans1 = 0;
            for (int k = i; k <= j; k++) {
                if (a[k] == 0) {
                    ans1++;
                } 
            }
            for (int k = 0; k < i; k++) {
                if (a[k] == 1) {
                    ans1++;
                }
            }
            for (int k = j + 1; k < n; k++) {
                if (a[k] == 1) {
                    ans1++;
                }
            }
            ans = max(ans, ans1);
        }
    }
    cout << ans << endl;
    return 0;
}