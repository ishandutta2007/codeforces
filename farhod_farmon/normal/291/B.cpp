#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector < string > v;
    string s,t;
    int a,i,j;
    getline( cin, s );
    a=s.size();
    for( i=0; i<a; i++ ){
        if( s[i]=='"' ){
            t="<";
            for( j=i+1; j<a; j++ ){
                if( s[j]=='"' ){
                    break;
                }
                t+=s[j];
            }
            i=j;
            t+=">";
            v.push_back( t );
        }
        else if( s[i]!=' ' ){
            t="<";
            for( j=i; j<a; j++ ){
                if( s[j]==' ' ){
                    break;
                }
                t+=s[j];
            }
            i=j;
            t+=">";
            v.push_back( t );
        }
    }
    for( i=0; i<v.size(); i++ ){
        cout<<v[i]<<endl;
    }
    return 0;
}