#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int main() {
    int n,m,r;
    cin >>n>>m>>r;
    int a[n],b[m];
    for(int i=0;i<n;i++){
        cin >>a[i];
    }
    for(int i=0;i<m;i++){
        cin >>b[i];
    }
    sort(a,a+n);
    sort(b,b+m);
    if(a[0]>=b[m-1]){
        cout<< r;
    }
    else{
        int x= r/a[0];
        cout<< r+ x*(b[m-1]-a[0]);
    }
	return 0;
}