#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int mod = 1e9 + 7;

using namespace std;

int n;
int res[N];
int A[N];
int B[N];
int L[N];
int inv[N];
pair < int, int > t[N][20];
vector < pair < int, int > > v[N];

pair < int, int > get(int l, int r)
{
        int g = L[r - l + 1];
        return min(t[l][g], t[r - (1 << g) + 1][g]);
}

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        for(int i = 1; i <= n; i++){
                int l, r;
                cin >> l >> r;
                v[l].push_back({r, i});

                A[i] = l;
                B[i] = r;
        }
        set < pair < int, int > > s;
        for(int i = 1; i <= n; i++){
                for(auto p: v[i]){
                        s.insert(p);
                }
                auto shit = *s.begin();
                s.erase(s.begin());
                res[shit.se] = i;
                inv[i] = shit.se;
        }

        for(int i = 1; i <= n; i++){
                int j = inv[i];
                t[i][0] = {A[j], j};
        }
        for(int i = 2; i < N; i++){
                L[i] = L[i / 2] + 1;
        }
        for(int i = 1; i < 20; i++){
                for(int j = 1; j <= n; j++) if(j + (1 << i) - 1 <= n){
                        t[j][i] = min(t[j][i - 1], t[j + (1 << i - 1)][i - 1]);
                }
        }
        pair < int, int > sw = {-1, -1};
        for(int i = 1; i <= n; i++){
                int j = inv[i];
                if(B[j] == i){
                        continue;
                }
                auto p = get(i + 1, B[j]);
                if(p.fi <= i){
                        sw = {p.se, j};
                        break;
                }
        }
        if(sw.fi == -1){
                cout << "YES" << "\n";
        } else{
                cout << "NO" << "\n";
        }
        for(int i = 1; i <= n; i++){
                cout << res[i] << " \n"[i == n];
        }
        if(sw.fi != -1){
                swap(res[sw.fi], res[sw.se]);
                for(int i = 1; i <= n; i++){
                        cout << res[i] << " \n"[i == n];
                }
        }
}