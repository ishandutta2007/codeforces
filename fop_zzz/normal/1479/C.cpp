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
int pw[44],num,number,l,r,q[44],top;
int e[44][44];
int main()
{
	pw[0]=1;
	For(i,1,27)	pw[i]=pw[i-1]*2;
	l=read(),r=read();
	int cnt=0;
	int ps=0;
	if(l!=1)	e[1][2]=l-1,++number,r-=(l-1),cnt=3;else	cnt=2,ps=1;// x- [1,2^(x-3)]
	int now=1;
	while(now<=r)
	{
		// cout<<now<<" "<<r<<endl;
		// cout<<cnt<<"=="<<now<<endl;
		e[2-ps][cnt]=1;++number;
		For(i,3,cnt-1+ps)	e[i-ps][cnt]=pw[max(0,i-3)],++number;
		now*=2;
		cnt++;
	}
	cnt--;
	// cout<<number<<endl;
	// cout<<cnt<<' '<<number<<endl;
	r--;
	bool ned=0;
	while(r)	
	{
		q[++top]=r%2,r/=2;
		if(q[top]==0)	ned=1;
	}
	if(ned)
	{
		now=0;//top+3->cnt
		++cnt;e[2-ps][cnt]=1;++number;
		Dow(i,1,top)
		{	
			// cout<<i<<"=>"<<q[i]<<endl;
			if(q[i]==1)	
			{
				e[i+2-ps][cnt]=now+1;++number;
				now+=pw[i-1];
			}
		}
	}
	puts("YES");
	write_p(cnt);writeln(number);
	For(i,1,cnt)	For(j,i+1,cnt)	if(e[i][j])	write_p(i),write_p(j),writeln(e[i][j]);
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
	-- Benq
*/