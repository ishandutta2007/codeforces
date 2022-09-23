#include <bits/stdc++.h>
using namespace std;
int main()
{
    bool b1=false;
    string s,t;
    int a,cnt=0,i,d[10];
    cin>>s>>t;
    if( s.size() != t.size() ){
        cout<<"NO";
        return 0;
    }
    a=s.size();
    for( i=0; i<a; i++ ){
        if( s[i]!=t[i] ){
            cnt++;
            d[cnt]=i;
        }
        if( cnt==2 && b1==false ){
            b1=true;
            swap( s[d[1]], s[d[2]] );
        }
        else if( cnt>2 ){
            cout<<"NO";
            return 0;
        }
    }
    if( s==t ){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}