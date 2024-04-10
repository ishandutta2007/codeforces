#include <bits/stdc++.h>
                  
using namespace std;
          
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n;
ll a[100007];
ll b[100007];
vector<pair<int, int> > t[200007];

int main(){
   // freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n / 2; i++) cin >> a[i];

    for (int i = 1; i < 200007; i += 2){
        int sum = 0;
        for (int j = i; ; j += 2){
            sum += j;
            if (sum >= 200007) break;
            t[sum].pb(mp(i, j));
        }
    }

    int last = 1;
    for (int i = 0, j = 0; i < n; i += 2, j++){
        int x = a[j];
        auto now = mp(-1, -1);
        for (auto c : t[x]) if (c.x > last){
            now = c;
            break;
        }
        if (now.x == -1){
            cout << "No";
            exit(0);
        }
        ll kek = 0;
        for (int d = last; d < now.x; d += 2) kek += d;
        last = now.y + 2;
        b[i + 1] = a[j];
        b[i] = kek;
    }
    cout << "Yes\n";
    for (int i = 0; i < n; i++) cout << b[i] << ' ';
}