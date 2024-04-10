#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;
int main()
{
    string s,s1;
    int a=0,b=0,a1=0,b1=0,i;
    cin>>s>>s1;
    for( i=0; i<3; i++ ){
        if(s[i]=='0'){a=a*10+0;}
        else if(s[i]=='1'){a=a*10+1;}
        else if(s[i]=='2'){a=a*10+2;}
        else if(s[i]=='3'){a=a*10+3;}
        else if(s[i]=='4'){a=a*10+4;}
        else if(s[i]=='5'){a=a*10+5;}
        else if(s[i]=='6'){a=a*10+6;}
        else if(s[i]=='7'){a=a*10+7;}
        else if(s[i]=='8'){a=a*10+8;}
        else if(s[i]=='9'){a=a*10+9;}
        if(s1[i]=='0'){b=b*10+0;}
        else if(s1[i]=='1'){b=b*10+1;}
        else if(s1[i]=='2'){b=b*10+2;}
        else if(s1[i]=='3'){b=b*10+3;}
        else if(s1[i]=='4'){b=b*10+4;}
        else if(s1[i]=='5'){b=b*10+5;}
        else if(s1[i]=='6'){b=b*10+6;}
        else if(s1[i]=='7'){b=b*10+7;}
        else if(s1[i]=='8'){b=b*10+8;}
        else if(s1[i]=='9'){b=b*10+9;}
    }
    for( i=3; i<5; i++ ){
        if(s[i]=='0'){a1=a1*10+0;}
        else if(s[i]=='1'){a1=a1*10+1;}
        else if(s[i]=='2'){a1=a1*10+2;}
        else if(s[i]=='3'){a1=a1*10+3;}
        else if(s[i]=='4'){a1=a1*10+4;}
        else if(s[i]=='5'){a1=a1*10+5;}
        else if(s[i]=='6'){a1=a1*10+6;}
        else if(s[i]=='7'){a1=a1*10+7;}
        else if(s[i]=='8'){a1=a1*10+8;}
        else if(s[i]=='9'){a1=a1*10+9;}
        if(s1[i]=='0'){b1=b1*10+0;}
        else if(s1[i]=='1'){b1=b1*10+1;}
        else if(s1[i]=='2'){b1=b1*10+2;}
        else if(s1[i]=='3'){b1=b1*10+3;}
        else if(s1[i]=='4'){b1=b1*10+4;}
        else if(s1[i]=='5'){b1=b1*10+5;}
        else if(s1[i]=='6'){b1=b1*10+6;}
        else if(s1[i]=='7'){b1=b1*10+7;}
        else if(s1[i]=='8'){b1=b1*10+8;}
        else if(s1[i]=='9'){b1=b1*10+9;}
    }


    a=(a*60)+a1;
    b=(b*60)+b1;

    a=a-b;

    if(a<0){
        if((1440-abs(a))/60<=9){
            cout<<"0"<<(1440-abs(a))/60<<":";
            if((1440-abs(a))%60<=9){
                cout<<"0"<<(1440-abs(a))%60;
            }
            else{
                cout<<(1440-abs(a))%60;
            }
        }
        else{
            cout<<(1440-abs(a))/60<<":";
            if((1440-abs(a))%60<=9){
                cout<<"0"<<(1440-abs(a))%60;
            }
            else{
                cout<<(1440-abs(a))%60;
            }
        }
    }

    else{
        if(abs(a)/60<=9){
            cout<<"0"<<abs(a)/60<<":";
            if(abs(a)%60<=9){
                cout<<"0"<<abs(a)%60;
            }
            else{
                cout<<abs(a)%60;
            }
        }
        else{
            cout<<abs(a)/60<<":";
            if(abs(a)%60<=9){
                cout<<"0"<<abs(a)%60;
            }
            else{
                cout<<abs(a)%60;
            }
        }
    }



    return 0;
}