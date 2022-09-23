#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 1e9 + 7;

using namespace std;

int c[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                c[x]++;
        }

        vector < int > v0, v1;
        for(int i = 0; i < N; i++){
                if(c[i] >= 1){
                        v0.push_back(i);
                }
                if(c[i] == 2){
                        v1.push_back(i);
                }
                if(c[i] > 2){
                        cout << "NO" << "\n";
                        return 0;
                }
        }

        sort(v0.begin(), v0.end());
        sort(v1.begin(), v1.end());
        reverse(v1.begin(), v1.end());

        cout << "YES" << "\n";
        cout << v0.size() << "\n";
        for(int x: v0){
                cout << x << " ";
        }
        cout << "\n" << v1.size() << "\n";
        for(int x: v1){
                cout << x << " ";
        }
}