#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int Q = 1000100;
const long long mod1 = 1e9 + 9;
const long long mod2 = 1e9 + 7;

using namespace std;

int n;
int a[N];
string s[N];
set < int > d[Q];
vector < pair < int, int > > v[200];
vector < char > g = {'a', 'e', 'o', 'i', 'u'};


int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> s[i];
                int cnt = 0;
                char last;
                for(char c: s[i]){
                        int ok = 0;
                        for(char y: g){
                                if(c == y){
                                        ok = 1;
                                        break;
                                }
                        }
                        if(ok){
                                last = c;
                                cnt += 1;
                        }
                }
                a[i] = cnt;
                d[cnt].insert(i);
                v[last].push_back({cnt, i});
        }
        vector < pair < int, int > > A, B;
        for(int i = 0; i < 200; i++){
                if(v[i].empty()){
                        continue;
                }
                sort(v[i].begin(), v[i].end());
                for(int j = 0; j + 1 < v[i].size(); j++){
                        if(v[i][j].fi == v[i][j + 1].fi){
                                int x = v[i][j].se, y = v[i][j + 1].se;
                                d[a[x]].erase(x);
                                d[a[y]].erase(y);
                                A.push_back({x, y});
                                j += 1;
                        }
                }
        }
        for(int i = 1; i < Q; i++){
                while(d[i].size() > 1){
                        int x = *d[i].begin();
                        d[i].erase(d[i].begin());
                        int y = *d[i].begin();
                        d[i].erase(d[i].begin());
                        B.push_back({x, y});
                }
        }
        int res = min((int)A.size(), (int)B.size());
        res += ((int)A.size() - res) / 2;
        cout << res << "\n";
        while(!A.empty() && !B.empty()){
                cout << s[B.back().fi] << " " << s[A.back().fi] << "\n";
                cout << s[B.back().se] << " " << s[A.back().se] << "\n";
                A.pop_back();
                B.pop_back();
        }
        while(A.size() > 1){
                int g = A.size();
                cout << s[A[g - 1].fi] << " " << s[A[g - 2].fi] << "\n";
                cout << s[A[g - 1].se] << " " << s[A[g - 2].se] << "\n";
                A.pop_back();
                A.pop_back();
        }
}