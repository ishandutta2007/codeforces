#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <map>
#include <vector>

#define pb push_back
#define lli long long int
#define sc scanf
#define pr printf
#define cl clear
#define fi first
#define se second
#define vlli vector < long long int >
#define vs vector < string >
#define vf vector < float >
#define vc vector < char >
#define vi vector < int >

using namespace std;
int main()
{
    float a[5],b[5],c[5],d[5],minn=99999,maxn=0,f;
    int n,i,j;
    cin>>n;
    for( i=1; i<=n; i++ ){
        cin>>a[i];
        b[i]=a[i];
        c[i]=a[i];
        d[i]=a[i];
        maxn=max( maxn, a[i] );
        minn=min( minn, a[i] );
    }
    if( n==0 ){
        cout<<"YES\n1\n1\n3\n3";
        return 0;
    }
    if( n==1 ){
        cout<<"YES\n";
        cout<<a[1]<<endl<<a[1]*3<<endl<<a[1]*3;
        return 0;
    }
    if( n==2 ){
        sort( a+1, a+n+1 );
        a[3]=a[1]*4-a[2];
        a[4]=a[1]*3;
        if( (a[1]+a[2]+a[3]+a[4])/4==(a[2]+a[3])/2 && (a[2]+a[3])/2==a[4]-a[1] && a[1]>0 && a[2]>0 && a[3]>0 && a[4]>0 ){
            cout<<"YES\n";
            cout<<a[3]<<endl<<a[4];
        }
        else{
            cout<<"NO";
        }
        return 0;
    }
    if( n==3 ){
        sort( a+1, a+n+1 );
        f=a[2];
        a[4]=a[1]*3;
        if( (a[1]+a[2]+a[3]+a[4])/4==(a[2]+a[3])/2 && (a[2]+a[3])/2==a[4]-a[1] && a[1]>0 && a[2]>0 && a[3]>0 && a[4]>0 ){
            cout<<"YES\n";
            cout<<a[4];
            return 0;
        }
        b[4]=maxn/3;
        c[4]=minn*4-f;
        c[0]=c[4];
        b[0]=b[4];
        sort( b+1, b+n+2 );
        sort( c+1, c+n+2 );
        if( (b[1]+b[2]+b[3]+b[4])/4==(b[2]+b[3])/2 && (b[2]+b[3])/2==b[4]-b[1] && b[4]>0 ){
            cout<<"YES\n";
            cout<<b[0];
            return 0;
        }
        if( (c[1]+c[2]+c[3]+c[4])/4==(c[2]+c[3])/2 && (c[2]+c[3])/2==c[4]-c[1] && c[4]>0 ){
            cout<<"YES\n";
            cout<<c[0];
            return 0;
        }
        else{
            cout<<"NO";
        }
        return 0;
    }
    if( n==4 ){
        sort( a+1, a+n+1 );
        if( (a[1]+a[2]+a[3]+a[4])/4==(a[2]+a[3])/2 && (a[2]+a[3])/2==a[4]-a[1] ){
            cout<<"YES\n";
        }
        else{
            cout<<"NO";
        }
        return 0;
    }
    return 0;
}