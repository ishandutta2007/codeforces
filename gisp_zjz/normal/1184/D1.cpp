#include<bits/stdc++.h>
using namespace std;
int n,m,k,t;
int main(){
    cin >> n >> k >> m >> t;
    for (int i=0;i<t;i++){
        int o,p;
        cin >> o >> p;
        if (o==1){
            if (p<=k) ++k;
            ++n;
        } else {
            if (p>=k) n=p;
            else k-=p,n-=p;
        }
        cout << n << ' ' << k << endl;
    }
}