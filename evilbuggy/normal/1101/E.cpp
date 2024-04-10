#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int q, x, y;
    cin>>q;
    char ch;
    int mini, maxi;
    for(int i = 0; i < q; i++){
        cin>>ch>>x>>y;
        if(i == 0){
            mini = min(x, y);
            maxi = max(x, y);
        }else if(ch == '+'){
            if(x > y)swap(x, y);
            mini = max(x, mini);
            maxi = max(y, maxi);
        }else{
            if(x > y)swap(x, y);
            if(mini <= x && maxi <= y){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
}