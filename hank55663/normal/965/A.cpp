#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
int main(){
    LL k,n,s,p;
    scanf("%lld %lld %lld %lld",&k,&n,&s,&p);
    n=(n+s-1)/s;
    k*=n;
    printf("%lld\n",(p+k-1)/p);
}