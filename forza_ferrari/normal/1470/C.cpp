#include<iostream>
#include<cstdio>
using namespace std;
int n,m,pos;
int main()
{
    cin>>n>>m;
    pos=-1;
    for(int i=1;;++i)
    {
        pos=(pos+i)%n;
        cout<<"? "<<pos+1<<endl;
        int x;
        cin>>x;
        if(x==m)
            continue;
        if(x<m)
        {
            while(1)
            {
                pos=(pos+1)%n;
                cout<<"? "<<pos+1<<endl;
                int y;
                cin>>y;
                if(y==m)
                {
                    cout<<"! "<<pos+1<<endl;
                    return 0;
                }
            }
        }
        else
        {
            while(1)
            {
                pos=(pos+n-1)%n;
                cout<<"? "<<pos+1<<endl;
                int y;
                cin>>y;
                if(y==m)
                {
                    cout<<"! "<<pos+1<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}