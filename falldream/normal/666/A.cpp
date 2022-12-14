#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define MN 10000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,f[MN+5],F[MN+5];
char st[MN+5];
set<pair<pair<int,int>,int> >S;

bool check(int l,int r,int L,int R)
{
    if(r-l!=R-L) return true;
    for(int i=0;i<r-l+1;++i) if(st[l+i]!=st[L+i]) return true;
    return false;
}

bool Check(int l,int r)
{
    if(r-l+1==2)
    {
        if(F[r+1]) return f[l]=true;
        if(f[r+1]&&check(l,r,r+1,r+2)) return f[l]=true;
        return false;
    }
    else
    {
        if(f[r+1]) return F[l]=true;
        if(F[r+1]&&check(l,r,r+1,r+3)) return F[l]=true;
        return false;
    }
}

int main()
{
    scanf("%s",st+1);n=strlen(st+1);F[n+1]=f[n+1]=1;
    for(int i=n;i>5;--i)for(int j=i+1;j<=min(i+2,n);++j) if(Check(i,j))
    {
        if(j-i+1==2) S.insert(make_pair(make_pair(st[i],st[i+1]),0));
        else S.insert(make_pair(make_pair(st[i],st[i+1]),st[i+2]));
    }
    printf("%d\n",S.size());
    for(set<pair<pair<int,int>,int> >::iterator it=S.begin();it!=S.end();++it)
        if(it->second!=0) printf("%c%c%c\n",it->first.first,it->first.second,it->second);
        else printf("%c%c\n",it->first.first,it->first.second);
    return 0;
}