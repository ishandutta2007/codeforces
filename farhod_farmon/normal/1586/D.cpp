#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 10011;

using namespace std;

int ask(vector<int> v)
{
        cout << "?";
        for(int x : v){
                cout << " " << x;
        }
        cout << endl;
        int k;
        cin >> k;
        return k;
}

int res[N];

int main()
{
        #ifdef zxc
                //freopen("input.txt", "r", stdin);
                //freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int n;
        cin >> n;
        int P = n;
        for(int i = 1; i < n; i++){
                vector<int> v(n, i);
                v[n - 1] = n;
                if(ask(v)){
                        P = i;
                        break;
                }
        }
        res[n] = P;
        for(int i = 1; i < P; i++){
                vector<int> v(n, P - i + 1);
                v[n - 1] = 1;
                res[ask(v)] = i;
        }
        for(int i = P + 1; i <= n; i++){
                vector<int> v(n, 1);
                v[n - 1] = i - P + 1;
                res[ask(v)] = i;
        }

        cout << "!";
        for(int i = 1; i <= n; i++){
                cout << ' ' << res[i];
        }
        cout << endl;
}