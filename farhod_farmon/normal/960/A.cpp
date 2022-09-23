#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 3000100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

string s;
vector < pair < char, int > > v;

void solve()
{
        cin >> s;
        int cnt = 0, last = -1;
        for(int i = 0; i < s.size(); i++){
                if(s[i] == last){
                        cnt++;
                }
                else{
                        if(cnt > 0){
                                v.push_back({last, cnt});
                        }
                        cnt = 1;
                        last = s[i];
                }
        }
        v.push_back({last, cnt});
        if(v.size() != 3){
                cout << "NO" << "\n";
        }
        else if(v[0].fi != 'a' || v[1].fi != 'b' || v[2].fi != 'c'){
                cout << "NO" << "\n";
        }
        else if(v[0].se == v[2].se || v[1].se == v[2].se){
                cout << "YES" << "\n";
        }
        else{
                cout << "NO" << "\n";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}