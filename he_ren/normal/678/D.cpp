#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

ll c[3][3];
inline void mul(ll a[3][3],ll b[3][3])
{
	for(int i=0; i<=1; ++i)
		for(int j=0; j<=1; ++j)
		{
			c[i][j]=0;
			for(int k=0; k<=1; ++k)
				c[i][j] += a[i][k]*b[k][j] %mod;
			c[i][j]%=mod;
		}
	for(int i=0; i<=1; ++i)
		for(int j=0; j<=1; ++j) a[i][j]=c[i][j];
}

ll res[3][3], m[3][3];
void pw(ll a,ll b,ll n)
{
	res[0][0]=res[1][1]=1;
	m[0][0]=a; m[0][1]=b; m[1][1]=1;
	
	while(n)
	{
		if(n&1ll) mul(res,m);
		mul(m,m);
		n>>=1ll;
	}
}

int main(void)
{
	ll a,b,n,x;
	cin>>a>>b>>n>>x;
	
	pw(a,b,n);
	cout<< (x*res[0][0] + res[0][1]) %mod;
	return 0;
}