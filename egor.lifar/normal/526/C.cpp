#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <map>
#include <set>
#include <unordered_set>


using namespace std;


long long c, hr, hb, wr, wb;


int main() {
    cin >> c >> hr >> hb >> wr >> wb;
    long long ans = 0;
    for (long long i = 0; i <= 1000000; i++) {
        if (i * wr <= c) {
            ans = max(ans, i * hr + ((c - i * wr) / wb) * hb);
        }
    }
    for (long long i = 0; i <= 1000000; i++) {
        if (i * wb <= c) {
            ans = max(ans, i * hb + ((c - i * wb) / wr) * hr);
        }
    }
    cout << ans << endl;
    return 0;
}