#include<cstdio>
#include<cstring>
#include<set>
using namespace std; 
typedef long long ll;
const int N=200001;
int read() 
{ 	
    int a=0;char b=1,c; 
    do if((c=getchar())==45)b=-1;while(!(c&16)); 
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())&16); 
    return a*b; 
} 
void write(int x) 
{
    if(x<0)putchar('-'),x=-x; 
    char a[10],s=0; 
    do a[s++]=x%10|48;while(x/=10); 
    do putchar(a[--s]);while(s);
} 
ll a[N];
int main()
{
	int n=read(),ans=0;
	ll sum=0;
	set<ll>st;
	st.insert(0);
	while(n--)
	{
		int t=read();
		if(st.count(sum+=t))++ans,st.clear(),st.insert(0),sum=t;
		st.insert(sum);	
	}
	write(ans);
	return 0;
}