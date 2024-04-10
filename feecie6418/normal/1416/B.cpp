#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[10005];
struct Y{
	int x,y,z;
}ans[30005];
int main(){
	int te;
	cin>>te;
	while(te--){
		cin>>n;
		int s=0;
		for(int i=1;i<=n;i++)cin>>a[i],s+=a[i];
		if(s%n){
			puts("-1");
			continue;
		}
		s/=n;
		int cnt=0;
		for(int O=2;O<=n;O++){
			int i=O;
			if(a[i]%i==0){
				ans[++cnt]={i,1,a[i]/i};
				a[1]+=a[i];
				a[i]=0;
				continue;
			}
			ans[++cnt]={1,i,i-a[i]%i};
			a[1]-=i-a[i]%i;
			a[i]+=i-a[i]%i;
			ans[++cnt]={i,1,a[i]/i};
			a[1]+=a[i];
			a[i]=0;
		}
		for(int i=2;i<=n;i++)ans[++cnt]={1,i,s},a[1]-=s,a[i]+=s;
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;i++)printf("%d %d %d\n",ans[i].x,ans[i].y,ans[i].z);
	}
    return 0;
}