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
ll t,a , b;
int main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin); 
  freopen("out.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);cout.tie(NULL);
  cin >> t;
  for(int i = 0; i < t; i++){
      cin >> a >> b;
      b--;
      int n = 1, say = 0, s2 = 1;
      while(say + s2 <= b){
        n++;
        say += s2++;
      }
      //n++;
      //cout << b << " " << n << " ";
      int n2 = b-say;
      //cout << n2 <<" ";
      
      string s;
      for(int j = 0; j < a; j++){
        if(j == n || j == n2){
          s += 'b';
        }
        else s+= 'a';
      }
      reverse(all(s));
      cout <<s  << ln;
  }
}