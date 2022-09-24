#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100005],b[100005];
void Solve(){
	cin>>n;
	for(int i=1,c1=0,c2=0,x,y;i<=2*n;i++){
		cin>>x>>y;
		if(!x)a[++c1]=abs(y);
		else b[++c2]=abs(x);
	}
	sort(a+1,a+n+1),sort(b+1,b+n+1);
	double sum1=0,sum2=0;
	for(int i=1;i<=n;i++)sum1+=sqrt(1ll*a[i]*a[i]+1ll*b[i]*b[i]);
	for(int i=1;i<=n;i++)sum2+=sqrt(1ll*a[i]*a[i]+1ll*b[n-i+1]*b[n-i+1]);
	printf("%.15lf\n",min(sum1,sum2));
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
    return 0;
}