#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int n, x, y;
                cin >> n >> x >> y;
                vector < int > a(n + 1), b(n + 1);
                vector < vector < int > > c(n + 2);
                for(int i = 1; i <= n; i++){
                        cin >> a[i];
                        c[a[i]].push_back(i);
                }
                int none = 1;
                while(c[none].empty() == false) none += 1;

                for(int i = 1; i <= n; i++){
                        b[i] = none;
                }
                set < pair < int, int > > s;
                for(int i = 1; i <= n + 1; i++){
                        if(c[i].size() > 0){
                                s.insert({c[i].size(), i});
                        }
                }
                y -= x;
                int rem = n - x;
                while(x > 0){
                        int i = (--s.end())->se;
                        s.erase(--s.end());
                        b[c[i].back()] = i;
                        c[i].pop_back();
                        s.insert({c[i].size(), i});
                        x -= 1;
                }

                vector < pair < int, int > > A;
                while(s.size() > 0){
                        A.push_back(*s.begin());
                        s.erase(s.begin());
                }
                int sum = 0;
                for(int i = 0; i < (int)A.size() - 1; i++){
                        sum += A[i].fi;
                }
                while(A.back().fi > sum){
                        A.back().fi -= 1;
                        c[A.back().se].pop_back();
                }
                sum += A.back().fi;
                if(sum < y){
                        cout << "NO" << "\n";
                        continue;
                }
                cout << "YES" << "\n";
                if(y > 0){
                        vector < pair < int, int > > pos;
                        for(auto p: A){
                                for(auto i: c[p.se]){
                                        pos.push_back({i, p.se});
                                }
                        }
                        int shift = A.back().fi;
                        int L = pos.size();
                        for(int i = 0; i < y; i++){
                                b[pos[i].fi] = pos[(i + shift) % L].se;
                        }
                }
                for(int i = 1; i <= n; i++){
                        cout << b[i] << " ";
                }
                cout << "\n";
        }
}