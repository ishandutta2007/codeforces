#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1010;
const long long MX = 1000010;
const long long H = 17;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int a[N];
int l[N];
bool used[N];

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                a[i] = -1;
        }
        for(int i = 1; i <= m; i++){
                cin >> l[i];
                if(i > 1){
                        int cnt = 0;
                        for(int j = l[i - 1]; j != l[i]; j = j % n + 1){
                                cnt++;
                        }
                        if(cnt == 0){
                                cnt = n;
                        }
                        int h = l[i - 1];
                        if(a[h] == -1){
                                a[h] = cnt;
                                if(used[cnt]){
                                        cout << -1 << endl;
                                        return;
                                }
                                used[cnt] = true;
                        }
                        else if(a[h] != cnt){
                                cout << -1 << endl;
                                return;
                        }
                }
        }
        for(int i = 1, j = 1; i <= n; i++){
                while(used[j]){
                        j++;
                }
                if(a[i] == -1){
                        a[i] = j;
                        used[j] = true;
                }
                cout << a[i] << " ";
        }
        cout << "\n";
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
                sc("%d", &TE);
        while(TE--)
                solve();
        return 0;
}