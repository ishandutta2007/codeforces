#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<int> v;
int cnt[200010];
int ans[200010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    for(int i=0; i<n; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }

    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++) {
        int x = v[i];

        for(int j=0; x; j++, x >>= 1) {
            if(cnt[x] < k) {
                cnt[x]++;
                ans[x] += j;
            }
        }
    }

    int A = 100000000;
    for(int i=0; i<=200000; i++) {
        if(cnt[i] == k) {
            A = min(A, ans[i]);
        }
    }

    cout << A;
}