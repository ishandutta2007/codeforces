#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <ctime>

#define ll long long

using namespace std;

int t[100005],x[100005],ans[100005];
vector <pair<int,int> > v;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        scanf("%d%d",&t[i],&x[i]);
    int stime=0;
    for(int i=0;i<n;i+=m) {
        int mx=0;
        v.clear();
        for(int j=0;j<m&&i+j<n;++j) {
            stime=max(stime,t[i+j]);
            v.push_back(make_pair(x[i+j],i+j));
            mx=max(mx,x[i+j]);
        }
        sort(v.begin(),v.end());
        for(int j=0;j<m&&i+j<n;++j) {
            int cnt=1; stime+=v[j].first-(j ? v[j-1].first : 0);
            ans[v[j].second]=stime;
            for(;j+1<m&&i+j+1<n;++j)
                if (v[j+1].first==v[j].first) {
                    ++cnt;
                    ans[v[j+1].second]=stime;
                } else break;
            stime+=1+cnt/2;
        }
        stime+=mx;
    }
    for(int i=0;i<n;++i) {
        if (i) printf(" ");
        printf("%d",ans[i]);
    }
    printf("\n");
    return 0;
}