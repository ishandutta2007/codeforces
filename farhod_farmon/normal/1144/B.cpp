#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n;
        cin >> n;
        vector < int > v0, v1;
        for(int i = 1; i <= n; i++)
        {
                int x;
                cin >> x;
                if(x % 2){
                        v1.push_back(x);
                } else{
                        v0.push_back(x);
                }
        }

        sort(v0.begin(), v0.end());
        sort(v1.begin(), v1.end());

        while(!v0.empty() && !v1.empty()){
                v0.pop_back();
                v1.pop_back();
        }

        if(!v0.empty()){
                v0.pop_back();
        } else if(!v1.empty()){
                v1.pop_back();
        }

        int res = 0;
        for(int x: v0){
                res += x;
        }
        for(int x: v1){
                res += x;
        }
        cout << res << "\n";
}