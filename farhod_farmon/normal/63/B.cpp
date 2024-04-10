#include <iostream>
using namespace std;
int main()
{
    int a,b[101]={},i,j,k,cnt=0;
    cin>>a>>k;
    for( i=1; i<=a; i++ ){
         cin>>b[0];
         b[b[0]]++;     
    }
    while( b[k]<a ){
           j=1;
           b[0]=0;
           while( j<k ){
                  if( b[j]>0 && b[0]==0 ){
                      b[j]--;
                      b[j+1]++;    
                      b[0]=1;
                  }
                  else if( b[j]>1 && b[0]==1 ){
                      b[j]--;
                      b[j+1]++;         
                  }
                  j++;       
           }       
           cnt++;
    }
    cout<<cnt;
    return 0;
}