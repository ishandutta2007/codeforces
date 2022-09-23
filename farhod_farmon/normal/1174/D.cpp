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

        int n, x;
        cin >> n >> x;
        vector < int > res(1, 0);
        vector < bool > used(1 << n, 0);
        if(x < (1 << n)){
                used[x] = true;
        }
        for(int i = 1; i < (1 << n); i++){
                if(used[i]){
                        continue;
                }
                res.push_back(i);
                if((i ^ x) < (1 << n)){
                        used[i ^ x] = true;
                }
        }
        cout << res.size() - 1 << "\n";
        for(int i = 1; i < res.size(); i++){
                cout << (res[i - 1] ^ res[i]) << " ";
        }
}