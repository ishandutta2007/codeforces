#include<iostream>
#include<cstdio>
using namespace std;
int t;
char c[11][11];
int main()
{
    cin>>t;
    while(t--)
    {
        for(int i=1;i<=8;++i)
            for(int j=1;j<=8;++j)
                cin>>c[i][j];
        for(int i=2;i<=7;++i)
            for(int j=2;j<=7;++j)
                if(c[i-1][j-1]=='#'&&c[i-1][j+1]=='#'&&c[i+1][j-1]=='#'&&c[i+1][j+1]=='#'&&c[i][j]=='#')
                    cout<<i<<" "<<j<<'\n';
    }
    return 0;
}