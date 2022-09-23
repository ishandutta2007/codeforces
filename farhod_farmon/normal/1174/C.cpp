#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 303;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n;
        cin >> n;
        vector < pair < int, int > > v;
        for(int i = 2; i <= n; i++){
                int res = i;
                for(int j = 2; j * j <= i; j++){
                        if(i % j == 0){
                                res = j;
                                break;
                        }
                }
                v.push_back({res, i - 2});
        }
        sort(v.begin(), v.end());
        vector < int > res(n - 1);
        for(int i = 0, j = 1; i < v.size(); i++){
                if(i > 0 && v[i].fi != v[i - 1].fi){
                        j += 1;
                }
                res[v[i].se] = j;
        }
        for(int x: res){
                cout << x << " ";
        }
}