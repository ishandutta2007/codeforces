#include <bits/stdc++.h>

#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("O3")

using namespace std;
typedef long long ll;

ll n, p10[19];
unordered_map<ll, int> dist;
string tot;
//x25, x50, x75, x00

int bfs(ll n) {
    dist[n] = 0;

    queue<ll> fila;
    fila.push(n);

    tot = to_string(n);
    int tam = tot.size()-1;

    while(!fila.empty()) {
        ll u = fila.front(); fila.pop();
        string str = to_string(u);
        int du = dist[u], sz = str.size();
        //if(clock() * 1.0 / CLOCKS_PER_SEC > 0.95) return -1;

        for(int i = 0; i + 1 < sz; i++) {
            char c = str[i];
            if(c == '1') continue;

            int x = str[i] - '0', y = str[i+1] - '0';
            if(x != y) {
                ll v = u - p10[sz - i - 1]*x - p10[sz - i - 2]*y;
                      v += p10[sz - i - 1]*y + p10[sz - i - 2]*x;

                if(v < p10[tam]) continue;
                if(!dist.count(v)) {
                    dist[v] = du + 1;
                    if(v % 25 == 0) return du + 1;
                    fila.push(v);
                }
            }
        }
    }
    return -1;
}

char s[20]; string str;
int f[11];

int main() {
     scanf("%s", s); str = s;
     for(int i = 0; i < str.size(); i++) {
         char c = str[i];
         if(c != '0' && c != '2' && c != '5' && c != '7') str[i] = '1';
         f[str[i] - '0']++;
     } reverse(str.begin(), str.end());

     p10[0] = 1;
     for(int i = 1; i < 19; i++) p10[i] = p10[i-1] * 10;

     if(f[5] < 1)
        for(char &c : str)
            if(c == '2' || c == '7') c = '1';

     n = 0;
     for(int i = 0; i < str.size(); i++) {
         n += (str[i] - '0') * p10[i];
     }

     if(n % 25 == 0) printf("0");
     else {
         if(f[0] < 2 && (f[2] < 1 || f[5] < 1) && (f[0] < 1 || f[5] < 1) && (f[7] < 1 || f[5] < 1))
            printf("-1\n");
         else printf("%d\n", bfs(n));
     }
    return 0;
}