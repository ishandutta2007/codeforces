#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector <int> v2,v1;
    long long int a,b[200001],i,maxn2=0,maxn1=0;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>b[i];
        if( b[i]>0 ){
            maxn1+=b[i];
            v1.push_back(b[i]);
        }
        else if( b[i]<0 ){
            maxn2+=(-b[i]);
            v2.push_back(-b[i]);
        }
    }
    if( maxn1>maxn2 ){
        cout<<"first";
        return 0;
    }
    else if( maxn2>maxn1 ){
        cout<<"second";
        return 0;
    }
    for( i=0; i<max( v2.size(), v1.size() ); i++ ){
        if( v1[i]>v2[i] ){
            cout<<"first";
            return 0;
        }
        else if( v2[i]>v1[i] ){
            cout<<"second";
            return 0;
        }
    }
    if( b[a]>0 ){
        cout<<"first";
    }
    else{
        cout<<"second";
    }
    return 0;
}