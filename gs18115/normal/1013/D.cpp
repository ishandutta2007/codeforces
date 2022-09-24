#include<iostream>
#include<vector>
#include<set>
using namespace std;
typedef long long LL;
const LL MAXI=234567;
const LL INF=1LL<<55LL;
LL X,Y,i,N,s,A,B;
LL pa[MAXI<<1],lv[MAXI<<1];
set<LL>S;
int parent(int a)
{
    if(pa[a]==-1)
        return a;
    return pa[a]=parent(pa[a]);
}
bool Find(int a,int b)
{
    if(parent(a)==parent(b))
        return true;
    return false;
}
void Union(int a,int b)
{
    int A=parent(a);
    int B=parent(b);
    if(Find(A,B))
        return;
    if(lv[A]>lv[B])
        pa[B]=A;
    else if(lv[A]<lv[B])
        pa[A]=B;
    else
    {
        pa[A]=B;
        lv[B]++;
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>A>>B>>N;
    for(i=0;i<A+B;i++)
        pa[i]=-1;
    for(i=0;i<N;i++)
    {
        cin>>X>>Y;
        Union(X-1,Y+A-1);
    }
    for(i=0;i<A+B;i++)
        S.insert(parent(i));
    cout<<S.size()-1;
    return 0;
}