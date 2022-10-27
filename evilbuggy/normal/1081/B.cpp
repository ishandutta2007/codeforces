#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[100005], ans[100005];
vector<int> b[100005];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin>>n;
    map<int,int> arr;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        b[a[i]].push_back(i);
    }
    int ptr = 0;
    for(int i = 0; i < n; i++){
        if(b[i].size()%(n-i) != 0){
            cout<<"Impossible"<<endl;
            exit(0);
        }
        for(int j = 0; j < b[i].size(); j++){
            if(j%(n-i) == 0)ptr++;
            ans[b[i][j]] = ptr;
        }
    }
    cout<<"Possible"<<endl;
    for(int i = 1; i <= n; i++){
        cout<<ans[i]<<" ";
    }
}