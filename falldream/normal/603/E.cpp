#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define MN 300000
#define pa pair<int,int>
#define mp(x,y) make_pair(x,y)
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int n,m,X[MN+5],Y[MN+5],W[MN+5],ans[MN+5],now=0,rk[MN+5],Ans[MN+5],Left,fa[MN+5],size[MN+5];
pa s[MN+5];vector<int> v;
inline int getfa(int x){return fa[x]==x?x:getfa(fa[x]);}
int Unite(int a)
{
    int x=X[a],y=Y[a],f1=getfa(x),f2=getfa(y),od=0;
    if(f1==f2) return 0;
    if((size[f1]&1)&&(size[f2]&1)) od+=2,Left-=2;
    if(size[f1]>size[f2]) swap(f1,f2);
    v.push_back(f1);fa[f1]=f2;size[f2]+=size[f1];
    return od;
}

void Back(int top)
{
    for(;v.size()>top;v.pop_back())
    {
        int x=v.back();
        size[fa[x]]-=size[x];fa[x]=x;
    }
}

void Solve(int l,int r,int ll,int rr)
{
    if(l>r) return;
  //  cout<<"Solve"<<l<<" "<<r<<" "<<ll<<" "<<rr<<" "<<Left<<endl;
    int mid=l+r>>1,Pt=-1,ad=0,Cur=v.size();
    for(int i=l;i<=mid;++i) if(rk[i]<ll) ad+=Unite(i);
    for(int i=ll;i<=rr;++i)
    {
        if(s[i].second<=mid) ad+=Unite(s[i].second);
        if(!Left) {Pt=i;break;}
    }
  //  cout<<"Pt="<<Pt<<endl;
    Back(Cur),Left+=ad,ad=0;
    if(Pt==-1)
    {
        for(int i=l;i<=mid;++i)
            if(Ans[i]=-1,rk[i]<ll) ad+=Unite(i);
        Solve(mid+1,r,ll,rr);
        Back(Cur);Left+=ad;return;
    }
    Ans[mid]=s[Pt].first;//cout<<mid<<" = "<<s[Pt].first<<endl;
    for(int i=l;i<=mid;++i)
        if(rk[i]<ll) ad+=Unite(i);
    Solve(mid+1,r,ll,Pt);Back(Cur);Left+=ad;ad=0;
    for(int i=ll;i<Pt;++i)
        if(s[i].second<l) ad+=Unite(s[i].second);
    Solve(l,mid-1,Pt,rr);Back(Cur);Left+=ad;ad=0;
}

int main()
{
    n=Left=read();m=read();
    for(int i=1;i<=n;++i) fa[i]=i,size[i]=1;
    for(int i=1;i<=m;++i)
    {
        X[i]=read();Y[i]=read();W[i]=read();
        s[i]=mp(W[i],i);
    }
    sort(s+1,s+m+1);
    for(int i=1;i<=m;++i) rk[s[i].second]=i;
    Solve(1,m,1,m);
    for(int i=1;i<=m;++i) printf("%d\n",Ans[i]);
    return 0;
}