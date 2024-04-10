#include <iostream>

using namespace std;

int main ()
{
    int a,b,d,c;
    c = 0;
    b = 1;
    d = 1;
    cin >>a;
    if ( a == 1 ){
        cout <<1;
        return 0;
    }

    for ( ; a>=b; b=b+d){
        d++;
        a=a-b;
        c++;

    }
    cout <<c;
}