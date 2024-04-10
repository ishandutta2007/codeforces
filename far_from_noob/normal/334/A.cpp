#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n/2;j++){
            cout<< (i-1)*n/2 + j <<" "<<n*n+1-(i-1)*n/2 - j<<" ";
        }
        cout<<endl;
    }
    
    
	return 0;
}