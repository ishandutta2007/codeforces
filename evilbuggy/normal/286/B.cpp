#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

deque<int> q;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        q.push_back(i);
    }
    for(int l = 2; l <= n; l++){
        int pre = q.front();
        for(int i = l; i < n; i += l){
            swap(q[i], pre);
        }
        q.push_back(pre);
        q.pop_front();
    }
    for(int i = 0; i < n; i++){
        cout<<q[i]+1<<" ";
    }
    cout<<endl;
}