#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000010;
const long long mod = 1000000007;
const int MAGIC = 2000;

using namespace std;

string s, t;
int z[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int c[2] = {0, 0};
        cin >> s >> t;
        for(int i = 0; i < s.size(); i++){
                c[s[i] - '0'] += 1;
        }
        int m = t.size();
        t = t + "#" + t;
        for(int i = 1, l = 0, r = 0; i < t.size(); i++){
                if(i <= r){
                        z[i] = min(r - i + 1, z[i - l]);
                }
                while(i + z[i] < t.size() && t[z[i]] == t[i + z[i]]){
                        z[i]++;
                }
                if(i + z[i] - 1 > r){
                        l = i;
                        r = i + z[i] - 1;
                }
        }
        int best = t.size();
        for(int i = m + 2; i < (int)t.size(); i++){
                if(i + z[i] == int(t.size())){
                        best = i;
                        break;
                }
        }
        int d[2] = {0, 0};
        int f[2] = {0, 0};
        for(int i = m + 1; i < t.size(); i++){
                d[t[i] - '0'] += 1;
                if(i < best){
                        f[t[i] - '0'] += 1;
                }
        }
        best = t.size() - (best - m - 1);
        if(c[0] >= d[0] && c[1] >= d[1]){
                for(int i = m + 1; i < t.size(); i++){
                        cout << t[i];
                }
                c[0] -= d[0];
                c[1] -= d[1];
                while(c[0] >= f[0] && c[1] >= f[1]){
                        c[0] -= f[0];
                        c[1] -= f[1];
                        for(int i = best; i < (int)t.size(); i++){
                                cout << t[i];
                        }
                }
        }
        while(c[0]){
                cout << 0;
                c[0]--;
        }
        while(c[1]){
                cout << 1;
                c[1]--;
        }
}