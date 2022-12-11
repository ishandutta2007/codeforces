#include <bits/stdc++.h>
//#pragma comment(linker, /STACK:36777216)
           
using namespace std;
           
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n;
int a[1111], b[1111];
int ans[1111];

int main(){
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    vector<pair<int, int> > t;
    for (int i = 0; i < n; i++) t.pb(mp(a[i] + b[i], i));
    sort(all(t));

    for (int i = 0; i < n; i++) ans[i] = -1;

    int now = n;
    int cnt = 0;

    int i = 0;
    while(1){
        if (i >= t.size()) break;
        int j = i;
        while(j + 1 < t.size() && t[j + 1].x == t[i].x) j++;

        if (t[i].x != cnt) cout << "NO", exit(0);

        for (int s = i; s <= j; s++){
            int pos = t[s].y;
            int w1 = 0, w2 = 0;
            for (int d = 0; d < n; d++) if (ans[d] != -1){
                if (d < pos) w1++; else w2++;
            }
            if (mp(w1, w2) != mp(a[pos], b[pos])) cout << "NO", exit(0);
        }
        for (int s = i; s <= j; s++){
            int pos = t[s].y;
            ans[pos] = now;
        }

        cnt += j - i + 1;
        i = j + 1;
        now--;
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}