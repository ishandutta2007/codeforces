#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n;
        cin >> n;
        vector < int > v;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                x %= 2;
                if(v.empty() || v.back() != x){
                        v.push_back(x);
                }
                else{
                        v.pop_back();
                }
        }
        if(v.size() > 1){
                cout << "NO" << "\n";
        }
        else{
                cout << "YES" << "\n";
        }
}