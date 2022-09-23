#include <iostream>
using namespace std;
int main()
{
    int a,b[100001],i,j;
    cin>>a;
    for( i=1; i<=a; i++ )cin>>b[i];
    i=1;
    j=a;
    while( i<j-1 ){
           if( b[i]<=b[j] ){
                b[i+1]+=b[i];
                i++;    
           }  
           else{
                b[j-1]+=b[j];
                j--;     
           }
    }
    cout<<i<<" "<<a-i;
    return 0;
}