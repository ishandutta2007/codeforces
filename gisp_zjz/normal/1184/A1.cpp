#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll r,x,y;
int main(){
    cin >> r;
    for (x=1;x*x+x+1<r;x++){
        if ((r-x*x-x-1)%(2*x)==0){
            cout << x << ' ' << (r-x*x-x-1)/(2*x) << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}