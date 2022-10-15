  #include<bits/stdc++.h>
  #define pb push_back
  #define mp make_pair
  #define umap unordered_map
  #define all(v) v.begin(),v.end()
  #define st first
  #define nd second
  #define L (no<<1)
  #define R L|1
  #define mid (s + e)>>1
  #define ln '\n'
  #define MAX (1<<30)
  #define MOD 1000000007
  #define mod 998244353
  #define N 500005
  using namespace std;
  typedef long long ll;
  typedef pair<ll ,ll> pii;
  typedef vector<int> vi;
  int t, n, x;
  int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); 
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n;
        vi v;
        set <int> s; 
        while(n--){
          cin >> x;
          s.insert(x);
          v.pb(x);
        }
        if(v[0] == v[v.size() - 1]){
          if(s.size() == 1){
              cout << 1 << ln;
              for(int i = 0; i < v.size(); i++){
                cout << 1 << " ";
              } 
          }
          else {
            cout << 2 << ln;
            int num = 1;
            cout << num << " ";
            for(int i = 1; i < v.size(); i++){
              if(v[i] != v[i - 1]){
                num = (num == 1 ? 2 : 1);
              }
              cout << num << " ";
            }
          }
        }
        else {
          int now = 0;
          for(int i = 0; i < v.size() - 1; i++){
              if(v[i] == v[i + 1]){
                now = i + 1;
              }
          }
          if(now == 0 && v.size() % 2 == 1){
              cout << 3 << ln;
              for(int i = 0; i < v.size(); i++){
                if(i == v.size() - 1){
                    cout << 3;
                }
                else cout << 1 + (i%2)<<" ";
              }
          }
          else {
            cout << 2 << ln;
            vi ans1, ans2;
            int num = 1;
            ans1.pb(num);
            for(int i = 1; i < v.size(); i++){
              if(v[i] != v[i - 1]){
                num = (num == 1 ? 2 : 1);
              }
              ans1.pb(num);
            }
            if(ans1[0] == ans1[ans1.size() - 1]){
              num = 1;
              cout << num << " ";
              for(int i = 1; i < v.size(); i++){
                 if(v[i] != v[i - 1] || i == now){
                num = (num == 1 ? 2 : 1);
                }
                cout << num << " ";
              }
            }
            else {
              for(auto a : ans1){
                cout << a << " ";
              }
            } 
          }
         
        }
        cout << ln;
    }

  }