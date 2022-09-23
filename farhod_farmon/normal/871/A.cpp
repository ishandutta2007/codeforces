#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 8000;

using namespace std;

int d[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        vector < int > v;
        for(int i = 1; i < N; i++){
                bool good = false;
                for(int j = 2; j < i; j++){
                        if(i % j == 0) good = true;
                }
                if(good) v.push_back(i);
        }
        for(int i = 1; i < N; i++){
                d[i] = -1;
                for(int j: v){
                        if(i >= j && d[i - j] != -1) d[i] = max(d[i], d[i - j] + 1);
                }
        }
        int q;
        cin >> q;
        while(q--){
                int x;
                cin >> x;
                if(x < N){
                        cout << d[x] << "\n";
                } else{
                        int nx = x % (N / 2);
                        nx += N / 2;
                        assert(d[nx] != -1);
                        cout << d[nx] + (x - nx) / 4 << "\n";
                }
        }
}