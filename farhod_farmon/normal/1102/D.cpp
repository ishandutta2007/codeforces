#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 300300;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int c[4];
string s;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> s;
        for(int i = 0; i < n; i++){
                c[s[i] - '0'] += 1;
        }
        for(int i = 0; i < n && c[0] < n / 3; i++){
                if(c[s[i] - '0'] <= n / 3){
                        continue;
                }
                if(s[i] != '0'){
                        c[s[i] - '0'] -= 1;
                        s[i] = '0';
                        c[s[i] - '0'] += 1;
                }
        }
        for(int i = 0; i < n && c[1] < n / 3; i++){
                if(c[s[i] - '0'] <= n / 3){
                        continue;
                }
                if(s[i] == '2'){
                        c[s[i] - '0'] -= 1;
                        s[i] = '1';
                        c[s[i] - '0'] += 1;
                }
        }
        for(int i = n - 1; i >= 0 && c[2] < n / 3; i--){
                if(c[s[i] - '0'] <= n / 3){
                        continue;
                }
                if(s[i] != '2'){
                        c[s[i] - '0'] -= 1;
                        s[i] = '2';
                        c[s[i] - '0'] += 1;
                }
        }
        for(int i = n - 1; i >= 0 && c[1] < n / 3; i--){
                if(c[s[i] - '0'] <= n / 3){
                        continue;
                }
                if(s[i] != '1'){
                        c[s[i] - '0'] -= 1;
                        s[i] = '1';
                        c[s[i] - '0'] += 1;
                }
        }
        cout << s << "\n";
}