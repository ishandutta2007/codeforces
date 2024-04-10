#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
typedef vector<LL>VL;
int N,M,i,b;
int a[12];
bool c;
bool chk[12];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    for(i=0;i<N;i++)
        cin>>a[i];
    for(i=0;i<M;i++)
    {
        cin>>b;
        chk[b]=true;
    }
    for(i=0;i<N;i++)
    {
        if(chk[a[i]])
        {
            cout<<a[i]<<' ';
            c=true;
        }
    }
    if(!c)
        cout<<'\n';
    return 0;
}