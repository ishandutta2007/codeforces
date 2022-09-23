#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;
const long long mod = 998244353;

using namespace std;

int n;
int a[N];
int x[N];

bool can(int k)
{
        for(int i = 0; i < k; i++){
                x[i] = 1e9;
        }
        for(int i = 1; i <= n; i++){
                int id = (i - 1) % k;
                if(x[id] != 1e9 && x[id] != a[i] - a[i - 1]){
                        return false;
                }
                x[id] = a[i] - a[i - 1];
        }
        return true;
}

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        vector < int > v;
        for(int i = 1; i <= n; i++){
                if(can(i)){
                        v.push_back(i);
                }
        }
        cout << v.size() << "\n";
        for(int x: v){
                cout << x << " ";
        }
}