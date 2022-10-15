
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define umap unordered_map
#define flush fflush(stdout)
#define For(ii,aa,bb) for(int ii = aa; ii < bb; ii++) 
#define st first
#define nd second 
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ln "\n"
#define all(v) v.begin(),v.end()
#define MAX 1000000009
#define MOD 1000000007
#define mid (start + end) / 2 
#define R(ii) (ii + ii + 1)
#define L(ii) (ii + ii)
#define N 1000005
using namespace std;
typedef pair<ll,ll> pp;
typedef vector<ll> vi; 
ll n, t, x, a, b, k, m;
struct No{
    ll open;
    ll close;
    ll sum;
};
No tree[N * 10];
void upgrade(ll node, ll start, ll end, ll target, ll val){
   // cout << node << ln;
    if(start > target || end < target){
        return;
    }
    if(start == target && end == target){
        tree[node].open = val;
        tree[node].close = val;
        tree[node].sum = val;
        return ;
    }
    
   upgrade(L(node), start, mid, target, val);
    upgrade(R(node), mid + 1, end, target, val);
    No Left = tree[L(node)];
    No Right = tree[R(node)];
    tree[node].open = max(Left.open, Right.open + Left.sum);
    tree[node].close = min(Left.close, Right.close + Left.sum);
    tree[node].sum = Left.sum + Right.sum;
 //   cout << start << " "  << end << " values " << tree[node].sum << " " << tree[node].open  << " " << tree[node].close << " " << ln;
}
char c;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    ll cursor = 1;
    while(t--){
        cin >> c;
        if(c == 'R'){
            cursor++;
        }
        else if(c == 'L'){
            if(cursor > 1){
                  cursor--;
            }
          
        }
        else if(c == '('){
            upgrade(1, 1, N, cursor, 1);
        }
        else if(c == ')'){
             upgrade(1, 1, N, cursor, -1);
        }
        else{
             
             upgrade(1, 1, N, cursor, 0);
        }
        
        if(tree[1].sum == 0 && tree[1].close == 0){
            cout << tree[1].open << " ";
        }
        else {
            cout << -1 << " ";
        }
        
      //cout << ln;

    }
    return 0;
}