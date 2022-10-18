#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long
int t,n[3],ans;
vector<int> v[3];
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n[0]>>n[1]>>n[2];
        for(int j=0;j<3;++j)
        {
            v[j].clear();
            for(int i=1;i<=n[j];++i)
            {
                int x;
                cin>>x;
                v[j].push_back(x);
            }
            sort(v[j].begin(),v[j].end());
        }
        ans=3e18;
        for(int i=0;i<3;++i)
            for(auto j:v[i])
            {
                int pos1=lower_bound(v[(i+1)%3].begin(),v[(i+1)%3].end(),j)-v[(i+1)%3].begin(),pos2=lower_bound(v[(i+2)%3].begin(),v[(i+2)%3].end(),j)-v[(i+2)%3].begin(),val1,val2;
                if(!(pos1==v[(i+1)%3].size()||pos2==v[(i+2)%3].size()))
                {
                    val1=v[(i+1)%3][pos1],val2=v[(i+2)%3][pos2];
                    ans=min(ans,(j-val1)*(j-val1)+(j-val2)*(j-val2)+(val1-val2)*(val1-val2));
                }
                pos1=lower_bound(v[(i+1)%3].begin(),v[(i+1)%3].end(),j)-v[(i+1)%3].begin()-1,pos2=lower_bound(v[(i+2)%3].begin(),v[(i+2)%3].end(),j)-v[(i+2)%3].begin();
                if(!(pos1==-1||pos2==v[(i+2)%3].size()))
                {
                    val1=v[(i+1)%3][pos1],val2=v[(i+2)%3][pos2];
                    ans=min(ans,(j-val1)*(j-val1)+(j-val2)*(j-val2)+(val1-val2)*(val1-val2));
                }
                pos1=lower_bound(v[(i+1)%3].begin(),v[(i+1)%3].end(),j)-v[(i+1)%3].begin(),pos2=lower_bound(v[(i+2)%3].begin(),v[(i+2)%3].end(),j)-v[(i+2)%3].begin()-1;
                if(!(pos1==v[(i+1)%3].size()||pos2==-1))
                {
                    val1=v[(i+1)%3][pos1],val2=v[(i+2)%3][pos2];
                    ans=min(ans,(j-val1)*(j-val1)+(j-val2)*(j-val2)+(val1-val2)*(val1-val2));
                }
                pos1=lower_bound(v[(i+1)%3].begin(),v[(i+1)%3].end(),j)-v[(i+1)%3].begin()-1,pos2=lower_bound(v[(i+2)%3].begin(),v[(i+2)%3].end(),j)-v[(i+2)%3].begin()-1;
                if(!(pos1==-1||pos2==-1))
                {
                    val1=v[(i+1)%3][pos1],val2=v[(i+2)%3][pos2];
                    ans=min(ans,(j-val1)*(j-val1)+(j-val2)*(j-val2)+(val1-val2)*(val1-val2));
                }
            }
        cout<<ans<<endl;
    }
    return 0;
}