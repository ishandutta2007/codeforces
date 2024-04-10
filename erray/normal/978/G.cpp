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
#define N 100005
using namespace std;
typedef long long ll;
typedef pair<ll ,ll> pii;
typedef vector<int> vi;   
int n, m,a, b, c, kal[N], fns[N];
vector  <pair <pii, pii>  > v;  
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        v.pb(mp(mp(a, b), mp(c, i + 1)));
        kal[i + 1] = c;
        fns[b] = i + 1;
    }
    priority_queue <pii, vector <pii>, greater <pii> > pq;
    vector <int> ans; 
    sort(all(v));
    for(int i = 1; i <= n; i++){
        while(!v.empty() && v[0].st.st == i){
            pq.push(mp(v[0].st.nd, v[0].nd.nd));
            v.erase(v.begin());
        }   
        if(fns[i] == 0){
            if(pq.empty()){
                ans.pb(0);
            }
            else {
                ans.pb(pq.top().nd);
                if(--kal[pq.top().nd] == 0){
                    pq.pop();
                }
                //cout << kal[pq.top().nd]  << " ";
            }
        }
        else {
            ans.pb(m + 1);
            if(kal[fns[i]] != 0){
                cout << -1;
                return 0;
            }
        }
        //cout << ans[ans.size() - 1] << ln;
    } 
    for(auto a: ans)cout << a<< " ";
}