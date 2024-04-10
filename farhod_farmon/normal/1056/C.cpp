#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define fi first
#define se second
#define ll long long

const int N = 2010;

using namespace std;

int n;
int m;
int a[N];
int p[N];
bool used[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        n += n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                p[x] = y;
                p[y] = x;
        }
        int pre = -1;
        int t;
        cin >> t;
        for(int it = 1; it <= n; it++){
                if(t == 1){
                        if(pre != -1 && p[pre] && !used[p[pre]]){
                                cout << p[pre] << endl;
                                pre = p[pre];
                        }
                        else{
                                int in = -1;
                                for(int i = 1; i <= n; i++){
                                        if(used[i]){
                                                continue;
                                        }
                                        if(p[i]){
                                                in = i;
                                                break;
                                        }
                                }
                                if(in != -1){
                                        if(a[in] < a[p[in]]){
                                                in = p[in];
                                        }
                                        cout << in << endl;
                                        pre = in;
                                }
                                else{
                                        int in = -1;
                                        for(int i = 1; i <= n; i++){
                                                if(used[i]){
                                                        continue;
                                                }
                                                if(in == -1 || a[i] > a[in]){
                                                        in = i;
                                                }
                                        }
                                        cout << in << endl;
                                        pre = in;
                                }
                        }
                }
                else{
                        cin >> pre;
                }
                used[pre] = true;
                t = 3 - t;
        }
}