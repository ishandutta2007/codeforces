#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back
#define IT set<int> :: iterator
#define debug puts("wzp akking");


using namespace std;

inline ll read()
{
    ll t=0,dp=1;char c=getchar();
    while(!isdigit(c))	{if(c=='-')	dp=-1;c=getchar();}
    while(isdigit(c))	t=t*10+c-48,c=getchar();
    return t*dp;
}
inline void write(ll x){if(x<0)	{putchar('-');x=-x;}	if(x>=10)	write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}
/*------------------------------------------------------------------------------------------------------*/
multiset<int> S,S1;
const int N=2e5+5;
int n,w,k,a[N],b[N],ans,use,cost,tv;

inline bool Ins(int r)
{
    if(r>n)	return 0;
    if(use<w)	
    {
        if((b[r]+1)/2+cost<=k)
        {
            S.insert(b[r]);
            cost+=(b[r]+1)/2;
            use++;
        }else	return 0;
    }else	
    {
        IT it=S.begin();
        if(*it<b[r])
        {
            if(cost+(b[r]+1)/2+(*it)/2>k)	return 0;
            S1.insert(*it);
            cost+=(b[r]+1)/2+(*it)/2;
            S.erase(it);
            S.insert(b[r]);
        }else
        {
            if(cost+b[r]>k)	return 0;
            else	cost+=b[r],S1.insert(b[r]);
        }
    }
    tv+=a[r];
    return 1;
}
inline void Del(int x)
{
    tv-=a[x];
    bool half=0;
    IT it=S.begin();
    if(b[x]<(*it))	half=0;else	half=1;
    if(!half)	
    {
        S1.erase(S1.find(b[x]));
        cost-=b[x];
    }else
    {
        S.erase(S.find(b[x]));
        use--;
        cost-=(b[x]+1)/2;
        if(S1.size())
        {
            IT it=S1.end();
            it--;use++;
            cost-=(*it)/2;
            S.insert(*it);
            S1.erase(it);
        }
    }
}
int main()
{
    n=read();w=read();k=read();
    For(i,1,n)	a[i]=read();
    For(i,1,n)	b[i]=read();
    use=0,cost=0;
    int r=1;
    Ins(1);
    while(1)
    {
        r++;
        bool flag=Ins(r);
        if(!flag)	{r--;break;}
    }
    ans=tv; 
    For(now,2,n)
    {
        Del(now-1);
        while(1)
        {
            r++;
            bool flag=Ins(r);
            if(!flag)	{r--;break;}
        }
        ans=max(ans,tv);
    }
    writeln(ans);
}
/*
31 10 471
785 637 518 257 957 866 438 173 381 549    1  624 286 323 903 488 366 414 695 728     226 49 377 663 850 230 733 102 760 960    218
30  53  89  16  96  4   37  34  34  73     97 73  5   87  58  46  77  19  51  68      27  87 7   4   48  99  88  91  55  71     96
*/