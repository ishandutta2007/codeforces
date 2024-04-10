#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,cnt=0;
    cin>>a;
    if( a%10==0 ){ cnt+=2; } 
    else if( a%10==1 ){ cnt+=7; } 
    else if( a%10==2 ){ cnt+=2; } 
    else if( a%10==3 ){ cnt+=3; } 
    else if( a%10==4 ){ cnt+=3; } 
    else if( a%10==5 ){ cnt+=4; } 
    else if( a%10==6 ){ cnt+=2; } 
    else if( a%10==7 ){ cnt+=5; } 
    else if( a%10==8 ){ cnt+=1; } 
    else if( a%10==9 ){ cnt+=2; }
    a/=10; 
    if( a%10==0 ){ cnt*=2; } 
    else if( a%10==1 ){ cnt*=7; } 
    else if( a%10==2 ){ cnt*=2; } 
    else if( a%10==3 ){ cnt*=3; } 
    else if( a%10==4 ){ cnt*=3; } 
    else if( a%10==5 ){ cnt*=4; } 
    else if( a%10==6 ){ cnt*=2; } 
    else if( a%10==7 ){ cnt*=5; } 
    else if( a%10==8 ){ cnt*=1; } 
    else if( a%10==9 ){ cnt*=2; }
    cout<<cnt;
    return 0;
    }