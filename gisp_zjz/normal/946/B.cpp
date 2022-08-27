#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c;

int main()
{
    scanf("%lld%lld",&a,&b);
    while (true){
        if (a==0||b==0) {printf("%lld %lld\n",a,b);return 0;}
        else if (a>=b*2) a%=(b*2);
        else if (b>=a*2) b%=(a*2);
        else {printf("%lld %lld\n",a,b);return 0;}
    }
}