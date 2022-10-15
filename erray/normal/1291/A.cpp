    #include <bits/stdc++.h>
typedef long long ll;
#define st first 
#define nd second 
#define pb push_back
#define mp make_pair 
#define MAX 1000000009
#define MOD 1000000007
#define For(ii,aa,bb) for(ll ii = aa; ii < bb;ii++)  
#define Rof(ii,aa,bb) for(ll ii = aa - 1; ii >= bb;ii--)
#define IT iterator 
#define ln "\n"
#define mid (start + end)/2
#define R(ii) (ii * 2) + 1
#define L(ii) (ii * 2)
#define pp pair<ll,ll> 
#define all(vv) vv.begin(),vv.end()
#define N 10005
using namespace std;
ll t, x, y, n;
string s;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--){
        cin >> n >>  s;
        ll sum = 0;
        reverse(all(s)); 
        while (s[s.size() - 1] == '0'){
            s.erase(s.end() - 1);
        }
        reverse(all(s));
        For(i, 0, s.size()){
            sum += s[i] - '0';
        }
        while ((s[s.size() - 1] - '0') % 2 == 0 && !s.empty()){
            s.erase(s.end() - 1);
        }
        if (sum % 2 == 0){
            if (s.empty()){
                cout << -1 << ln;
            }
            else {
                cout << s << ln;
            }
        }
        else {
            ll a = -1;
            For(i, 0, s.size()){
                if ((s[i] - '0')%2 == 1){
                    s.erase(s.begin() + i);
                    a = i;
                    break;
                }
            }
            if (a == -1){
                cout << a << ln;
            }
            else {
                while ((s[s.size() - 1] - '0') % 2 == 0 && !s.empty()){
                    s.erase(s.end() - 1);
                } 
                if (s.empty()){
                    cout << -1 << ln;
                }
                else {
                    reverse(all(s));
                    while (s[s.size() - 1] == '0'){
                        s.erase(s.end() - 1);
                    }
                    reverse(all(s));
                    if (s.empty()){
                        cout << -1 << ln;
                    }
                    else {
                        cout << s << ln;
                    }
                }
            }
        }
        
    }
    return 0;
}