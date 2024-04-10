#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=200010;
const int n=262144;
vector<int>V[MAXN];
vector<pair<int,bool> >VV[MAXN];
priority_queue<int,vector<int>,less<int> >SS;
bool CHK[(n<<1)+10];
int N,Q,i;
int maxi,mini;
int A;
void chk(int N)
{
    N+=n;
    while(N>0)
    {
        CHK[N]=true;
        N>>=1;
    }
    return;
}
bool chked(int s,int e)
{
    s+=n;
    e+=n;
    while(s<=e)
    {
        if(CHK[s]||CHK[e])
            return true;
        s=s+1>>1;
        e=e-1>>1;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>Q;
    for(i=0;i<N;i++)
    {
        cin>>A;
        V[A].push_back(i);
    }
    if(V[0].empty()&&V[Q].empty())
        return cout<<"NO"<<endl,0;
    for(i=1;i<=Q;i++)
    {
        if(!V[i].empty())
        {
            maxi=0;
            mini=N-1;
            for(int I:V[i])
            {
                maxi=max(maxi,I);
                mini=min(mini,I);
            }
            if(chked(mini,maxi))
                return cout<<"NO"<<endl,0;
        }
        else
        {
            if(V[0].empty())
                mini=maxi=V[Q][0];
            else
                mini=maxi=V[0][0];
        }
        if(i>1)
        {
            VV[mini].push_back(make_pair(i,true));
            VV[maxi].push_back(make_pair(i,false));
        }
        for(int I:V[i])
            chk(I);
    }
    cout<<"YES"<<endl;
    VV[0].push_back(make_pair(1,true));
    for(i=0;i<n;i++)
        CHK[i]=false;
    for(i=0;i<N;i++)
    {
        for(auto I:VV[i])
            if(I.second)
                SS.push(I.first);
        while(CHK[SS.top()])
            SS.pop();
        cout<<SS.top()<<' ';
        for(auto I:VV[i])
            if(!I.second)
                CHK[I.first]=true;
    }
    cout<<endl;
    return 0;
}