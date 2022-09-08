#include<bits/stdc++.h>
using namespace std;
int l,r,mid,n;
int work(int x){
    return (x+1)/2-1 + max(0,x/4-1);
    /*
    int ret=0;
    while (x){
        ret+=(x+1)/2-1;
        x/=4;
    }
    return ret;
    */
}
int main(){
    cin >> n;
    l=0; r=2e9;
    while (r-l>1){
        mid=l+(r-l)/2;
        if (work(mid)<n) l=mid; else r=mid;
    }
    cout << r << endl;
}