#include<iostream>
using namespace std;
int main(){
    long long int n,k,ans=0,m;
    cin >> n >> k;
    m=n*2-3;
    for(int i=0; i<k ;i++){
        ans+=max(0LL,m);
        m-=4;
    }
    cout << ans << endl;
}