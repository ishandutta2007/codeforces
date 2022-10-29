#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm> 
using namespace std;
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    for(int i=0;i< c/a+2;i++)
    {
        for(int j=0;j<c/b+2;j++)
        {
            if(i*a+j*b==c)
            {
                cout<<"YES";
                return 0;
            }
        }
    }
    cout<<"NO";
    return 0;
}