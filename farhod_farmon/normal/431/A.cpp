#include <iostream>
using namespace std;
int main ()
{
    int b1,b2,b3,b4,c1=0,i;
    string a;
    cin>>b1>>b2>>b3>>b4>>a;
    for(i=0; i<a.size(); i++)
    {
        if(a[i]=='1'){c1=c1+b1;}
        else if(a[i]=='2'){c1=c1+b2;}
         else if(a[i]=='3'){c1=c1+b3;}
          else if(a[i]=='4'){c1=c1+b4;}
        }
        cout<<c1<<endl;
        
    return 0;
    }