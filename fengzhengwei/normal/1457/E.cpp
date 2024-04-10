#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll n,k;
ll a[N],id[N],bef[N],q[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	ll place=n+1;
	ll maxx;
	ll tot=0,ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]<0){
			place=i;
			break;
		}
		ans+=tot;tot+=a[i];
	}
	ll used=0;k++;
	for(int i=n;i>=place;i--){
		used++;
		if(used>k)id[i]=id[i+1]+1,used=1;
		else id[i]=id[i+1];
		ans+=id[i]*a[i];bef[i]=used-1;
		if(used==1)q[++q[0]]=a[i];
		//cout<<i<<" "<<id[i]<<endl;
	}	
	ans+=q[0]*tot;
	maxx=ans;
//	cout<<ans<<endl;
	ll sum=0,at=q[0];
	for(int i=place;i<=n;i++){
		if(bef[i]==0){
			sum+=a[i];
			at=id[i];
			continue;
		}
	//	cout<<sum<<" "<<id[i]<<" "<<at<<" "<<tot<<endl;
		ans+=sum;ans-=id[i]*a[i];ans+=tot;ans+=at*a[i];
		maxx=max(maxx,ans);sum+=a[i];
	}
	
	cout<<maxx<<endl;
	return 0;
}