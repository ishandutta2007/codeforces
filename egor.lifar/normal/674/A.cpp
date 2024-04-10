#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <map>


using namespace std;


int n;
int t[5001];
int cnt[5001];
int ans[5001];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        t[i]--;
    }
    for (int i = 0; i < n; i++) {
        int color = -1;
        for (int j = 0; j < n; j++) {
            cnt[j] = 0;
        }
        for (int j = i; j < n; j++) {
            cnt[t[j]]++;
            if (color == -1) {
                color = t[j];
            } else {
                if (cnt[color] < cnt[t[j]]) {
                    color = t[j];
                } else {
                    if (cnt[color] == cnt[t[j]] && color > t[j]) {
                        color = t[j];
                    }
                }
            }
            ans[color]++;
        }
    } 
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}