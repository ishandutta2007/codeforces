#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 7;

int a[MAXN];
bool good[MAXN];
int want[MAXN], pref[MAXN], next_[MAXN];

signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cout.precision(40);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }

    stack <int> st;
    for (int i = 0; i < n; ++i){
        while (st.size() && a[st.top()] < a[i]){
            next_[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(st.size()){
        next_[st.top()] = n;
        st.pop();
    }

    int mx1 = -MOD;
    int mx2 = -MOD;
    for (int i = 0; i < n; ++i){
        if (a[i] < mx1 && a[i] > mx2){
            want[i] = true;
        }

        if (a[i] > mx1){
            mx2 = mx1;
            mx1 = a[i];
        }
        else if (a[i] > mx2){
            mx2 = a[i];
        }
    }


    pref[0] = want[0];
    for (int i = 1; i < n; ++i){
        pref[i] = pref[i - 1] + want[i];
    }

    int mx = -MOD;
    int ans = -MOD;
    int best = -1;
    for (int i = 0; i < n; ++i){
        mx = max(mx, a[i]);
        if (a[i] != mx) continue;

        int j = next_[i];
        int new_ans = pref[j - 1] - pref[i] - 1;
        if (new_ans > ans || (new_ans == ans && a[i] < a[best])){
            ans = new_ans;
            best = i;
        }
    }

    mx = -MOD;
    for (int i = 0; i < n; ++i){
        mx = max(mx, a[i]);
        if (a[i] == mx) continue;
        int new_ans = 0;
        if (new_ans > ans || (new_ans == ans && a[i] < a[best])){
            ans = new_ans;
            best = i;
        }
    }

    cout << a[best] << '\n';
    return 0;
}