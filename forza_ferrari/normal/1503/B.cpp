#include<iostream>
#include<cstdio>
using namespace std;
int a1,b1,a2,b2,n,color;
int main()
{
    cin>>n;
    a1=b1=a2=1;
    b2=2;
    for(register int i=1;i<=n*n;++i)
    {
        cin>>color;
        if(color==1)
        {
            if(a2>n)
            {
                cout<<"3 "<<a1<<" "<<b1<<endl;
                b1+=2;
                if(b1>n)
                {
                    ++a1;
                    if(b1&1)
                        b1=2;
                    else
                        b1=1;
                }
            }
            else
            {
                cout<<"2 "<<a2<<" "<<b2<<endl;
                b2+=2;
                if(b2>n)
                {
                    ++a2;
                    if(b2&1)
                        b2=2;
                    else
                        b2=1;
                }
            }
        }
        if(color==2)
        {
            if(a1>n)
            {
                cout<<"3 "<<a2<<" "<<b2<<endl;
                b2+=2;
                if(b2>n)
                {
                    ++a2;
                    if(b2&1)
                        b2=2;
                    else
                        b2=1;
                }
            }
            else
            {
                cout<<"1 "<<a1<<" "<<b1<<endl;
                b1+=2;
                if(b1>n)
                {
                    ++a1;
                    if(b1&1)
                        b1=2;
                    else
                        b1=1;
                }
            }
        }
        if(color==3)
        {
            if(a2<=n)
            {
                cout<<"2 "<<a2<<" "<<b2<<endl;
                b2+=2;
                if(b2>n)
                {
                    ++a2;
                    if(b2&1)
                        b2=2;
                    else
                        b2=1;
                }
            }
            else
            {
                cout<<"1 "<<a1<<" "<<b1<<endl;
                b1+=2;
                if(b1>n)
                {
                    ++a1;
                    if(b1&1)
                        b1=2;
                    else
                        b1=1;
                }
            }
        }
    }
    return 0;
}