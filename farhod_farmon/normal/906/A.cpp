#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 60100;
const long long Q = 5000010;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
bool used[200];
set < char > s;

void solve()
{
        cin >> n;
        for(int i = 'a'; i <= 'z'; i++){
                s.insert(i);
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
                char c, x;
                string t;
                cin >> c;
                if(c == '.'){
                        cin >> t;
                        for(int j = 0; j < t.size(); j++){
                                s.erase(t[j]);
                        }
                }
                else if(c == '?'){
                        cin >> x;
                        if(s.size() == 1 && *s.begin() != x){
                                cnt++;
                        }
                        s.erase(x);
                }
                else{
                        if(s.size() == 1){
                                cnt++;
                        }
                        cin >> t;
                        for(int j = 0; j < t.size(); j++){
                                used[t[j]] = 1;
                        }
                        for(int j = 'a'; j <= 'z'; j++){
                                if(!used[j]){
                                        s.erase(j);
                                }
                        }
                        for(int j = 0; j < t.size(); j++){
                                used[t[j]] = 0;
                        }
                }
        }
        cout << cnt << "\n";
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