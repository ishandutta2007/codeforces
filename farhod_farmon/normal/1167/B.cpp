#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int Q = 1 << 21;
const long long mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("sum.in", "r", stdin);
        //freopen("sum.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        vector < int > v = {4, 8, 15, 16, 23, 42};
        vector < int > p;
        for(int i = 0; i < 4; i++){
                cout << "? " << i + 1 << " " << i + 2 << endl;
                int x;
                cin >> x;
                p.push_back(x);
        }
        do{
                bool good = true;
                for(int i = 0; i < 4; i++){
                        if(v[i] * v[i + 1] != p[i]){
                                good = false;
                        }
                }
                if(good){
                        cout << "!";
                        for(int x: v){
                                cout << " " << x;
                        }
                        cout << endl;
                        return 0;
                }
        }while(next_permutation(v.begin(), v.end()));
}