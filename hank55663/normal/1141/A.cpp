#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int gcd=__gcd(n,m);
    n/=gcd;
    m/=gcd;
    int cnt=0;
    while(m%2==0)m/=2,cnt++;
    while(m%3==0)m/=3,cnt++;
    if(n==1&&m==1){
        printf("%d\n",cnt);
    }
    else{
        printf("-1\n");
    }
}