#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 333;

using namespace std;

int l[N], r[N];
vector < vector < int > > e;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);
        int L, R;
        cin >> L >> R;

        for(int i = 2; i < 23; i++){
                l[i] = r[i] = 1;
                e.push_back({1, i, 1});
                for(int j = 2; j < i; j++){
                        e.push_back({j, i, r[i]});
                        r[i] += r[j] - l[j] + 1;
                }
        }

        int g = R - L;
        int sum = 1;
        e.push_back({1, 23, 1});
        for(int i = 0; i < 23; i++){
                if(g & (1 << i)){
                        e.push_back({i + 2, 23, sum});
                        sum += (1 << i);
                }
        }

        int n = 23;
        if(L > 1){
                n = 24;
                e.push_back({23, 24, L - 1});
        }
        cout << "YES\n";
        cout << n << " " << e.size() << "\n";
        for(auto p: e){
                cout << p[0] << " " << p[1] << " " << p[2] << "\n";
        }
}