// January 4, 2019
// https://codeforces.com/contest/1097/problem/C

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug_output.txt", "w", stderr);
#endif


    int N;
    cin >> N;
    vector<string> seqs(N);
    vector<int> left(N), right(N);
    vector<bool> first(N, false), second(N, false);
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        seqs[i] = s;
        int cnt = 0;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == '(') {
                cnt++;
                left[i]++;
            }
            else {
                cnt--;
                right[i]++;
            }
            if (cnt < 0) second[i] = true;
        }
        cnt = 0;
        for (int j = s.length() - 1; j >= 0; j--) {
            if (s[j] == '(') cnt++;
            else cnt--;
            if (cnt > 0) first[i] = true;
        }
    }
    // if first[i] == false and second[i] == false, then must have cnt of 0
    vector<int> a, b;
    int zero = 0;
    for (int i = 0; i < N; i++) {
        if (first[i] && second[i]) continue;
        else if (first[i]) {
            a.push_back(left[i] - right[i]);
        }
        else if (second[i]) {
            b.push_back(right[i] - left[i]);
        }
        else {
            zero++;
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = zero / 2;
    int cura = 0, curb = 0;
    while (cura < a.size() && curb < b.size()) {
        if (a[cura] == b[curb]) {
            ans++;
            cura++;
            curb++;
        }
        else if (a[cura] < b[curb]) {
            cura++;
        }
        else {
            curb++;
        }
    }
    cout << ans << '\n';


    return 0;
}