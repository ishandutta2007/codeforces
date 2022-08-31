#include<iostream>
using namespace std;
int n,m,k;
int a[200001],b[200001];
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> k;
    int have=0,gave=0;
    for(int i=1; i<=n ;i++){
        cin >> a[i];
        have+=a[i];
        if(have<8) gave+=have;
        else gave+=8;
        have=max(have-8,0);
        if(gave>=k){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}