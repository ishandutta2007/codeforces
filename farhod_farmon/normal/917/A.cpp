#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 5005;
const long long Q = 6000100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

string s;

void solve()
{
        int ans = 0;
        cin >> s;
        for(int i = 0; i < s.size(); i++){
                int l = 0, r = -1, cur = 0, in = -1;
                for(int j = i; j < s.size(); j++){
                        if(s[j] == '('){
                                cur++;
                        }
                        else if(s[j] == ')'){
                                cur--;
                                if(cur == -1){
                                        if(r - l < 0){
                                                break;
                                        }
                                        in--;
                                        l++;
                                        cur = 0;
                                }
                        }
                        else{
                                r++;
                        }
                        in = max(in, r - cur);
                        int sz = r - l + 1;
                        if(in < r - cur + 1 && sz >= cur && (sz - cur) % 2 == 0){
                                ans++;
                        }
                }
        }
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("bootfall.in");
        //fout("bootfall.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}