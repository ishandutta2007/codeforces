#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int t,n,r,p;
    cin >> t;
    for(int i=1; i<=t ;i++){
        cin >> n >> r;
        int sum=0;
        for(int i=1; i<n ;i++){
            cin >> p;sum+=p;
        }
        sum=(n*n+r-sum-1)%n+1;
        cout << sum << endl;
    }
}