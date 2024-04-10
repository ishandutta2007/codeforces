#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <map>

using namespace std;

int check(vector <int> x) {
    int f = min(x[0], x[1]);
    int s = max(x[0], x[1]);
    if (f == 0 && s == 2) return 1;
    if (f == 1 && s == 5) return 2;
    if (f == 3 && s == 4) return 3;
    return -1;
}

bool go(vector <int> f, vector <int> s) {
    bool flag = true;
    if (f[0] != s[6]) flag = false;
    if (f[1] != s[7]) flag = false;
    for (int i = 2; i < 8; ++i)
        if (f[i] != s[i - 2]) flag = false;
    if (flag) return true;
    flag = true;
    if (s[0] != f[6]) flag = false;
    if (s[1] != f[7]) flag = false;
    for (int i = 0; i < 6; ++i)
        if (f[i] != s[i + 2]) flag = false;
    if (flag) return true;
    return false;
}
int main() {
    vector <vector <int>> v(6, vector <int>(4));
    vector <int> vc(25);
    int n = 1;
    for (int i = 0; i < 6; ++i){
        for (int j = 0; j < 4; ++j) {
            cin >> v[i][j];
            vc[n] = v[i][j];
            ++n;
        }
    }
    int full = 0;
    int diff = 0;
    vector <int> f;
    for (int i = 0; i < 6; ++i) {
        map <int, int> cnt;
        for (int j = 0; j < 4; ++j)
            ++cnt[v[i][j]];
        if (cnt.size() == 1) {
            ++full;
            f.push_back(i);
        }
        else if (cnt.size() == 2 && cnt.begin() -> second == 2) {
            ++diff;
        }
        else {
            cout << "No" << endl;
            return 0;
        }
    }
    if (full != 2 || diff != 4) {
        cout << "No" << endl;
        return 0;
    }
    int c = check(f);
    if (c == -1) {
        cout << "No" << endl;
        return 0;
    }
    vector <int> first;
    vector <int> second;
    if (c == 1) {
        first.push_back(vc[5]);
        first.push_back(vc[6]);
        first.push_back(vc[17]);
        first.push_back(vc[18]);
        first.push_back(vc[21]);
        first.push_back(vc[22]);
        first.push_back(vc[13]);
        first.push_back(vc[14]);
        second.push_back(vc[7]);
        second.push_back(vc[8]);
        second.push_back(vc[19]);
        second.push_back(vc[20]);
        second.push_back(vc[23]);
        second.push_back(vc[24]);
        second.push_back(vc[15]);
        second.push_back(vc[16]);
    }
    if (c == 2) {
        first.push_back(vc[16]);
        first.push_back(vc[14]);
        first.push_back(vc[3]);
        first.push_back(vc[4]);
        first.push_back(vc[17]);
        first.push_back(vc[19]);
        first.push_back(vc[10]);
        first.push_back(vc[9]);
        second.push_back(vc[15]);
        second.push_back(vc[13]);
        second.push_back(vc[1]);
        second.push_back(vc[2]);
        second.push_back(vc[18]);
        second.push_back(vc[20]);
        second.push_back(vc[12]);
        second.push_back(vc[11]);
    }
    else {
        first.push_back(vc[3]);
        first.push_back(vc[1]);
        first.push_back(vc[22]);
        first.push_back(vc[24]);
        first.push_back(vc[11]);
        first.push_back(vc[9]);
        first.push_back(vc[7]);
        first.push_back(vc[5]);
        second.push_back(vc[4]);
        second.push_back(vc[2]);
        second.push_back(vc[21]);
        second.push_back(vc[23]);
        second.push_back(vc[12]);
        second.push_back(vc[10]);
        second.push_back(vc[8]);
        second.push_back(vc[6]);
    }
    if (go(first, second)) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }
}