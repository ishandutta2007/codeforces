#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    int pab = 0;
    int kiek[n+1]={};
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        for(int j = a;j<=b;j++){
            kiek[j]++;
        }
    }
    for(int i = 1;i<=n;i++){
        if(kiek[i]!=1){
            cout << i << " " << kiek[i] << endl;
            return 0;
        }
    }
    cout << "OK";
}