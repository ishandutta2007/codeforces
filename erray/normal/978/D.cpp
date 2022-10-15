#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define umap unordered_map
#define ff(zz) for(int i = zz; i; i--)
#define all(v) v.begin(),v.end()
#define st first
#define nd second
#define ln '\n'
#define MAX 1000000009
#define MOD 1000000007
#define N 200005
using namespace std;
typedef long long ll;
typedef pair<ll ,ll> pii;
typedef vector<int> vi; 
int t, n, arr[N];
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    for(int i = 0; i <t; i++){
        cin >> arr[i];
    }
    if(t <= 2){
        cout << 0;
        return 0;
    }
    int ans = MAX;
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            int a = arr[0] + i, b = arr[1] + j;
            int fark = b-  a, cnt = abs(i) + abs(j);
            int lst = b+ fark; 
            for(int q = 2; q < t; q++){
                //cout << lst << ln;
                if(abs(lst - arr[q]) > 1 || lst <= 0){
                    cnt = -1;
                    break;
                }
                else cnt += abs(lst - arr[q]);
                lst += fark;
            } 
            if(cnt == -1){
                continue;
            }
            else ans = min(cnt, ans);
        }
    }
    cout << (ans == MAX ? -1 : ans);
}