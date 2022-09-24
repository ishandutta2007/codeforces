#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char str[200005];
int s[200005],n,B=300,a[200005],p[200005],tot;
ll ans=0;
int main(){
	cin>>str+1,n=strlen(str+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+(str[i]=='1');
		if(str[i]=='1')p[++tot]=i;
	}
	for(int j=1;j<=B;j++){
		for(int i=0;i<=n;i++)a[i]=j*s[i]-i;
		stable_sort(a,a+n+1),a[n+1]=2e9;
		for(int i=0,cnt=0;i<=n+1;i++){
			if(i==0||a[i]^a[i-1])ans+=1ll*cnt*(cnt-1)/2,cnt=1;
			else cnt++;
		}
	}
	for(int i=1;i<=n;i++){
		int l=lower_bound(p+1,p+tot+1,i)-p;
		if(l>tot)break;
		for(int j=1,u=n/B,r;j<=u&&l+j-1<=tot;j++){//p[l]~p[l+j]-1
			int tl=p[l+j-1],tr=(l+j>tot?n:p[l+j]-1);
			ans+=max(0,(tr-i+1)/j-max((tl+j-i)/j,B+1)+1);
			//cout<<i<<' '<<j<<' '<<ans<<' '<<tr/j<<' '<<max((tl+j-1)/j,(i+j-1)/j+B)<<endl;
		}
	}
	cout<<ans;
	return 0;
}