#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<int> factors(int n){
    vector<int> tmp;
    for(int i = 1; i * i <= n; i++){
        if(n%i == 0){
            if(i*i != n){
                tmp.push_back(i);
                tmp.push_back(n/i);
            }else{
                tmp.push_back(i);
            }
        }
    }
    return tmp;
}

int last[100005];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(last, 0, sizeof(last));
    int n, x, y;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>x>>y;
        vector<int> f = factors(x);
        int cnt = 0;
        for(auto fac : f){
            if(last[fac] < i - y)cnt++;
            last[fac] = i;
        }
        cout<<cnt<<endl;
    }

}