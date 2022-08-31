#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    if(n+m==0 || abs(n-m)>1) cout << "NO\n";
    else cout << "YES\n";
}