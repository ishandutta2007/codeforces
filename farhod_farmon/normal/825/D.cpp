#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int a[200];
int b[200];
int ne[200];
string s, t;

void solve()
{
        cin >> s >> t;
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
                if(s[i] != '?') a[s[i]]++;
                else cnt++;
        }
        for(int i = 0; i < t.size(); i++) b[t[i]]++;
        int l = 0, r = 1e6;
        while(l < r){
                int m = (l + r) / 2 + 1;
                long long have = cnt;
                for(char c = 'a'; c <= 'z'; c++){
                        long long need = 1ll * b[c] * m;
                        have -= max(0ll, need - a[c]);
                }
                if(have >= 0){
                        l = m;
                }
                else{
                        r = m - 1;
                }
        }
        for(char c = 'a'; c <= 'z'; c++){
                long long need = b[c] * l;
                ne[c] = max(0ll, need - a[c]);
        }
        for(int i = 0; i < s.size(); i++){
                char c = 'a';
                if(s[i] == '?'){
                        for(int j = 'a'; j <= 'z'; j++){
                                if(ne[j]){
                                        c = j;
                                        ne[j]--;
                                        break;
                                }
                        }
                        s[i] = c;
                }
        }
        cout << s << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("landscape.in");
        //fout("landscape.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}