#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int main() {
    int n,m,k;
    cin >> n>>m>>k;
    int x[m+1];
    int binary[m+1][n];
    for(int i=0;i<m+1;i++){
        cin>> x[i];
        for(int j=n-1;j>=0;j--){
            binary[i][j]=x[i]/(int) pow(2,j);
            x[i]=x[i]- binary[i][j]*(int) pow(2,j);
        }
    }
    int friends=0;
    for(int i=0;i<m;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(binary[i][j]!=binary[m][j])
            count++;
        }
        if (count <=k){
            
            friends++;
        }
    }
    cout<< friends;
	return 0;
}