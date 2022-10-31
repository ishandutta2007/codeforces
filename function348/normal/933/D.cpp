#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
const int p=1000000007;
void chk(int &ans){if (ans<0) ans+=p;if (ans>=p) ans-=p;}
int main()
{
	long long m;
	cin>>m;
	int ans=0,mp=m%p,inv2=(p+1)/2,inv3=(p+1)/3,inv5=(2*p+1)/5;
	int inv6=1LL*inv2*inv3%p,inv7=(p+1)/7;
	int inv42=1LL*inv6*inv7%p;
	for (int x=0;1LL*x*x<=m;x++)
	{
		int q=sqrt(m-1LL*x*x);
		int xx=1LL*x*x%p;
		int sum2=1LL*q*(q+1)%p*(2*q+1)%p*inv6%p;
		int sum4=1LL*sum2*(3LL*q*q%p+3*q-1)%p*inv5%p;
		int sum6=1LL*(1LL*(1LL*(1LL*(1LL*inv7*q%p+inv2)*q%p+inv2)*q%p*q%p-inv6)*q%p*q%p+inv42)*q%p;
		ans+=(-sum4+1LL*(-2LL*xx+1)*sum2+1LL*(xx+mp)*(mp-xx+1)%p*q)%p*(mp+1)%p*inv2%p;chk(ans);
		ans+=-1LL*q*mp%p*(mp+1)%p*(2*mp+1)%p*inv6%p;chk(ans);
		ans+=1LL*(2LL*sum6+1LL*(6LL*xx%p-3)*sum4%p+1LL*(6LL*xx*xx%p-6LL*xx+1)*sum2%p+1LL*(1LL*xx*xx%p-xx)*(2*xx-1)%p*q)%p*inv6%p;
		chk(ans);
	}
	ans=(4LL*ans+1LL*inv6*mp%p*(mp+1)%p*(mp+2))%p;
	cout<<ans;
	return 0;
}