#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#define fo(i,n) for(int (i) = 0 ; i < (n) ; i++)
#define ll long long
#define do double
int main() {
    int n,a,x,b,y;
    cin>>n>>a>>x>>b>>y;
    int l;
    if(x>a)l=x-a;
    else l=n-a+x;
    int a1[l+1];
    if(x>a)for(int i=a;i<=x;i++)a1[i-a]=i;
    else for(int i=a;i<=n+x;i++)a1[i-a]= (i-1)%n +1;
    int l1;
    if(y<b)l1=b-y;
    else l1=n+b-y;
    int b1[l1+1];
    if(y<b)for(int i=b;i>=y;i--)b1[b-i]=i;
    else for(int i=b;i>=-n+y;i--)b1[b-i]= (n+i-1)%n +1;
    //cout<<b1[1]<<b1[2]<<b1[3]<<a1[1]<<a1[2]<<a1[3]<<l<<l1;
    int flag=0;
    for(int i=0;i<=l&&i<=l1 ;i++){
        if(a1[i]==b1[i]){
            flag=1;
        }
    }
    if(flag)
    cout<<"YES";
    else cout<<"NO";


    return 0;
}