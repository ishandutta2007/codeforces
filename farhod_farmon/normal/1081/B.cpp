#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 200200;
const ll mod = 998244353;

using namespace std;

int n;
int a[N];
vector < int > v[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                x = n - x;
                v[x].push_back(i);
        }
        int C = 0;
        for(int i = 1; i <= n; i++){
                int g = v[i].size();
                if(g % i){
                        cout << "Impossible" << "\n";
                        return 0;
                }
                for(int j = 0; j < g; j += i){
                        C++;
                        for(int h = 0; h < i; h++){
                                a[v[i][j + h]] = C;
                        }
                }
        }
        cout << "Possible" << "\n";
        for(int i = 1; i <= n; i++){
                cout << a[i] << " ";
        }
}