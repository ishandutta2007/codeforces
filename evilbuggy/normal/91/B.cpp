#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

pair<int,int> a[100005];
int ans[100005];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>x;
        a[i] = {x, i};
    }
    sort(a + 1, a + n + 1);
    int ind;
    for(int i = 1; i <= n; i++){
        if(i == 1){
            ans[a[i].second] = -1;
            ind = a[i].second;
        }else{
            if(ind < a[i].second){
                ans[a[i].second] = -1;
                ind = a[i].second;
            }else{
                ans[a[i].second] = ind - a[i].second - 1;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout<<ans[i]<<" ";
    }
}