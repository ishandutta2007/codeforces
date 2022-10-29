#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>a,b,c;
int n;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        if(k==0) c.push_back(k);
        else if(k>0) a.push_back(k);
        else b.push_back(k);
    }
    printf("1 %d\n",b.back());
    b.pop_back();
    if(b.size()&1){
        c.push_back(b.back());
        b.pop_back();
    }
    cout<<b.size()+a.size()<<" ";
    for(int i=0;i<b.size();i++)
        cout<<b[i]<<" ";
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<" ";
    cout<<endl;
    cout<<c.size()<<" ";
    for(int i=0;i<c.size();i++)
        cout<<c[i]<<" ";
    return 0;
}