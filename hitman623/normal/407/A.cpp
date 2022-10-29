#include <bits/stdc++.h>
#define pb push_back
#define long long long
using namespace std;
int main()
{
    long a,b,i,j,x,y,xx,yy;
    cin>>a>>b;
    if(a>b) swap(a,b);
    for(i=1;i<a;++i)
    {
        x=i;
        y=sqrt(a*a-x*x);
        if(y*y==a*a-x*x)
        {
            for(j=-b+1;j<0;++j)
            {
                xx=j;
                yy=sqrt(b*b-j*j);
                if(yy*yy==b*b-j*j)
                {
                    if(yy*y==-xx*x && yy!=y)
                    {
                        cout<<"YES"<<endl;
                        cout<<0<<" "<<0<<endl;
                        cout<<x<<" "<<y<<endl;
                        cout<<xx<<" "<<yy<<endl;
                        exit(0);
                    }
                }
            }
        }
    }
    cout<<"NO";
    return 0;
}