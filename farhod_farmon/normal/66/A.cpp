#include <iostream>
using namespace std;
int main()
{
    string s,t[5]={ "", "127", "32767", "2147483647", "9223372036854775807" },ans[6]={ "", "byte", "short", "int", "long", "BigInteger" };
    int a,b=1,c=0,d=0,i,j,k;
    cin>>s;
    while( c==0 && b<5 ){
           d=0;
           for( i=0; i<t[b].size(); i++ ){
                if( t[b][i]>s[i] && d==0 ){
                    c=1;
                    break;    
                }     
                else if( s[i]>t[b][i] )d++;
           }     
           if( d==0 && s.size()==t[b].size() )c=1;
           if( t[b].size()>s.size() )c=1;
           if( t[b].size()<s.size() )c=0;
           if( c==0 )b++;
    }
    cout<<ans[b];
    return 0;
}