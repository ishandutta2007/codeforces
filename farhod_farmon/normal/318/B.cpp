#include <bits/stdc++.h>
using namespace std;
int main()
{

    char s[1000001];
    long long int i,j,g=0,d[100001],cnt=0,a;
    cin>>s;
    a=strlen(s);
    for( i=0; i<a; i++ ){
        if( s[i]=='h' && s[i+1]=='e' && s[i+2]=='a' && s[i+3]=='v' && s[i+4]=='y' ){
            g++;
        }
        if( s[i]=='m' && s[i+1]=='e' && s[i+2]=='t' && s[i+3]=='a' && s[i+4]=='l' ){
            for( j=1; j<=g; j++ ){
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
//    heavy