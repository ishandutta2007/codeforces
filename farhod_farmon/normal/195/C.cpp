#include <iostream>
using namespace std;
int main()
{
    bool b1=true;
    int a,b[1000001]={},i,j,c[1000001]={},d=0,h,g,joy[1000001]={};
    string s[1000001],type;
    cin>>a;
    for( i=0; i<=a; i++ ){
         getline( cin, s[i] );
    }
    for( i=1; i<=a; i++ ){
         for( j=0; j<s[i].size(); j++ ){
              if( s[i][j]==' ' ){
                  continue;    
              }     
              else if( s[i][j]=='t' && s[i][j+1]=='r' ){
                   d++;     
                   b[d]=i;
                   break;
              }
              else if( s[i][j]=='t' && s[i][j+1]=='h' ){
                   g=i;
                   for( h=j+5; h<s[i].size(); h++ ){
                        if( s[i][h]==' ' || s[i][h]=='(' ){
                            continue;    
                        }     
                        if( s[i][h]==')' ){
                            break;    
                        }
                        type+=s[i][h];
                   }
                   break;     
              }
              else{
                   c[b[d]]=i;
                   d--;
                   break;
              }
         }
    }
    for( i=1; i<=a; i++ ){
         if( c[i]!=0 ){
             joy[c[i]]=i;    
         }     
    } 
    int k,k1;
    for( i=g+1; i<=a; i++ ){
         b1=true;
         if( joy[i]<g ){
             for( j=0; j<s[i].size(); j++ ){
                  if( s[i][j]==' ' ){
                      continue;    
                  }     
                  if( s[i][j]=='(' ){
                      for( h=j+1; h<s[i].size(); h++ ){
                           if( s[i][h]==' ' ){
                               continue;    
                           }     
                           else{
                                k=h,k1=0;
                                while( s[i][k]!=' ' && s[i][k]!=',' ){
                                       if( s[i][k]!=type[k1] ){
                                           b1=false;
                                           break;    
                                       }
                                       k++;
                                       k1++;
                                }
                                if( k1!=type.size() ){
                                    b1=false;    
                                }
                                break;
                           }
                      }    
                      for( h==k; h<s[i].size(); h++ ){
                           if( s[i][h]==',' ){
                               j=h+1;
                               break;    
                           }     
                      }
                  }
                  if( b1==false ){
                      break;    
                  }
                  else if( s[i][j]=='"' ){
                       for( h=j+1; h<s[i].size(); h++ ){
                            if( s[i][h]=='"' ){
                                break;    
                            }     
                            cout<<s[i][h];
                       }
                       //system ( "pause" );
                       return 0;
                  }
             }   
         }
    }
    cout<<"Unhandled Exception";
    //system ( "pause" );
    return 0;    
}