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

int a[100010], p[100010],n;
inline void init()
{
	 cin >> n;
   	For(i,1,n)	cin >> a[i], p[i] = p[i-1] ^ a[i];
    For(i,1,n-2)	
    {
        if (a[i] > (a[i + 1] ^ a[i + 2]) )  
        {
            puts("1");
            exit(0);
        }      
    }
}
int main(){

	init();
    int ans = 1000000003;
    For(i,1,n)
    	For(j,i+2,n)
            for (int k = i; k < j; k++){
                if ((p[k] ^ p[i-1]) > (p[j] ^ p[k])) ans = min(ans, k - i + j - k - 1);
            }
    if (ans == 1000000003) puts("-1");
    else writeln(ans);
}