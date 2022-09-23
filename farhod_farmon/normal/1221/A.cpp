#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;

using namespace std;

int get(int x)
{
        int res = 0;
        while((1 << res) < x){
                res += 1;
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int q;
        cin >> q;
        while(q--){
                int n;
                cin >> n;
                vector < int > v(60, 0);
                for(int i = 1; i <= n; i++){
                        int x;
                        cin >> x;
                        v[get(x)] += 1;
                }
                int need = get(2048);
                for(int i = 0; i < need; i++){
                        v[i + 1] += v[i] / 2;
                }
                if(v[need]){
                        cout << "Yes" << "\n";
                } else{
                        cout << "No" << "\n";
                }
        }
}