#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 100100;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int k;
int a[N];
vector < int > v[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                v[x].push_back(i);
        }
        int j = 0;
        for(int i = 1; i < N; i++){
                if(v[i].size() > k){
                        cout << "NO" << "\n";
                        return 0;
                }
                for(int x: v[i]){
                        a[x] = j;
                        j = (j + 1) % k;
                }
        }
        cout << "YES" << "\n";
        for(int i = 1; i <= n; i++){
                cout << a[i] + 1 << " ";
        }
}