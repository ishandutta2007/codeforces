#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 55;

using namespace std;

int n;
char a[N];
bool used[N];
string need = "abacaba";

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                cin >> n;
                for(int i = 1; i <= n; i++){
                        cin >> a[i];
                        used[i] = 0;
                        if(a[i] == '?'){
                                used[i] = 1;
                                a[i] = 'd';
                        }
                }
                bool gg = false;
                for(int i = 1; i + 6 <= n; i++){
                        bool good = true;
                        for(int j = 1; j <= n; j++) if(used[j]) a[j] = 'd';
                        for(int j = 0; j < 7; j++){
                                if(a[i + j] != need[j]){
                                        if(!used[i + j]){
                                                good = false;
                                                break;
                                        }
                                        else a[i + j] = need[j];
                                }
                        }
                        if(!good) continue;
                        int cnt = 0;
                        for(int j = 1; j + 6 <= n; j++){
                                good = true;
                                for(int h = 0; h < 7; h++){
                                        if(a[h + j] != need[h]){
                                                good = false;
                                                break;
                                        }
                                }
                                if(good){
                                        cnt += 1;
                                }
                        }
                        if(cnt == 1){
                                gg = true;
                                break;
                        }
                }
                if(gg){
                        cout << "yes" << "\n";
                        for(int i = 1; i <= n; i++) cout << a[i];
                        cout << "\n";
                } else cout << "no" << "\n";
        }
}