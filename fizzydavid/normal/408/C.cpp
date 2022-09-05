#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>
using namespace std; 
bool sq[10001000];
int a,b,ax,ay,bx,by;
int main()
{
    for(int i=1;i<=1000;i++)sq[i*i]=1;
    cin>>a>>b;if(a<b)swap(a,b);
    for(int i=1;i*i<=a*a;i++)
    {
        if(sq[a*a-i*i])
        {
            ax=i,ay=sqrt(a*a-i*i)+0.0000001;
            for(int j=1;j*j<=b*b;j++)
            {
                if(sq[b*b-j*j])
                {
                    by=j,bx=-sqrt(b*b-j*j)-0.0000001;
                    if(by*ay==ax*abs(bx))
                    {cout<<"YES"<<endl<<"0 0"<<endl<<ax<<" "<<ay<<endl<<bx<<" "<<by<<endl;
                    return 0;}
                }
            }
        }
    }
    cout<<"NO";
    return 0;
}