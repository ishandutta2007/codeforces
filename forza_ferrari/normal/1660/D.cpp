#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int t,n,a[200001],maxn,ans[2];
vector<int> v;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        v.clear();
        v.emplace_back(0);
        maxn=0;
        ans[0]=n;
        ans[1]=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            if(!a[i])
                v.emplace_back(i);
        }
        v.emplace_back(n+1);
        for(int i=1;i<(int)v.size();++i)
        {
            int tag=1,cnt=0,l=v[i-1]+1,r=v[i]-1;
            for(int j=l;j<=r;++j)
            {
                if(a[j]<0)
                    tag=-tag;
                cnt+=a[j]==2||a[j]==-2;
            }
            if(tag==1)
            {
                if(cnt>maxn)
                {
                    maxn=cnt;
                    ans[0]=l-1;
                    ans[1]=n-r;
                }
                continue;
            }
            int vl=0,vr=0,pl=0,pr=0,pos=l;
            while(a[pos]>0)
            {
                vl+=a[pos]==2||a[pos]==-2;
                ++pos;
            }
            pl=pos;
            vl+=a[pos]==2||a[pos]==-2;
            pos=r;
            while(a[pos]>0)
            {
                vr+=a[pos]==2||a[pos]==-2;
                --pos;
            }
            vr+=a[pos]==2||a[pos]==-2;
            pr=pos;
            if(vl<vr)
            {
                if(cnt-vl>maxn)
                {
                    maxn=cnt-vl;
                    ans[0]=pl;
                    ans[1]=n-r;
                }
            }
            else
            {
                if(cnt-vr>maxn)
                {
                    maxn=cnt-vr;
                    ans[0]=l-1;
                    ans[1]=n-pr+1;
                }
            }
        }
        cout<<ans[0]<<" "<<ans[1]<<'\n';
    }
    return 0;
}