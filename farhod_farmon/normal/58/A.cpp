#include <iostream>
using namespace std;
int main ()
{
string s1;
int i,d=0,g;
cin>>s1;
g=s1.size();
 for( i=0; i<g; i++ ){
    if(d==0 && s1[i]=='h'){d=1;}
    else if(d==1 && s1[i]=='e'){d=2;}
    else if(d==2 && s1[i]=='l'){d=3;}
    else if(d==3 && s1[i]=='l'){d=4;}
    else if(d==4 && s1[i]=='o'){d=5;}
 }
(d!=5)?:cout<<"YES";
(d==5)?:cout<<"NO";
 return 0;
}