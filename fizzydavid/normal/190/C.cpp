#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
string s,res;
int t;
void F()
{
     if(cin>>s)
     {
         res+=s;
         if(s=="pair")res+="<",F(),res+=",",F(),res+=">";
     }
     else t=1;
}

int main()
{
    cin>>s;F();
    if(t==1||cin>>s)cout<<"Error occurred";else cout<<res;
    return 0;
}