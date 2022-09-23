#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
int a[N];
int c[N];
vector < int > v[11];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                cin >> n;
                for(int i = 0; i < 10; i++){
                        v[i].clear();
                }
                char h;
                for(int i = 1; i <= n; i++){
                        cin >> h;
                        v[h - '0'].push_back(i);
                }
                int cur = 1, last = 0;
                for(int i = 0; i < 10; i++){
                        if(v[i].empty()){
                                continue;
                        }
                        if(v[i][0] < last){
                                cur += 1;
                                int st = n + 1;
                                for(int x: v[i]){
                                        if(x <= last){
                                                st = x;
                                        }
                                }
                                for(int x: v[i]){
                                        if(x <= st){
                                                c[x] = cur;
                                        } else{
                                                c[x] = cur - 1;
                                        }
                                }
                                last = st;
                        } else{
                                for(int x: v[i]){
                                        c[x] = cur;
                                }
                                last = v[i].back();
                        }
                }
                if(cur > 2){
                        cout << "-";
                } else{
                        for(int i = 1; i <= n; i++){
                                cout << c[i];
                        }
                }
                cout << "\n";
        }
}