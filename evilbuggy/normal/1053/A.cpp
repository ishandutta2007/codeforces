#include <bits/stdc++.h>

using namespace std;

long long int gcd(long long int a, long long int b){
    if(a == 0)return b;
    return gcd(b%a, a);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int n,m,k;
    cin>>n>>m>>k;
    long long int a = n*m, b = k;
    long long int g = gcd(a, b);
    a /= g;
    b /= g;
    if(b > 2){
        cout<<"NO"<<endl;
    }else if(b == 2){
        cout<<"YES"<<endl;
        cout<<"0 0"<<endl;
        long long int tmp = gcd(n, g);
        cout<<"0 "<<m*tmp/g<<endl;
        cout<<n/tmp<<" 0"<<endl;
    }else if(k == 1){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        cout<<"0 0"<<endl;
        long long int k1 = gcd(n,k);
        long long int k2 = k/k1;
        if(k1 > 1){
            cout<<2*n/k1<<" 0"<<endl;
            cout<<"0 "<<m/k2<<endl;
        }else{
            cout<<n/k1<<" 0"<<endl;
            cout<<"0 "<<2*m/k2<<endl;
        }
    }
}