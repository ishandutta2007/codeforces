#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define N 200005
#define M
#define pi 3.14159265359
using namespace std;
typedef long long LL;
int main(){
	int n;
	scanf("%d",&n);
	int a[200005];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	sort(a,a+n);
	int min=2e9,ans=0;
	for(int i=0;i<n-1;i++){
		if(a[i+1]-a[i]<min)
		min=a[i+1]-a[i],ans=1;
		else if(a[i+1]-a[i]==min)
		ans++;
	}
	if(min==0){
		LL Ans=0,sum=1;
		for(int i=1;i<n;i++)
		{
			if(a[i]==a[i-1])
			sum++;
			else
			Ans+=sum*(sum-1)/2;
		}
		Ans+=sum*(sum-1);
		printf("%I64d %I64d\n",min,Ans);
		return 0;
	}
	printf("%d %d\n",min,ans);
}