#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1,s2;
    int position=0,count=0,x=0;
    cin >> s1>>s2;
    for(int i=0; i < s1.length();i++){
        if(s1[i]=='+')position++;
        else position--;
        if(s2[i]=='+')count++;
        else if(s2[i]=='-')count--;
        else x++;
    }
    //cout << position<< count<< x;
    count=abs(count-position);
    double ans=1;
    int xfac=x,countfac=(x-count)/2,fac=abs(x+count)/2;
    for(int i=x-1;i>0;i--){
        xfac=xfac*i;
    }
    for(int i=countfac-1;i>0;i--){
        countfac=countfac*i;
    }
    if(countfac==0)countfac=1;
    for(int i=fac-1;i>0;i--){
        fac=fac*i;
    }
    if(fac==0)fac=1;
   // cout<< x<<" "<<countfac<<" "<<fac<<endl;
    if(count>x) ans=0;
    else if(count ==0 && x==0)ans=1;
    else{
        ans=(double)pow(.5,x);
        ans=(double)ans*xfac/countfac/fac;
   //     if(count==0)ans=(double)ans*2;

    }
    printf("%0.12lf",ans);

    return 0;
}