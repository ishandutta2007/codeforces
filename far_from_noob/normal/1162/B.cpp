#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long
int main() {
    int n,m;
    cin >>n>>m;
    int a[n][m],b[n][m],c[n][m],d[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> b[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(b[i][j] > a[i] [j] ){c[i][j]=b[i][j]; d[i][j]= a[i][j];}
            else {d[i][j]=b[i][j]; c[i][j]= a[i][j];}
        }
    }
    int flag=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++){
            if(d[i][j+1]<= d[i][j]){
                flag=1;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++){
            if(c[i][j+1]<= c[i][j]){
                flag=1;
                break;
            }
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            if(d[i+1][j]<= d[i][j]){
                flag=1;
                break;
            }
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            if(c[i+1][j]<= c[i][j]){
                flag=1;
                break;
            }
        }
    }
    if(flag==1) cout<<"Impossible";
    else cout<< "Possible";
    return 0;
}