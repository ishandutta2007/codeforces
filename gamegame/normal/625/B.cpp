#include<string>
#include<iostream>
using namespace std;
int main(){
    string m,n,s;
    cin >> m >> n;
    s=m;
    int p=0,q=0;
    p=m.find(n);
    while(p>=0){
        m.erase(0,p+1);
        q=q+1;
        p=m.find(n);
    }
    p=0,q=0;
    m=s;
    p=m.find(n);
    while(p>=0){
        m.erase(0,p+n.size());
        q=q+1;
        p=m.find(n);
    }
    cout << q << endl;
}