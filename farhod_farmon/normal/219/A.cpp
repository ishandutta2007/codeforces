#include <iostream>
#include <map>
using namespace std;
int main()
{
    string s;
    map<char,int>m;
    char c[1001];
    int a,i,d=0,g,j,h;
    cin>>a>>s;
    g=s.size();
    for( i=0; i<g; i++ ){
        m[s[i]]++;
        if(m[s[i]]==1){
            c[d]=s[i];
            d++;
        }
    }
    for( i=0; i<d; i++ ){
        if(m[c[i]]%a!=0){
            cout<<-1;
            return 0;
        }
    }
    for( i=0; i<a; i++ ){
        for( j=0; j<d; j++ ){
            for( h=0; h<m[c[j]]/a; h++ ){
                cout<<c[j];
            }
        }
    }
    return 0;
}