#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int k;
char c[N];
bool used[200];

void solve()
{
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> c[i];
                used[c[i]] = 1;
        }
        int last = -1;
        for(int i = 1; i <= min(n + 1, k); i++){
                bool can = 0;
                for(int j = 'a'; j <= 'z'; j++){
                        if(!used[j]){
                                continue;
                        }
                        if(j > c[i]){
                                can = 1;
                        }
                }
                if(can){
                        last = i;
                }
        }
        for(int i = 1; i < last; i++){
                cout << c[i];
        }
        for(char j = 'a'; j <= 'z'; j++){
                if(used[j] && j > c[last]){
                        cout << j;
                        break;
                }
        }
        for(char j = 'a'; j <= 'z'; j++){
                if(used[j]){
                        for(int i = last + 1; i <= k; i++){
                                cout << j;
                        }
                        break;
                }
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