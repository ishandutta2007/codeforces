#include <iostream>
using namespace std;
int main()
{
    string s;
    int i,a;
    getline( cin, s );
    a=s.size();
    for( i=a-1; i>=0; i-- ){
        if( s[i]==' ' || s[i]=='?' ){
            continue;
        }
        s[i]=toupper(s[i]);
        if( s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='Y' ){
            cout<<"YES";
            return 0;
        }
        else{
            cout<<"NO";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}