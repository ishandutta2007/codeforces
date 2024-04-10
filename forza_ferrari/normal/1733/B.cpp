#include<iostream>
#include<cstdio>
using namespace std;
int t,n,x,y;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>x>>y;
        if(x>y)
            swap(x,y);
        if(x||!y||(n-1)%y)
        {
            cout<<"-1\n";
            continue;
        }
        int cnt=2;
        for(int i=1;i<=(n-1)/y;++i)
        {
            int tmp=cnt;
            for(int j=1;j<=y;++j)
            {
                ++cnt;
                cout<<tmp<<" ";
            }
        }
        cout<<'\n';
    }
    return 0;
}