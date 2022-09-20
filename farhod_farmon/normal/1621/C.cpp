#include "bits/stdc++.h"

#define fi first
#define se second

const int N = 100100;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n, -1);
        function<int(int)> get = [&](int x) -> int
        {
            cout << "? " << x << endl;
            cin >> x;
            return x;
        };
        for(int i = 0; i < n; i++){
            if(a[i] != -1){
                continue;
            }
            int x = get(i + 1);
            vector<int> v = {x};
            while(true){
                x = get(i + 1);
                v.push_back(x);

                if(x == v[0]){
                    break;
                }
            }
            for(int j = 1; j < v.size(); j++){
                a[v[j - 1] - 1] = v[j];
            }
        }
        cout << "! ";
        for(int x : a){
            cout << x << " ";
        }
        cout << endl;
    }
}