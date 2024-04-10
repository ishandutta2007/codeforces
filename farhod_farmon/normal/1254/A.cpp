#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 110;
const long long mod = 1e9 + 7;

using namespace std;

int k;

char make(int x)
{
        x = min(x, k - 1);
        if(x < 26){
                return 'A' + x;
        } else if(x < 52){
                return 'a' + (x - 26);
        } else{
                return '0' + (x - 52);
        }
}

int n;
int m;
int a[N][N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int T;

        cin >> T;
        while(T--){
                cin >> n >> m >> k;
                int G = 0, shit = 0;
                for(int i = 1; i <= n; i++){
                        for(int j = 1; j <= m; j++){
                                char c;
                                cin >> c;
                                a[i][j] = 0;
                                if(c == 'R'){
                                        a[i][j] = 1;
                                        G += 1;
                                }
                        }
                }
                shit = G % k;
                G /= k;
                if(shit > 0){
                        G += 1;
                }
                int need = 0, id = 0;
                for(int i = 1; i <= n; i++){
                        string res = "";
                        if(i % 2){
                                for(int j = 1; j <= m; j++){
                                        res += make(id);
                                        need += a[i][j];
                                        if(need == G){
                                                shit -= 1;
                                                if(shit == 0){
                                                        G -= 1;
                                                }
                                                need = 0;
                                                id += 1;
                                        }
                                }
                        } else{
                                for(int j = m; j >= 1; j--){
                                        res += make(id);
                                        need += a[i][j];
                                        if(need == G){
                                                shit -= 1;
                                                if(shit == 0){
                                                        G -= 1;
                                                }
                                                need = 0;
                                                id += 1;
                                        }
                                }
                                reverse(res.begin(), res.end());
                        }
                        cout << res << "\n";
                }
        }
}