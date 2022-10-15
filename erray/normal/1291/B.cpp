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
#define N 50005
using namespace std;
ll t, x, n;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    
  
    while (t--){
        vector <ll> v;
        cin >> x;
        For(i, 0, x){
            cin >> n;
            v.pb(n);
        }
        vector <ll> tmp = v;  
        v[0] = 0;
        ll now = 1;
        while ((v[now - 1] + 1) <= v[now] && now < v.size()){
            v[now] = v[now - 1]+1;
            now++;
        }
        //cout << now << ln;
        ll now2 = 1;
        reverse(all(tmp));
        tmp[0] = 0;
        while ((tmp[now2 - 1] + 1) <= tmp[now2] && now2 < v.size()){
            tmp[now2] = tmp[now2 - 1] + 1;
            now2++;
        }
        //out << now2 << ln;
        if (now > (x - now2)){
            cout << "Yes" << ln;
        }
        else {
            cout << "No" << ln;
        }
           
    }
    return 0;
}