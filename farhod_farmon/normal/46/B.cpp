#include <iostream>
#include <map>
using namespace std;
int main()
{
    int a,b[8],c[1001],d,i,j;
    map < string, int > m;
    string s[1001],ans[6]={"", "S", "M", "L", "XL", "XXL" };
    m["S"]=1;
    m["M"]=2;
    m["L"]=3;
    m["XL"]=4;
    m["XXL"]=5;
    b[0]=0;
    cin>>b[1]>>b[2]>>b[3]>>b[4]>>b[5];
    cin>>a;
    for( i=1; i<=a; i++ ){
         cin>>s[i];
         c[i]=m[s[i]];     
    }
    for( i=1; i<=a; i++ ){
         if( b[c[i]]>0 ){
              cout<<s[i]<<endl;
              b[c[i]]--;    
         }      
         else{
              j=c[i]-1;
              while( j>=1 && b[j]==0 )j--;
              d=j;
              j=c[i]+1;
              while( j<=5 && b[j]==0 )j++;
              if( c[i]-d<j-c[i] && d>0 || j>5 ){
                   cout<<ans[d]<<endl;
                   b[d]--;    
              }
              else{
                   cout<<ans[j]<<endl;
                   b[j]--;     
              }
         }
    }
    //system ( "pause" );
    return 0;
}