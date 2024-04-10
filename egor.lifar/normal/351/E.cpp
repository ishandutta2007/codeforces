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
 

using namespace std;


int n;
int a[3000];
int inversions[3000];


int main(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; 
        a[i] = abs(a[i]); 
        inversions[i] = 0;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            if (a[j] < a[i]) {
                inversions[i]++;
            }
        }
        for (int j= i + 1; j< n; j++){
            if (a[j] < a[i]) {
                inversions[i]--;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (inversions[i] < 0) {
            a[i] *= -1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j= i + 1; j < n;j++){
            if (a[i] > a[j]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}