#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct Node{
    int t, d, w;
    Node(int it = 0, int id = 0, int iw = 0){
        t = it;
        d = id;
        w = iw;
    }
};

struct cmp{
    bool operator()(Node &a, Node &b){
        if(a.w != b.w)return a.w < b.w;
        return a.d < b.d;
    }
};

pair<int,int> arr[100005];
ll dp[100005][205];
vector<Node> a[100005];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    int n, k, m;
    cin>>n>>m>>k;
    
    for(int i = 1; i <= k; i++){
        int s, t, d, w;
        cin>>s>>t>>d>>w;
        a[s].push_back(Node(t, d, w));
    }
    priority_queue<Node, vector<Node>, cmp> pq;
    for(int i = 1; i <= n; i++){
        for(auto x : a[i]){
            pq.push(x);
        }
        arr[i] = {0, i + 1};
        while(!pq.empty()){
            Node y = pq.top();
            if(y.t >= i){
                arr[i] = {y.w, y.d + 1};
                break;
            }
            pq.pop();
        }
    }
    for(int i = 0; i <= m; i++){
        dp[n+1][i] = 0;
    }
    for(int i = n; i > 0; i--){
        dp[i][0] = dp[arr[i].second][0] + arr[i].first;
        for(int j = 1; j <= m; j++){
            dp[i][j] = min(dp[arr[i].second][j] + arr[i].first, dp[i+1][j-1]);
        }
    }
    cout<<dp[1][m]<<endl;
}