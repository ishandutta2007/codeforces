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
int a[100007];
vector<int> t[100007];
int ans[100007];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        a[i] = n - a[i];
        t[a[i]].pb(i);
    }
    int dd = 1;
    for (int i = 1; i <= n; i++) if (t[i].size()){
        if (t[i].size() % i != 0){
            cout << "Impossible";
            exit(0);
        }
        int cnt = i;
        for (int j = 0; j < t[i].size(); j++){
            ans[t[i][j]] = dd;
            cnt--;
            if (cnt == 0){
                cnt = i;
                dd++;
            }
        }
    }
    cout << "Possible\n";
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}