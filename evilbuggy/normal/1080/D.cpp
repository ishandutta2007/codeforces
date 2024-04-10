#include <bits/stdc++.h>

using namespace std;

long long int findMax(long long int k){
    long long int l = 0;
    long long int sum = 0;
    while(sum <= k){
        l++;
        sum += (1LL<<l) - 1;
    }
    return l-1;
}

int main(){
    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        long long int n,k;
        cin>>n>>k;
        long long int l = findMax(k);
        if(n > 31){
            cout<<"YES "<<(n-1)<<endl;
            continue;
        }
        l = n - min(l, n);
        long long int tmp1 = ((1LL<<(2*n))-1)/3;
        long long int tmp2 = (((1LL<<(2*l))-1)/3)*((1<<(n-l+1)) - 1);
        if(k <= tmp1 - tmp2){
            cout<<"YES "<<l<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    
}