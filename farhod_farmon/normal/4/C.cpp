#include <iostream>
#include <map>
using namespace std;
int main()
{
    int a,i;
    string s[100001];
    map<string,int>m;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>s[i];
    }
    for( i=1; i<=a; i++ ){
        if(m[s[i]]==0){
            cout<<"OK"<<endl;
        }
        else{
            cout<<s[i]<<m[s[i]]<<endl;
        }
        m[s[i]]++;
    }
    return 0;
}