#include<bits/stdc++.h>

using namespace std;

int n,m;
string a[505];

bool placeDog(int i, int j){
    if(i < 0 || j < 0){
       return true;
    }
    if(i >= n || j >= m){
        return true;
    }
    if(a[i][j] == 'W'){
        return false;
    }else if(a[i][j] == '.'){
        a[i][j] = 'D';
    }
    return true;
}

int main(){
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    bool ans = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'S'){
                ans &= placeDog(i-1, j);
                ans &= placeDog(i+1, j);
                ans &= placeDog(i, j-1);
                ans &= placeDog(i, j+1);
            }
        }
    }
    if(!ans){
        cout<<"No";
    }else{
        cout<<"Yes"<<endl;
        for(int i = 0; i < n; i++){
            cout<<a[i]<<endl;
        }
    }
}