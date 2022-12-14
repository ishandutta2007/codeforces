#include<bits/stdc++.h>
#define MN 100000
#define MX 1500000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,Ans[MN+5],num[4],id[MN+5][4],g;
long long X,Y;
set<pair<int,int> > S[4];
pair<int,int> s[MN+5];
inline int Ran()
{
    g^=g<<13;g^=g>>17;g^=(g<<5);
    return g;
}
void Add(int x)
{
    if(s[x].first<0) S[0].insert(make_pair(id[x][0]=Ran(),x));
    if(s[x].first>0) S[1].insert(make_pair(id[x][1]=Ran(),x));
    if(s[x].second<0) S[2].insert(make_pair(id[x][2]=Ran(),x));
    if(s[x].second>0) S[3].insert(make_pair(id[x][3]=Ran(),x));
}
void Del(int x)
{
    if(s[x].first<0) S[0].erase(make_pair(id[x][0],x));
    if(s[x].first>0) S[1].erase(make_pair(id[x][1],x));
    if(s[x].second<0) S[2].erase(make_pair(id[x][2],x));
    if(s[x].second>0) S[3].erase(make_pair(id[x][3],x));
}
void Solve(int id,bool (*f)())
{
    while(!f())
    {
        int x=S[id].begin()->second;
        Del(x);X-=2*s[x].first;Y-=2*s[x].second;
        Ans[x]*=-1;s[x].first*=-1;s[x].second*=-1;
        Add(x);
    }
}
bool in(){return X>=-MX&&X<=MX&&Y>=-MX&&Y<=MX&&X*X+Y*Y<=1LL*MX*MX;}
bool XDown(){return X>=-1000000||in();}
bool XUp(){return X<=1000000||in();}
bool YDown(){return Y>=-1000000||in();}
bool YUp(){return Y<=1000000||in();}
int main()
{
    n=read();srand((long long)new char);g=rand();
    for(int i=1;i<=n;++i) 
    {
        s[i].first=read(),s[i].second=read();
        Ans[i]=1;X+=s[i].first;Y+=s[i].second;
        Add(i);
    }
    while(true)
    {
        if(!XDown()){Solve(0,XDown);continue;}
        if(!XUp()){Solve(1,XUp);continue;}
        if(!YDown()){Solve(2,YDown);continue;}
        if(!YUp()){Solve(3,YUp);continue;}
        for(int i=1;i<=n;++i) printf("%d ",Ans[i]);
        return 0;
    }
}