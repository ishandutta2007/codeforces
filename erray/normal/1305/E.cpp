#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define flush fflush(stdout)
#define st first
#define nd second
#define umap unordered_map
#define all(v) v.begin(),v.end()
#define ln '\n'
#define MOD 1000000007
#define N 1005
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
int n, a, b, tar;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    cin >> n >> tar;
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += i / 2;
        //  cout << ans << ln;
        if(ans >= tar){
            if(i == 0){
                for(int j = 0; j < n; j++){
                    cout << MOD - 7 - (n - j) << " ";
                }
                return 0;
            }
            int fark =  i + (ans - tar)*2 + 1;
            for(int j = 0;  j < i; j++){
                cout << j + 1 << " ";
            }

            cout << fark << " ";
            for(int j = i + 1; j < n; j++){
                cout << MOD - 7 - ((n - j) * (fark + 1))   << " ";
            }
            return 0;
        }

    }
    cout << -1;




}