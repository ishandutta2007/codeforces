#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 1e5 + 13;


int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<vector<int>> ans;

    for(int i = 0; i < n - 1; i++) {
        vector<int> res;

        int ind = 0;
        for(; ind < n; ind++)
            if(a[ind] == i)
                break;

        if(i % 2 == 0) {
            if(ind > 0)
                res.push_back(ind);
            res.push_back(n - ind - i);
            for(int j = 0; j < i; j++)
                res.push_back(1);
        } else {
            for(int j = 0; j < i; j++)
                res.push_back(1);
            res.push_back(ind + 1 - i);
            if(ind < n - 1)
                res.push_back(n - ind - 1);
        }

        if(res.size() > 1)
            ans.push_back(res);

        vector<vector<int>> b(res.size());
        int cur = 0;
        for(int j = 0; j < res.size(); j++) {
            for(int l = 0; l < res[j]; l++) {
                b[j].push_back(a[cur++]);
            }
        }

        a.erase(a.begin(), a.end());
        for(int j = res.size() - 1; j >= 0; j--) {
            for(int l = 0; l < b[j].size(); l++)
                a.push_back(b[j][l]);
        }
    }

    if(n % 2 == 1 && n > 1) {
        ans.push_back(vector<int>(0));
        for(int i = 0; i < n; i++)
            ans.back().push_back(1);
    }

    cout<< ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i].size() << ' ';
        for(int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
}