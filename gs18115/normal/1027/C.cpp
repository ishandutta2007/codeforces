#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef long long LL;
map<LL,bool>chk;
LL T,N,i,A;
LL mini,maxi;
vector<LL>V;
inline bool cmp(LL cx,LL cy,LL chx,LL chy)
{
    return (cx+cy)*(cx+cy)*chx*chy>(chx+chy)*(chx+chy)*cx*cy;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>N;
        map<LL,bool>chk;
        chk.clear();
        V.clear();
        for(i=0;i<N;i++)
        {
            cin>>A;
            if(chk[A])
            {
                V.push_back(A);
                chk[A]=false;
            }
            else
                chk[A]=true;
        }
        sort(V.begin(),V.end());
        mini=1;
        maxi=99999;
        for(i=0;i<V.size()-1;i++)
        {
            if(cmp(mini,maxi,V[i],V[i+1]))
            {
                mini=V[i];
                maxi=V[i+1];
            }
        }
        cout<<mini<<' '<<mini<<' '<<maxi<<' '<<maxi<<'\n';
    }
    return 0;
}