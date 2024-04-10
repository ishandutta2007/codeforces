#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int main(void) {
    int n;
    cin >>n;
    int a[n] ,b[n-1],c[n-2];
    for(int i=0;i<n;i++){
        cin >>a[i];
    }
    for(int i=0;i<n-1;i++){
        cin >>b[i];
    }
    for(int i=0;i<n-2;i++){
        cin >>c[i];
    }
    sort(a,a+n);
    sort(b,b+n-1);
    sort(c,c+n-2);
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            cout<< a[i]<<endl;
            break;
        }
        if(i==n-1)cout<< a[i]<<endl;
    }
    for(int i=0;i<n-1;i++){
        if(c[i]!=b[i]){
            cout<< b[i]<<endl;
            break;
        }
        if(i==n-2)cout<< b[i]<<endl;
    }
	// your code goes here
	return 0;
}