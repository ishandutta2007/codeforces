#include <bits/stdc++.h>
#define N 105
#define INF 5000000
using namespace std;
typedef long long ll;
int n;
ll p,q,b,bf,gcd;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    while(n-->0){
        cin>>p>>q>>b;
        q/=__gcd(p,q);
        bf=q;
        while(1){
            gcd=__gcd(q,b);
            while(q%gcd==0&&gcd!=1&&q)
                q/=gcd;
            if(q==bf)
                break;
            bf=q;
        }
        if(bf==1)
            cout<<"Finite\n";
        else
            cout<<"Infinite\n";
    }
    return 0;
}