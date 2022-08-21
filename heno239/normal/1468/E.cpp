#include <iostream>
using namespace std;
using ll = long long;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        ll s = 0;
        s = max(min(a,b)*min(c,d), s);
        s = max(min(a,c)*min(b,d), s);
        s = max(min(a,d)*min(c,b), s);
        cout<<s<<endl;
    }

}