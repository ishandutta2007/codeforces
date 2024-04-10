#include <iostream>
using namespace std;
int main()
{
    int a,x,y,x1,y1,i;
    cin>>a>>x>>y>>x1>>y1;
    char c[a+1];
    for( i=1; i<=a; i++ ){
         cin>>c[i];     
    }
    i=1;
    while( i<=a ){
         if( c[i]=='E' && x<x1 ){
             x++;    
         }    
         else if( c[i]=='S' && y>y1 ){
             y--;     
         }
         else if( c[i]=='W' && x>x1 ){
             x--;     
         }
         else if( c[i]=='N' && y<y1 ){
             y++;      
         }
         if( x==x1 && y==y1 ){
             cout<<i;
             //system ( "pause" );
             return 0;    
         }   
         i++;
    }
    cout<<-1;
    //system ( "pause" );
    return 0;    
}