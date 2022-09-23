#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 400100;
const long long Q = 2e18;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int k;
string s;
bool used[N];
vector < int > v[200];

void solve()
{
        cin >> n >> k >> s;
        for(int i = 0; i < n; i++){
                v[s[i]].push_back(i);
        }
        for(int i = 0; i < 200; i++){
                reverse(v[i].begin(), v[i].end());
        }
        for(int i = 0; i < k; i++){
                for(int j = 'a'; j <= 'z'; j++){
                        if(!v[j].empty()){
                                used[v[j].back()] = 1;
                                v[j].pop_back();
                                break;
                        }
                }
        }
        for(int i = 0; i < n; i++){
                if(!used[i]){
                        cout << s[i];
                }
        }
        cout << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("island.in");
        //fout("island.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}