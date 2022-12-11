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
int a[100007];

int ans[100007];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<pair<int, int> > t;
    for (int i = 0; i < n; i++) cin >> a[i], t.pb(mp(a[i], i));
    sort(all(t));
    reverse(all(t));

    for (int i = 0; i < t.size(); i++){
        int v = t[i].y;
        int val = t[i].x;
        int f = 0;
        for (int j = 1; ; j++) if (j * val + v < n){
            int pos = v + j * val;
            if (a[pos] > a[v] && ans[pos] == 0) f = 1;
        } else break;
        for (int j = 1; ; j++) if (-j * val + v >= 0){
            int pos = v - j * val;
            if (a[pos] > a[v] && ans[pos] == 0) f = 1;
        } else break;
        ans[t[i].y] = f;
    }

    for (int i = 0; i < n; i++){
        if (ans[i]) cout << 'A'; else cout << 'B';
    }
}