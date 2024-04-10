#include<iostream>
using namespace std;
string a[101];
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1; i<=n ;i++){
        cin >> a[i];
        bool ok=false;
        for(int j=1; j<i ;j++){
            if(a[j]==a[i]) ok=true;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}