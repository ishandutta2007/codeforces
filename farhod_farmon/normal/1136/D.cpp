#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const long long mod = 1000000007;
const int MAGIC = 2000;

using namespace std;

int n;
int m;
int a[N];
bool good[N];
set < pair < int, int > > s;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                if(y == a[n]){
                        good[x] = 1;
                }
                else{
                        s.insert({x, y});
                }
        }
        for(int i = n - 1; i >= 1; i--){
                if(!good[a[i]]){
                        continue;
                }
                for(int j = i; j + 1 < n; j++){
                        if(s.find({a[j], a[j + 1]}) != s.end()){
                                swap(a[j], a[j + 1]);
                        }
                        else{
                                break;
                        }
                }
        }
        int res = 0;
        while(n - res - 1 >= 1 && good[a[n - res - 1]]){
                res++;
        }
        cout << res << "\n";
}