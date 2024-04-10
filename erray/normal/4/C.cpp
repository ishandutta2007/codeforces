#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define umap unordered_map
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
int n;
string s;
map <string, int> m;
vector <string> v;  
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    string lst = "0";
    v.pb(lst);
    for(int i = 1; i <  N; i++){
        int now = lst.size() - 1;
        while(lst[now] == '9'){
            lst[now--] = '0';
        }
        if(now < 0){
            lst = '1' + lst;
        }
        else {
            lst[now] += 1;
        }
        v.pb(lst);
    }
    cin >> n;
    while(n--){
        cin >> s;
        if(++m[s] == 1){
            cout << "OK";
        }
        else {
            cout << s << v[m[s] - 1];
        }
        cout << ln;
    }
    
}