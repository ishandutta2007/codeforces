#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int t,n,m;
vector<int> a[200001],b[200001];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int l=0,r=0;
        bool flag=1;
        for(int i=1;i<=n;++i)
        {
            a[i].resize(m+1);
            for(int j=1;j<=m;++j)
                cin>>a[i][j];
            b[i]=a[i];
            sort(b[i].begin(),b[i].end());
            int x=0,y=0;
            for(int j=1;j<=m;++j)
                if(a[i][j]^b[i][j])
                    if(!x)
                        x=j;
                    else
                        if(!y)
                            y=j;
                        else
                        {
                            flag=0;
                            break;
                        }
            if(!x&&!y)
                continue;
            if(!l&&!r)
            {
                l=x;
                r=y;
            }
            else
                if(l!=x||r!=y)
                    flag=0;
        }
        if(!flag)
        {
            cout<<"-1\n";
            continue;
        }
        if(!l&&!r)
        {
            cout<<"1 1\n";
            continue;
        }
        for(int i=1;i<=n;++i)
        {
            swap(a[i][l],a[i][r]);
            for(int j=2;j<=m;++j)
                if(a[i][j]<a[i][j-1])
                {
                    flag=0;
                    break;
                }
            if(!flag)
                break;
        }
        if(!flag)
            cout<<"-1\n";
        else
            cout<<l<<" "<<r<<'\n';
    }
    return 0;
}