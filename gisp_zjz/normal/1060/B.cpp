#include<bits/stdc++.h>
#define maxn 234560

using namespace std;
typedef long long ll;
ll n,s,r,p;

int main(){
    cin >> n;
    while (n%10==9) p+=n%10,n/=10;
    while (n>=10) p+=n%10,s+=9,n/=10;
    p+=n; r=(p==1)?10:p;
    cout << p+s << endl;
}