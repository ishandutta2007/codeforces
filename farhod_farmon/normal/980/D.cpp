#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 5050;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int a[N];
int ans[N];
bool usa[Q];
bool usb[Q];

int get(int x)
{
        int y = 1;
        if(x < 0){
                y = -y;
                x = -x;
        }
        for(int i = 2; i * i <= x; i++){
                int cnt = 0;
                while(x % i == 0){
                        x /= i;
                        cnt++;
                }
                if(cnt % 2 == 1){
                        y *= i;
                }
        }
        if(x > 1){
                y *= x;
        }
        return y;
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                if(a[i]) a[i] = get(a[i]);
        }
        for(int i = 1; i <= n; i++){
                int k = 0;
                int h = i;
                while(h <= n && a[h] == 0){
                        ans[1]++;
                        h++;
                }
                if(h > i){
                        k = 1;
                        if(a[h] < 0){
                                usa[-a[h]] = 1;
                        }
                        else{
                                usb[a[h]] = 1;
                        }
                }
                for(int j = h; j <= n; j++){
                        if(a[j] < 0 && !usa[-a[j]]){
                                usa[-a[j]] = 1;
                                k++;
                        }
                        else if(a[j] > 0 && !usb[a[j]]){
                                usb[a[j]] = 1;
                                k++;
                        }
                        ans[k]++;
                }
                for(int j = h; j <= n; j++){
                        if(a[j] < 0){
                                usa[-a[j]] = 0;
                        }
                        else{
                                usb[a[j]] = 0;
                        }
                }
        }
        for(int i = 1; i <= n; i++){
                cout << ans[i] << " ";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("maze.in");
        //fout("maze.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}