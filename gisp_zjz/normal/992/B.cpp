#include<bits/stdc++.h>

using namespace std;
int a,b,x,y,p,q;

int gcd(int x,int y){
    if (x%y==0) return y; else return gcd(y,x%y);
}

int main(){
    cin >> a >> b >> x >> y;
    int ans=0;
    if (y%x){
        cout << 0 << endl;
        return 0;
    }
    y/=x;
    for (int i=1;i*i<=y;i++) if (y%i==0){
        p=i; q=y/i;
        if (gcd(p,q)>1) continue;
        if (p*x>=a&&q*x<=b) {
            ans++;
            if (p!=q) ans++;
        }
    }
    cout << ans << endl;
}