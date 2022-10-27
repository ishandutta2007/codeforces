#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct Itrv{
    ll l, r;
    int id;
    Itrv(ll il = 0, ll ir = 0, int iid = 0){
        l = il; r = ir; id = iid;
    }
};

bool cmp(Itrv &a, Itrv &b){
    return a.l < b.l;
}

ll l[200005], r[200005];
pair<ll,int> a[200005];
Itrv arr[200005];
int ans[200005];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    int n, m;
    cin>>n>>m;

    if(m < n-1){
        cout<<"No"<<endl;
        return 0;
    }

    for(int i = 1; i <= n; i++){
        cin>>l[i]>>r[i];
    }
    for(int i = 1; i <= m; i++){
        cin>>a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + m + 1);
    for(int i = 1; i < n; i++){
        ans[i] = -1;
        arr[i] = Itrv(l[i+1] - r[i], r[i+1] - l[i], i);
    }
    sort(arr + 1, arr + n, cmp);
    int i = 1;
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;
    for(int j = 1; j <= m; j++){
        while(i < n && arr[i].l <= a[j].first){
            pq.push({arr[i].r, arr[i].id});
            i++;
        }
        while(!pq.empty()){
            pair<ll, int> y = pq.top();
            pq.pop();
            if(y.first < a[j].first)continue;
            ans[y.second] = a[j].second;
            break;
        }
    }
    for(int i = 1; i < n; i++){
        if(ans[i] == -1){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    for(int i = 1; i < n; i++){
        cout<<ans[i]<<" ";
    }
}