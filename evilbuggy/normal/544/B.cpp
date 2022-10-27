#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

int countMax(int n){
    if(n%2 == 0)return n*n/2;
    return n*(n/2) + (n+1)/2;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin>>n>>k;
    int m = countMax(n);
    if(k > m)cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i%2 == j%2){
                    if(k > 0){
                        cout<<'L';
                        k--;
                    }else{
                        cout<<'S';
                    }
                }else{
                    cout<<'S';
                }
            }
            cout<<endl;
        }
    }
}