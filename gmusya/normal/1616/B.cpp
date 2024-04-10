#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

mt19937_64 rnd(time(nullptr));

string true_ans(string str) {
    string ans;
    ans += str[0];
    ans += str[0];
    for (int i = 0; i < str.size(); ++i) {
        string res;
        for (int j = 0; j <= i; ++j) {
            res += str[j];
        }
        for (int j = i; j >= 0; --j) {
            res += str[j];
        }
        ans = min(ans, res);
    }
    return ans;
}

string my_solve(string str) {
    int n = str.size();
    int l = 0;
    while (l + 1 < n && str[l] > str[l + 1]) {
        ++l;
    }
    int r = l;
    while (r < n && str[l] == str[r]) {
        ++r;
    }
    string res;
    if (l == 0) {
        res += str[0];
        res += str[0];
    } else {
        for (int x = 0; x < r; ++x) {
            res += str[x];
        }
        for (int x = r - 1; x >= 0; --x) {
            res += str[x];
        }
    }
    return res;
}

string my_solve2(string str) {
    int n = str.size();
    string kek;
    if (n >= 2 && str[0] == str[1]) {
        kek += str[0];
        kek += str[0];
        return kek;
    }
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = str[i] - 'a';
    }
    vector<int> mi(n), ma(n);
    mi[n - 1] = ma[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        mi[i] = min(mi[i + 1], arr[i]);
        ma[i] = max(ma[i + 1], arr[i]);
    }
    int ind = 0;
    while (ind + 1 < n && str[ind] >= str[ind + 1]) {
        ++ind;
    }
    string res;
    if (str[0] == str[ind]) {
        res += str[0];
        res += str[0];
    } else {
        for (int i = 0; i <= ind; ++i) {
            res += str[i];
        }
        for (int i = ind; i >= 0; --i) {
            res += str[i];
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        cout << my_solve2(str);
        cout << '\n';
    }
    return 0;
}

/*
1
3
zaab
 */