#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
string a;
int c;
int main(){
    cin>>a;
    while(a.find("WUB")==0)a.replace(a.find("WUB"),3,"");
    c=a.find("WUB");
    while(c!=-1){
        if(a[c-1]!=' ')a.replace(c,3," ");else a.replace(c,3,"");
        c=a.find("WUB");
    }
    cout<<a<<endl;
    return 0;
}