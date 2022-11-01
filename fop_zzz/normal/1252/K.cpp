#include<bits/stdc++.h>
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back
#define fir first
#define sec second
#define pb push_back
#define pa pair<int,int>
#define mk make_pair
 
using namespace std;
 
inline ll read()
{
    ll t=0,dp=1;char c=getchar();
    while(!isdigit(c))  {if(c=='-') dp=-1;c=getchar();}
    while(isdigit(c))   t=t*10+c-48,c=getchar();
    return t*dp;
}
inline void write(ll x){if(x<0)  {putchar('-');x=-x;}    if(x>=10)    write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}

const int N = 5e5+5;
int a[N], b[N], n, ans;
inline bool check(int x)
{
    int now = 0;
    For(i, 1, n)
        if(b[i] >= now && a[i] >= x - now - 1) now ++; 
    if(now >= x) return 1;
    return 0;
}
int main(){
    int T = read();
    while(T--)
    {
        n = read();
        For(i, 1, n)
            a[i] = read(), b[i] = read();
        int l = 1, r = n;
        while(l <= r)
        {
            int mid = l + r >> 1;
            if(check(mid)) l = mid + 1,ans = mid;
            else r = mid - 1;
        }
        writeln(ans);
    }
}