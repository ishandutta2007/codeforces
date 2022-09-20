#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 400200;

using namespace std;

int t[N];

void upd(int x, int y)
{
        while(x < N){
                t[x] = max(t[x], y);
                x += x & -x;
        }
}

int get(int x)
{
        int res = 0;
        while(x > 0){
                res = max(res, t[x]);
                x -= x & -x;
        }
        return res;
}

int n;
int a[N];

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n;
        vector<int> ord;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                ord.push_back(i);
        }
        sort(ord.begin(), ord.end(), [&](int i, int j){return make_pair(a[i], -i) < make_pair(a[j], -j);});

        for(int i: ord){
                int cur = get(i - a[i] + N / 2) + 1;

                if(cur == 1 && a[i] > i){
                        cur = 0;
                }

                upd(i - a[i] + N / 2, cur);
        }

        cout << get(N - 1) << "\n";
}