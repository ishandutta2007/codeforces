#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long
int main() {
    int n,h,m;
    cin >>n>>h>>m;
    int height[n+1],l[m+1],r[m+1],x[m+1];
    for(int i=1;i<n+1;i++){
        height[i]=h;
    }
    for(int i=1;i<m+1;i++){
        cin >> l[i]>>r[i]>>x[i];
        for(int j=l[i];j<=r[i];j++){
            if(height[j] >= x[i])
                height[j]=x[i];
        }
    }
    int countsum=0;
    for(int i=1;i<n+1;i++){
        countsum+=height[i]*height[i];
    }

    cout<<countsum;

    return 0;
}