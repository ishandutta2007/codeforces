#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,i;
    string s,t[11];
    cin>>n;
    for( i=0; i<=n; i++ ){
         getline( cin, t[i] );   
    }
    for( i=1; i<=n; i++ ){
         int a=t[i].size()-1;
         s=t[i];
         if( s[0]=='m' && s[1]=='i' && s[2]=='a' && s[3]=='o' && s[4]=='.' && s[a]=='.' && s[a-1]=='a' && s[a-2]=='l' && s[a-3]=='a' && s[a-4]=='l' ){
              cout<<"OMG>.< I don't know!\n";    
         }     
         else if( s[0]=='m' && s[1]=='i' && s[2]=='a' && s[3]=='o' && s[4]=='.' ){
              cout<<"Rainbow's\n";     
         }
         else if( s[a]=='.' && s[a-1]=='a' && s[a-2]=='l' && s[a-3]=='a' && s[a-4]=='l' ){
              cout<<"Freda's\n";     
         }
         else{
              cout<<"OMG>.< I don't know!\n";  
         }
    }
    //system( "pause" );
    return 0;    
}