#include<bits/stdc++.h>
using namespace std;
int _,n,m;

int main(){
    cin >> _;
    while (_--){
        cin >> n >> m;
        if (n%m) puts("NO");
        else puts("YES");
    }
}