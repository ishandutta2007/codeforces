#include<iostream>
#include<cstdio>
using namespace std;
int t,n,cnt[10];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<10;++i)
            cnt[i]=0;
        for(int i=1;i<=n;++i)
        {
            int x;
            cin>>x;
            ++cnt[x%10];
        }
        bool flag=0;
        for(int i=0;i<10;++i)
            if(cnt[i])
            {
                --cnt[i];
                for(int j=0;j<10;++j)
                    if(cnt[j])
                    {
                        --cnt[j];
                        for(int k=0;k<10;++k)
                            if(cnt[k]&&(i+j+k)%10==3)
                            {
                                flag=1;
                                break;
                            }
                        if(flag)
                            break;
                        ++cnt[j];
                    }
                if(flag)
                    break;
                ++cnt[i];
            }
        cout<<(flag? "YES":"NO")<<'\n';
    }
    return 0;
}