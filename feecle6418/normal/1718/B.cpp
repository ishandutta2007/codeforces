#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef long long ll;
int n;
ll c[105],fib[105],sumlen[105],cnt[105],islst[105];
bool Check(int lst){
	if(lst==1)return cnt[2]==1;
	if(lst==2)return cnt[2]==2;
	if(cnt[2]==2&&*min_element(cnt+3,cnt+lst+1)==1&&*max_element(cnt+3,cnt+lst+1)==1)return 1;
	return 0;
}
void Solve(){
	memset(c,0,sizeof(c));
	memset(cnt,0,sizeof(cnt));
	memset(islst,0,sizeof(islst));
	cin>>n;
	ll s=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		s+=c[i];
		int lst=0;
		for(int j=50;j>=1;j--){
			if(c[i]>=fib[j]){
				c[i]-=fib[j],cnt[j]++;
				lst=j;
			}
		}
		islst[lst]=1;// 
	}
	bool out=0;
	for(int i=1;i<=50;i++){
		if(s==sumlen[i]){//cout<<"I:"<<i<<'\n';
			bool ok=Check(i);
			for(int j=4;j<=i+1;j+=2){
				if(!islst[j])continue;
				cnt[j]--;
				for(int k=j-1;k>=1;k-=2)cnt[max(k,2)]++;
				ok|=Check(i);
				//cout<<j<<' '<<ok<<'\n';
				//for(int k=1;k<=i;k++)cout<<cnt[k]<<' ';
				//puts("");
				cnt[j]++;
				for(int k=j-1;k>=1;k-=2)cnt[max(k,2)]--;
			}
			if(!ok)puts("No");
			else puts("Yes");
			out=1;
			break;
		}
	}
	if(!out)puts("No");
}
int main(){
	fib[1]=fib[2]=1;
	for(int i=3;i<=50;i++){
		fib[i]=fib[i-1]+fib[i-2];
	}
	for(int i=1;i<=50;i++){
		sumlen[i]=sumlen[i-1]+fib[i];
		//\\cerr<<sumlen[i]<<'\n';
	}
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}