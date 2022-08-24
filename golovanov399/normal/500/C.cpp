#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;
    vector<int> w(n);
    for (int i = 0; i < n; i++)
        cin >> w[i];
    vector<int> b(m);
    for (int i = 0; i < m; i++){
        cin >> b[i];
        b[i]--;
    }
    long long ans = 0;
    int cur = 0;
    vector<int> last(n, -1);
    for (int i = 0; i < m; i++){
        if (last[b[i]] == -1){
            ans += cur;
            cur += w[b[i]];
        } else {
            for (int j = last[b[i]] + 1; j < i; j++){
                if (j == last[b[j]])
                    ans += w[b[j]];
            }
        }
        last[b[i]] = i;
    }
    cout << ans << "\n";

    return 0;
}