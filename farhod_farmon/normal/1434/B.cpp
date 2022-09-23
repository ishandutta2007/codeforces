#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 600100;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int n;
        cin >> n;
        vector < int > res(n);
        set < int > s;
        vector < pair < char, int > > v(2 * n);
        for(int i = 0; i < 2 * n; i++){
                cin >> v[i].fi;
                if(v[i].fi == '-'){
                        cin >> v[i].se;
                }
        }
        int j = n - 1;
        for(int i = 2 * n - 1; i >= 0; i--){
                if(v[i].fi == '-'){
                        if(!s.empty() && *s.begin() < v[i].se){
                                cout << "NO" << "\n";
                                return 0;
                        }
                        s.insert(v[i].se);
                } else{
                        if(s.empty()){
                                cout << "NO" << "\n";
                                return 0;
                        }
                        res[j] = *s.begin();
                        s.erase(s.begin());
                        j -= 1;
                }
        }
        cout << "YES" << "\n";
        for(int x: res){
                cout << x << " ";
        }
}