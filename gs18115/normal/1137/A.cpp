#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL N,M,i,j,r,c,h;
LL A[1010][1010],B[1010][1010];
vector<LL>row[1010],col[1010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M;
    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
            cin>>A[i][j];
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
            row[i].push_back(A[i][j]);
        sort(row[i].begin(),row[i].end());
        row[i].erase(unique(row[i].begin(),row[i].end()),row[i].end());
    }
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
            col[i].push_back(A[j][i]);
        sort(col[i].begin(),col[i].end());
        col[i].erase(unique(col[i].begin(),col[i].end()),col[i].end());
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            r=lower_bound(row[i].begin(),row[i].end(),A[i][j])-row[i].begin();
            c=lower_bound(col[j].begin(),col[j].end(),A[i][j])-col[j].begin();
            h=max(r,c);
            cout<<max((LL)row[i].size()+h-r,(LL)col[j].size()+h-c)<<' ';
        }
        cout<<'\n';
    }
    cout<<endl;
    return 0;
}