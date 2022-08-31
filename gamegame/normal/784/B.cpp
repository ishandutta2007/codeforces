#include<iostream>
using namespace std;
int a[16]={1,0,0,0,1,0,1,0,2,1,1,2,0,1,0,0};
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int ans=(n==0);
    while(n!=0){
        ans=ans+a[n%16];
        n/=16;
    }
    cout << ans << endl;
}