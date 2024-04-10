#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <math.h>
#include <vector>
#include <map>

#define pb push_back
#define lli long long int
#define sc scanf
#define pr printf
#define cl clear
#define vlli vector < long long int >
#define vs vector < string >
#define vf vector < float >
#define vc vector < char >
#define vi vector < int >

using namespace std;

int main()
{
    int a,b[100001],c,i,j,cnt=0,d;
    bool b1=false;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>b[i];
    }
    b[a+1]=9999999;
    for( i=1; i<=a; i++ ){
        if( b[i]>b[i+1] ){
            if( b1==true ){
                cout<<-1;
                return 0;
            }
            cnt=i;
            for( j=i+1; j<=a; j++ ){
                if( b[j]>b[j+1] ){
                    cout<<-1;
                    return 0;
                }
            }
            i=j+1;
        }
    }
    if( b[a]>b[1] && cnt!=0 ){
        cout<<-1;
        return 0;
    }
    if( cnt==0 ){
        cout<<cnt;
        return 0;
    }
    cout<<a-cnt;
    return 0;
}