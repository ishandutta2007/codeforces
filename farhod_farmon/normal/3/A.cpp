#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s,s1,c[100];
    int a[3],b[3],i,j,d,g=1;
    cin>>s>>s1;
    if( s[0]=='a' ){
        a[1]=1;
    }
    else if( s[0]=='b' ){
        a[1]=2;
    }
    else if( s[0]=='c' ){
        a[1]=3;
    }
    else if( s[0]=='d' ){
        a[1]=4;
    }
    else if( s[0]=='e' ){
        a[1]=5;
    }
    else if( s[0]=='f' ){
        a[1]=6;
    }
    else if( s[0]=='g' ){
        a[1]=7;
    }
    else if( s[0]=='h' ){
        a[1]=8;
    }


    if( s1[0]=='a' ){
        b[1]=1;
    }
    else if( s1[0]=='b' ){
        b[1]=2;
    }
    else if( s1[0]=='c' ){
        b[1]=3;
    }
    else if( s1[0]=='d' ){
        b[1]=4;
    }
    else if( s1[0]=='e' ){
        b[1]=5;
    }
    else if( s1[0]=='f' ){
        b[1]=6;
    }
    else if( s1[0]=='g' ){
        b[1]=7;
    }
    else if( s1[0]=='h' ){
        b[1]=8;
    }

    if( s[1]=='1' ){
        a[2]=1;
    }
    else if( s[1]=='2' ){
        a[2]=2;
    }
    else if( s[1]=='3' ){
        a[2]=3;
    }
    else if( s[1]=='4' ){
        a[2]=4;
    }
    else if( s[1]=='5' ){
        a[2]=5;
    }
    else if( s[1]=='6' ){
        a[2]=6;
    }
    else if( s[1]=='7' ){
        a[2]=7;
    }
    else if( s[1]=='8' ){
        a[2]=8;
    }


    if( s1[1]=='1' ){
        b[2]=1;
    }
    else if( s1[1]=='2' ){
        b[2]=2;
    }
    else if( s1[1]=='3' ){
        b[2]=3;
    }
    else if( s1[1]=='4' ){
        b[2]=4;
    }
    else if( s1[1]=='5' ){
        b[2]=5;
    }
    else if( s1[1]=='6' ){
        b[2]=6;
    }
    else if( s1[1]=='7' ){
        b[2]=7;
    }
    else if( s1[1]=='8' ){
        b[2]=8;
    }


    while( a[1]!=b[1] || a[2]!=b[2] ){
        if( a[1]>b[1] && a[2]>b[2] ){
            a[1]--;
            a[2]--;
            c[g]="LD";
            g++;
            }
         if( a[1]<b[1] && a[2]>b[2] ){
            a[2]--;
            a[1]++;
            c[g]="RD";
            g++;
        }
         if( a[1]>b[1] && a[2]<b[2] ){
            c[g]="LU";
            g++;
            a[1]--;
            a[2]++;
        }
         if( a[1]<b[1] && a[2]<b[2] ){
            c[g]="RU";
            g++;
            a[1]++;
            a[2]++;
        }
         if( a[1]==b[1] && a[2]>b[2] ){
            c[g]="D";
            g++;
            a[2]--;
        }
         if( a[1]==b[1] && a[2]<b[2] ){
            a[2]++;
            c[g]="U";
            g++;
        }
         if( a[1]>b[1] && a[2]==b[2] ){
            a[1]--;
            c[g]="L";
            g++;
        }
         if( a[1]<b[1] && a[2]==b[2] ){
            a[1]++;
            c[g]="R";
            g++;
        }
    }
    cout<<g-1<<endl;
    for( i=1; i<g; i++ ){
        cout<<c[i]<<endl;
    }
    return 0;
}