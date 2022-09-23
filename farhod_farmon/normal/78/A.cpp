#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2,s3;
    int i,a,cnt=0;
    getline( cin, s1 );
    getline( cin, s2 );
    getline( cin, s3 );
    a=s1.size();
    for( i=0; i<a; i++ ){
        if( s1[i]=='a' || s1[i]=='e' || s1[i]=='i' || s1[i]=='u' || s1[i]=='o' ){
            cnt++;
        }
    }
    if( cnt!=5 ){
        cout<<"NO";
        return 0;
    }
    cnt=0;
    a=s2.size();
    for( i=0; i<a; i++ ){
        if( s2[i]=='a' || s2[i]=='e' || s2[i]=='i' || s2[i]=='u' || s2[i]=='o' ){
            cnt++;
        }
    }
    if( cnt!=7 ){
        cout<<"NO";
        return 0;
    }
    cnt=0;
    a=s3.size();
    for( i=0; i<a; i++ ){
        if( s3[i]=='a' || s3[i]=='e' || s3[i]=='i' || s3[i]=='u' || s3[i]=='o' ){
            cnt++;
        }
    }
    if( cnt!=5 ){
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
    return 0;
}