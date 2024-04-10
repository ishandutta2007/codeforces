#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int arr[1005];

bool inc(int n){
    arr[0] = 0;
    for(int i = 1; i <= n; i++){
        if(!arr[i])return false;
        if(arr[i] < arr[i-1])return false;
    }
    return true;
}

int main(){

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    int x, n, m, c;
    cin>>n>>m>>c;
    int limn = n/2;
    int limc = c/2;
    memset(arr, 0, sizeof(arr));
    for(int i = 1; i <= m; i++){
        cin>>x;
        if(x <= limc){
            for(int i = 1; i <= n; i++){
                if(arr[i] == 0 || arr[i] > x){
                    arr[i] = x;
                    cout<<i<<endl;
                    fflush(stdout);
                    break;
                }
            }
        }else{
            for(int i = n; i >= 1; i--){
                if(arr[i] == 0 || arr[i] < x){
                    arr[i] = x;
                    cout<<i<<endl;
                    fflush(stdout);
                    break;
                }
            }
        }
        if(inc(n)){
            break;
        }
    }
}