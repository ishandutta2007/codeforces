#include <bits/stdc++.h>
typedef long long  ll;
typedef unsigned long long int ull;
#define st first 
#define nd second 
#define pb push_back
#define mp make_pair 
#define MAX 1000000009
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define IT iterator 
#define ln "\n"
#define mid (start + end)/2
#define R(ii) (ii * 2) + 1
#define L(ii) (ii * 2)
#define pp pair<ll,ll> 
#define vi vector<ll> 
#define all(vv) vv.begin(),vv.end()
#define N 1000005
using namespace std;       
ll q, t, n;
string s;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> q;
    while(q--){
        cin >> n >>  s;
        map <pp, ll> ct;
        ll udc = 0, rlc = 0;
        bool flag = false;
        pp ans = mp(0, MAX);
        for(int i = 1; i <= n; i++){
            if (s[i -1] == 'L'){
                rlc--;
            }
            else if (s[i - 1] == 'R'){
                rlc++;
            }
            else if (s[i - 1] == 'U'){
                udc++;  
            }
            else {
                udc--;
            }
            if (ct[mp(rlc, udc)] != 0 || (rlc == 0 && udc == 0)){
                if (i - ct[mp(rlc, udc)] < (ans.nd - ans.st)){
                    ans = mp(ct[mp(rlc, udc)], i);
                    flag = true;
                }
            }
            ct[mp(rlc, udc)] = i;
        }
        if (flag){
            cout << ans.st + 1 << " " << ans.nd << ln;
        }
        else{
            cout << -1 << ln;
        }
    }
}