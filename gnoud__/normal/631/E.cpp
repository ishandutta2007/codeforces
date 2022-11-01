#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define int long long
using namespace std;
const int N=2e5+10;
int n,a[N],sum[N],root,kq;
int Swap(int x,int y)
{
	if (x<=y) return root+a[x]*(y-x)-(sum[y]-sum[x]);
	else return root+(sum[x-1]-sum[y-1])-a[x]*(x-y);
}
void read( int &x)
{
    x = 0; char c; bool nega = 0;
    while (!isdigit(c = getchar()) && c != '-');
    if (c == '-') c = getchar(), nega = 1;
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (nega) x = -x;
}
main()
{
    //freopen("631E.inp","r",stdin);
    //freopen("631E.out","w",stdout);
	read(n);
	forinc(i,1,n) read(a[i]),sum[i]=sum[i-1]+a[i],root+=a[i]*i;
	kq=root;
	forinc(i,1,n)
	{
		int l=1,r=n;
		while((r-l)>=3)
        {
			int m1=l+(r-l)/3,m2=r-(r-l)/3;
			if(Swap(i,m1)>Swap(i,m2)) r=m2;else l=m1;
		}
		forinc(j,l,r) kq=max(kq,Swap(i,j));
	}
	cout<<kq;
}