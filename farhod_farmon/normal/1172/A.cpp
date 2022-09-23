#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int Q = 10000011;
const int mod = 1e9 + 7;

using namespace std;

int n;
int a[N];
int b[N];
int c[N];
bool good[N];

bool can(int m)
{
        for(int i = 1; i <= n; i++){
                c[i] = 0;
        }
        for(int i = 1; i <= n; i++){
                if(a[i]){
                        c[a[i]] += 1;
                }
        }
        for(int i = 1; i <= m; i++){
                if(b[i]){
                        c[b[i]] += 1;
                }
        }
        int res = 1;
        for(int i = m + 1; i <= n; i++){
                if(c[i - m] == 0){
                        res = 0;
                        break;
                }
                c[b[i]] += 1;
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
                cin >> b[i];
        }
        int h = -1;
        for(int i = 1; i <= n; i++){
                if(b[i] == 1){
                        h = i;
                        for(int j = i; j <= n; j++){
                                if(b[j] != j - i + 1){
                                        h = -1;
                                }
                        }
                        break;
                }
        }
        if(h != -1){
                int res = 1;
                set < int > s;
                for(int i = 1; i <= n; i++){
                        if(a[i]){
                                s.insert(a[i]);
                        }
                }
                for(int i = 1; i < h; i++){
                        if(s.find(b[n] + i) == s.end()){
                                res = 0;
                                break;
                        }
                        s.insert(b[i]);
                }
                if(res){
                        cout << h - 1 << "\n";
                        return 0;
                }
        }

        int l = 0, r = n;
        while(l < r){
                int m = (l + r) / 2;
                if(can(m)){
                        r = m;
                } else{
                        l = m + 1;
                }
        }
        cout << l + n << "\n";
}