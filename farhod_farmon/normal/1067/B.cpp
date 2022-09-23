#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int mod = 998244353;

using namespace std;

int n;
int k;
int c[N];
bool used[N];
set < int > s[N];

void ans(bool correct)
{
        if(correct){
                cout << "Yes" << "\n";
        }
        else{
                cout << "No" << "\n";
        }
        exit(0);
}

int main()
{
        ios_base::sync_with_stdio(0);

        cin >> n >> k;
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                s[x].insert(y);
                s[y].insert(x);
        }
        vector < int > v;
        for(int i = 1; i <= n; i++){
                if(s[i].size() == 1){
                        v.push_back(i);
                        used[i] = true;
                }
        }
        while(k >= 1){
                if(v.empty()){
                        ans(false);
                }
                vector < int > nv;
                for(int x: v){
                        int y = *s[x].begin();
                        c[y]++;
                        s[x].erase(y);
                        s[y].erase(x);
                        if(used[y] == false){
                                used[y] = true;
                                nv.push_back(y);
                        }
                }
                for(int x: nv){
                        if(c[x] < 3 || s[x].size() != min(1, k - 1)){
                                ans(false);
                        }
                }
                v = nv;
                k--;
        }
        ans(true);
}