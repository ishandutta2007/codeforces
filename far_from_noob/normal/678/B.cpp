#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define dd double
#define endl "\n"
#define fo(i,n) for(int i=0;i<n;i++)
ll n,k,t,m,q,flag=0;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //cin>>t;
    t=1;
    while(t--){
            cin>>n;
            ll count=0;
            ll flag=0,flag1=0;
            if(n%400==0 || (n%4==0 && n%100!=0))flag1=1;
            //cout<<flag1;
            while(1){
                if(n%400==0 || (n%4==0 && n%100!=0) )count+=2;
                else count++;
                n++;
                if(n%400==0 || (n%4==0 && n%100!=0))flag=1;
                else flag=0;
                if(count%7==0 && flag==flag1)break;

            }
            cout<<n;


    }

    return 0;
}