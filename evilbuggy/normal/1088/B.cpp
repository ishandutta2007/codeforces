#include <bits/stdc++.h>

using namespace std;

int main(){
    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, n, k;
    cin>>n>>k;

    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i = 0; i < n; i++){
        cin>>x;
        pq.push(x);
    }

    int mini = 0;

    while(k > 0){
        if(pq.empty()){
            cout<<0<<endl;
            k--;
        }else{
            int y = pq.top();
            pq.pop();
            if(y == mini)continue;
            cout<<y-mini<<endl;
            mini = y;
            k--;
        }
    }
}