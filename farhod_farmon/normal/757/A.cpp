#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 100100;

using namespace std;

int a[200];
int b[200];
string s;
string need = "Bulbasaur";

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> s;
        for(int i = 0; i < s.size(); i++){
                a[s[i]]++;
        }
        for(int i = 0; i < need.size(); i++){
                b[need[i]]++;
        }
        int ans = 1e9;
        for(int i = 0; i < 200; i++){
                if(b[i]){
                        ans = min(ans, a[i] / b[i]);
                }
        }
        cout << ans << "\n";
}