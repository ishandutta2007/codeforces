#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef long double LD;
struct RT
{
    LL X,Y,A;
    RT():X(0),Y(0),A(0){}
    inline bool operator<(const RT&x)const{return X<x.X;}
};
struct LINE
{
    LL X,Y;
    LINE():X(0),Y(0){}
    LINE(LL x,LL y):X(x),Y(y){}
};
inline LD cross(LINE n,LINE m)
{
    return (LD)(n.Y-m.Y)/(m.X-n.X);
}
int n;
vector<LINE>CHT;
inline void CHI(const LL a,const LL b)
{
    LINE t=LINE(a,b);
    while(CHT.size()>1)
    {
        LINE t1=CHT.back();
        LINE t2=CHT[CHT.size()-2];
        if(cross(t1,t2)<=cross(t,t2))
        {
            if(n==CHT.size())
                n--;
            CHT.pop_back();
        }
        else
            break;
    }
    CHT.push_back(t);
    return;
}
inline LL CHR(const LL x)
{
    while(n<CHT.size()-1)
    {
        if((LD)x<=cross(CHT[n],CHT[n+1]))
            n++;
        else
            break;
    }
    return CHT[n].Y+CHT[n].X*x;
}
vector<RT>V;
LL dp[1234567];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin>>N;
    V.resize(N);
    for(int i=0;i<N;i++)
        cin>>V[i].X>>V[i].Y>>V[i].A;
    sort(V.begin(),V.end());
    CHI(0,0);
    LL maxi=0;
    for(int i=0;i<N;i++)
    {
        LL&x=V[i].X;
        LL&y=V[i].Y;
        LL&a=V[i].A;
        dp[i]=x*y-a+CHR(y);
        CHI(-x,dp[i]);
        if(maxi<dp[i])
            maxi=dp[i];
    }
    cout<<maxi<<endl;
    return 0;
}