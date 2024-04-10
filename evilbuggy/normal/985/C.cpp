#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair

int a[100005];

int main(){
    int n,k,l,m;
    cin>>n>>k>>l;
    m = n*k;
    for(int i = 0; i < m; i++){
        cin>>a[i];
    }
    sort(a, a+m);
    int mini = 0;
    for(int i = 0; i < m; i++){
        if(a[i] - a[0] <= l){
            mini = i;
        }else{
            break;
        }
    }
    if(mini+1 < n){
        cout<<0<<endl;
    }else{
        int i = 0;
        long long int ans = 0;
        while(n){
            ans += a[i];
            n--;
            i = min(i+k, mini-n+1);
        }
        cout<<ans<<endl;
    }
}