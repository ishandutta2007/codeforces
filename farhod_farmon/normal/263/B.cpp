#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a,c,b[101],i,x=-1;
    cin>>a>>c;
    for( i=1; i<=a; i++ ){
        cin>>b[i];
    }
    sort( b+1,b+a+1 );
    for( i=a; i>=1; i-- ){
        c--;
        if(c==0){
            x=b[i];
            break;
        }
    }
    if(x>0){
        cout<<x<<" "<<x;
    }
    else{
        cout<<x;
    }
    return 0;
}