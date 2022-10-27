#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair

int main(){
    int n, m;
    cin>>n>>m;
    string a[n];
    int sum[m] = {0};
    for(int i = 0; i < n; i++){
        cin>>a[i];
        for(int j = 0; j < m; j++){
            sum[j] += a[i][j] - '0';
        }
    }
    for(int i = 0; i < n; i++){
        bool tmp = true;
        for(int j = 0; j < m; j++){
            if(sum[j] == 1 && a[i][j] == '1'){
                tmp = false;
            }
        }
        if(tmp){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}