#include<bits/stdc++.h>
#define pii pair<int,int>
#define pb(x) push_back(x)
#define sqr(x) ((x)*(x))
#define mp(x,y) make_pair((x),(y))
#define N 1000005
#define first x
#define second y
typedef long long LL;
using namespace std;
int main(){
//	map<pii,int> m[100005];
	int n;
	scanf("%d",&n);
	int a[100005];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	int gcd=__gcd(a[0],a[1]);
	for(int i=2;i<n;i++)
	gcd=__gcd(gcd,a[i]);
	if(gcd!=1)
	printf("YES\n0\n");
	else{
		int ans=0;
		for(int i=0;i<n;i++)
		a[i]%=2;
		for(int i=0;i<n;i++){
			if(a[i]==1)
			{
				if(a[i+1]==1)
				a[i]=a[i+1]=0,ans++;
				else
				a[i]=0,ans+=2;
			}
		}
		printf("YES\n%d\n",ans);
	}
}