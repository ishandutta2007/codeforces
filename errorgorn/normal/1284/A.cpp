#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n,m;
string s;
vector<string> a,b;
int q,t;
int main(){
    cin>>n>>m;
    for (int x=0;x<n;x++){
        cin>>s;
        a.push_back(s);
    }
    
    for (int x=0;x<m;x++){
        cin>>s;
        b.push_back(s);
    }
    
    cin>>q;
    while (q--){
        cin>>t;
        t--;
        cout<<a[t%n];
        cout<<b[t%m]<<endl;
    }
}