#include <iostream>
#include <vector>
using namespace std;
int a[500000]; 
inline int gcd(int x,int y)
{
	if(x>y) swap(x,y);
	while(x) y%=x,swap(x,y);
	return y;
}
int s1[500005],s2[500005],cnt1,cnt2;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		cnt1=cnt2=0;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		int G=0;
		for(int i=1;i<=n;i++)
			G=gcd(G,a[i]);
		for(int i=1;i<=n;i++)
			a[i]/=G;
		for(int i=n+1;i<=n+n;i++)
			a[i]=a[i-n];
		int ans=0;
		for(int i=1;i<=n+n;i++)
		{
			s2[cnt2+1]=gcd(s2[cnt2],a[i]);
			++cnt2;
			while(gcd(s1[cnt1],s2[cnt2])==1&&cnt1) --cnt1;
			if(!cnt1)
			{
				for(int j=i;j>i-cnt2;j--) s1[cnt1+1]=gcd(s1[cnt1],a[j]),++cnt1;
				cnt2=0;
				while(s1[cnt1]==1) --cnt1;
			}
			ans=max(ans,cnt1+cnt2);
		}
		cout << ans << "\n";
	}
	return 0;
}