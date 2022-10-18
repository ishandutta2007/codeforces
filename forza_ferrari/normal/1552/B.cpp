#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[50001][5];
inline int win(int x,int y)
{
    int val=0;
    for(int i=0;i<5;++i)
        if(a[x][i]<a[y][i])
            ++val;
        else
            --val;
    return val>0? x:y;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            for(int j=0;j<5;++j)
                cin>>a[i][j];
        if(n==1)
        {
            cout<<"1\n";
            continue;
        }
        int p=win(1,2);
        for(int i=3;i<=n;++i)
            p=win(p,i);
        for(int i=1;i<=n;++i)
            if(i!=p&&p!=-1&&win(p,i)!=p)
                p=-1;
        cout<<p<<'\n';
    }
    return 0;
}