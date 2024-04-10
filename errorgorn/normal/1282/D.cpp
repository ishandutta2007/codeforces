#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main(){
    string a;
    string b;
    for (int x=0;x<300;x++) a+="a",b+="b";

    int sa,sb;
    cout<<a<<endl;
    cin>>sa;
    cout<<b<<endl;
    cin>>sb;
    
    sa=300-sa;
    sb=300-sb;
    int temp;
    int curr=sb;
    string fin;
    for (int x=0;x<sa+sb;x++) fin+="a";
    for (int x=0;x<sa+sb-1;x++){
        fin[x]='b';
        cout<<fin<<endl;
        cin>>temp;
        if (curr==temp-1) fin[x]='a';
        else curr=temp;
    }
    if (curr) fin[sa+sb-1]='b';
    cout<<fin<<endl;
}