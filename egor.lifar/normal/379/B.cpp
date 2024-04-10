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


int n, a[3000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool b = false;
    int s = 0;
    while (!b) {
        s++;
        b = true;
        for (int i = 0; i < n; i++) {
            if (a[i] > 0)
            {
                b = false;
            }
        }
        if (s % 2 == 1){
            cout << 'R';
            for (int i = 1; i < n; i++){
                if(i != 1) {
                    cout << 'R';
                }
                if(a[i] > 0) {
                    cout << 'P';
                    a[i]--;
                }
                if(i == n - 1){
                    cout << 'L';
                }
            }
        } else {
             for (int i = n - 2; i >= 0; i--){
                if(i != n - 2) {
                    cout << 'L';
                }
                if(a[i] > 0) {
                    cout << 'P';
                    a[i]--;
                }
            }
        }
    }
    cout << endl;
    return 0;
}