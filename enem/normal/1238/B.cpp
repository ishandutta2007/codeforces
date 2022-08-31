#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)

int main()
{
				ll tc;
				cin>>tc;
				while(tc--)
				{
								ll n,r;
								cin>>n>>r;
								ll a[n];
								ll x=0;
								REP(i,0,n)
								{
												cin>>a[i];
								}
								sort(a,a+n);
								ll h=0;
								ll ans=0;
								while(x+h<n)
								{
												ans++;
												ll i=n-1-h;
												while(a[i]==a[n-1-h])
												{
																i--;
																if(i==-1) break;
								    }
												h=n-1-i;
												while(a[x]<=r*ans)
												{
																x++;
												    if(x==n) break;
												}
								}
								cout<<ans<<'\n';
				}
				return 0;
}