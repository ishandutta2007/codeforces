#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int main()
{
    int sh,sm,s,th,tm,t,ph,pm,p;
    scanf("%d:%d",&sh,&sm);
    scanf("%d:%d",&th,&tm);
    s=sh*60+sm;t=th*60+tm;p=s-t;
    if(p<0)p+=1440;
    ph=p/60;pm=p%60;
    if(ph>9)cout<<ph<<":";else if(ph>0)cout<<"0"<<ph<<":";else cout<<"00:";
    if(pm>9)cout<<pm;else if(pm>0)cout<<"0"<<pm;else cout<<"00";
    return 0;
}