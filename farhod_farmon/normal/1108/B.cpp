#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 130;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("tracking2.in", "r", stdin);
        //freopen("tracking2.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int it = 0; it < 2; it++){
                int x = 0;
                for(int i = 1; i <= n; i++){
                        x = max(x, a[i]);
                }
                cout << x << " ";
                set < int > s;
                for(int i = 1; i <= n; i++){
                        if(a[i] == -1 || s.find(a[i]) != s.end()){
                                continue;
                        }
                        if(x % a[i] == 0){
                                s.insert(a[i]);
                                a[i] = -1;
                        }
                }
        }
}