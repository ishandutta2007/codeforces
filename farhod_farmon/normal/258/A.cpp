#include <iostream>
using namespace std;
int main()
{
    string s;
    int i;
    bool b=false;
    cin>>s;
    for( i=0; i<s.size(); i++ ){
        if( i==s.size()-1 && b==false ){
            return 0;
        }
        else if(s[i]=='0'){
            if(b==true){
                cout<<s[i];
            }
            b=true;
        }
        else{
            cout<<s[i];
        }
    }
    return 0;
}