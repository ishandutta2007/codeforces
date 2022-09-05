#include<iostream>
#include<cstdlib>
using namespace std;
float a,b,c,d,e,f;
int main()
{
    cin>>a>>b>>c>>d>>e>>f;
    if(a>0&&c>0&&e>0){if(b/a*d/c*f/e>1)cout<<"Ron"; else cout<<"Hermione";}
    else if(c==0&&d>0||a==0&&b>0&&c>0&&d>0||e==0&&f>0&&a>0&&b>0&&c>0&&d>0)cout<<"Ron";
    else if(b==0||d==0||f==0)cout<<"Hermione";
    return 0;
}