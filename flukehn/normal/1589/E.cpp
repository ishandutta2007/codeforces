#include<bits/stdc++.h>
using namespace std;
const int N=3e5+11;
int a[N],n;
long long sum[N];
long long work(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	long long ans=0;
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+(i%2?-a[i]:a[i]);
	
	map<long long,int> f;
	f[0]++;
	for(int i=1;i<=n;++i){
		ans+=f[sum[i]];
		if(i%2==0){
			f.erase(f.upper_bound(sum[i]),f.end());
		}else{
			f.erase(f.begin(),f.lower_bound(sum[i]));
		}
		f[sum[i]]++;
	}
	/*for(int i=1;i<=n;++i){
		long long sum=0;
		for(int j=i;j<=n;++j){
			sum=a[j]-sum;
			if(sum<0)break;
			if(sum==0)++ans;
		}
	}*/
	return ans;
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int T;
	cin>>T;
	while(T--)cout<<work()<<"\n";
}