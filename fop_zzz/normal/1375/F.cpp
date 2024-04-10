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

ll a[4],in;
int main()
{
	ll a1,a2;
	For(i,1,3)	cin>>a[i];
	puts("First");
	cout<<10000000000LL<<endl;
	cout.flush();
	cin>>in;
	a[in]+=1e10;
	a2=a[in];
	//a3+a1=2*a2   a1=2*a2-a3   difff=2*a2-a1-a3
	cout<<3*a2-a[2]-a[1]-a[3]<<endl;//writeln(3*a2-a[2]-a[1]-a[3]);
	cout.flush();
	cin>>in;
	a[in]+=3*a2-a[2]-a[1]-a[3];
	a1=a[in];
	cout<<a1-a2<<endl;
	cout.flush();
	cin>>in;
	a[in]+=a1-a2;
	//write_p(a[1]);write_p(a[2]);writeln(a[3]);
}