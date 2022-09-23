#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 202 * 202;

using namespace std;

int A;
int a, b;
int d[N];

long long get(long long L)
{
        return (L / A) * d[A - 1] + d[L % A];
}

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int q;
                cin >> a >> b >> q;
                for(int i = 0; i < N; i++){
                        d[i] = 0;
                        if((i % a) % b != (i % b) % a){
                                d[i] = 1;
                        }
                        if(i > 0){
                                d[i] += d[i - 1];
                        }
                }
                A = a * b;
                while(q--){
                        long long l, r;
                        cin >> l >> r;
                        cout << get(r) - get(l - 1) << " ";
                }
                cout << "\n";
        }
}