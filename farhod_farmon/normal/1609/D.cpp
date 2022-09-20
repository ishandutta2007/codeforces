#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;

using namespace std;

int n;
int p[N];
int s[N];

int get(int x)
{
        return p[x] == x ? x : p[x] = get(p[x]);
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int q;
        cin >> n >> q;
        vector<int> a(q);
        vector<int> b(q);
        for(int i = 0; i < q; i++){
                cin >> a[i] >> b[i];

                for(int j = 1; j <= n; j++){
                        p[j] = j;
                        s[j] = 1;
                }
                int rem = 0;
                for(int j = 0; j <= i; j++){
                        int x = get(a[j]), y = get(b[j]);
                        if(x != y){
                                p[x] = y;
                                s[y] += s[x];
                        } else{
                                rem += 1;
                        }
                }
                vector<int> v;
                for(int j = 1; j <= n; j++){
                        if(get(j) == j){
                                v.push_back(s[j]);
                        }
                }
                sort(v.rbegin(), v.rend());
                int res = 0;
                for(int i = 0; i < rem + 1; i++){
                        res += v[i];
                }
                cout << res - 1 << "\n";
        }
}