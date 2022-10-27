#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool arr[1000005];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    memset(arr, false, sizeof(arr));
    int n, xx;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>xx;
        arr[xx] = true;
    }
    vector<int> ans;
    stack<pair<int,int> > x, y;
    for(int i = 1; i <= 500000; i++){
        if(arr[i] && arr[1000001 - i]){
            if(y.empty()){
                x.push({i, 1000001 - i});
            }else{
                pair<int,int> tmp = y.top();
                ans.push_back(tmp.first);
                ans.push_back(tmp.second);
                y.pop();
            }
        }else if(arr[i]){
            ans.push_back(1000001 - i);
        }else if(arr[1000001 - i]){
            ans.push_back(i);
        }else{
            if(x.empty()){
                y.push({i, 1000001 - i});
            }else{
                x.pop();
                ans.push_back(i);
                ans.push_back(1000001 - i);
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto xy : ans){
        cout<<xy<<" ";
    }

}