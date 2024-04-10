#include<bits/stdc++.h>
using namespace std;
int n,a[99];
int main(){
    clock_t t=clock();
    while((clock()-t)<=1.5*CLOCKS_PER_SEC);
    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;++i)cout<<a[i]<<" ";
}