#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define umap unordered_map
#define all(v) v.begin(),v.end()
#define st first
#define nd second
#define L (nd<<1)
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
int n, k, ct[11];
string se;
int main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin); 
  freopen("out.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);cout.tie(NULL);
  cin >> n >> k >> se;
  //k += 4;
  string old = se;
  int ans = MAX;
  int eq = 0;
  vector <char> ch;
  sort(all(se));
  for(char c : se){
    ct[c - '0']++;
  }
  vector <pair <int, string> > alns; 
  for(int i = 0; i < 10; i++){
    auto  s= lower_bound(all(se), '0' + i), e = upper_bound(all(se), '0' + i);
    --s;
    vector<char>  tmp;
    int cost = 0;
    for(int j = 0; j <k - ct[i]; j++){
      //if(i == 8)cout << "asd" << ln;
      //cout << i << " ";
      if(s == se.begin() - 1){
        tmp.pb(*e);
        cost += *e - (i + '0');
        ++e;
      }
      else if(e == se.end()){
        tmp.pb(*s);
        cost += (i + '0') - *s;
        --s;
      }
      else {
        if((i + '0') - *s < *e - (i + '0')){
          tmp.pb(*s);
          cost += (i + '0') - *s;
          --s;
        }
        else {
           tmp.pb(*e);
          cost += *e - (i + '0');
          ++e;
        }
      } 
      //if(i == 8)cerr << e- se.begin() << " " <<  (s- se.begin()) << ln;
    } 

    string old2 = old;
    for(int q = 0; q < tmp.size(); q++){
    if(i < tmp[q] - '0'){
       for(int j = 0; j < se.size(); j++){
          if(old[j] == tmp[q]){
         //cout << "qwed" << ln;
          old[j] = i + '0';
         break;
        }
      }
    }
    else {
        for(int j = se.size() - 1; j >= 0; j--){
          if(old[j] == tmp[q]){
         //cout << "qwed" << ln;
          old[j] = i + '0';
         break;
        }
      }
    }
   
  }
    alns.pb(mp(cost, old));
    old = old2;
  }
  sort(all(alns));
  cout << alns[0].st << ln << alns[0].nd;
}