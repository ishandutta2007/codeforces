#include <iostream>
using namespace std;
int main()
{
    int a=0,b=0,d=0,i,g;
    string s;
    cin>>g>>s;
    for( i=0; i<g; i++ ){
        if(s[i]!='7' && s[i]!='4'){
            d++;
        }
    }
    if(d>0){
        cout<<"NO";
        return 0;
    }
    for( i=0; i<g/2; i++ ){
        if(s[i]=='0'){a+=0;}
        else if(s[i]=='1'){a+=1;}
        else if(s[i]=='2'){a+=2;}
        else if(s[i]=='3'){a+=3;}
        else if(s[i]=='4'){a+=4;}
        else if(s[i]=='5'){a+=5;}
        else if(s[i]=='6'){a+=6;}
        else if(s[i]=='7'){a+=7;}
        else if(s[i]=='8'){a+=8;}
        else if(s[i]=='9'){a+=9;}
    }
    for( i=g/2; i<g; i++ ){
        if(s[i]=='0'){b+=0;}
        else if(s[i]=='1'){b+=1;}
        else if(s[i]=='2'){b+=2;}
        else if(s[i]=='3'){b+=3;}
        else if(s[i]=='4'){b+=4;}
        else if(s[i]=='5'){b+=5;}
        else if(s[i]=='6'){b+=6;}
        else if(s[i]=='7'){b+=7;}
        else if(s[i]=='8'){b+=8;}
        else if(s[i]=='9'){b+=9;}
    }
    if(a==b){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}