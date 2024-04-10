#include<bits/stdc++.h>
using namespace std;
#define N 500005
#define ls k<<1
#define rs k<<1|1
#define mod 998244353
long long x,y,i,T,ss,gg,cnt[N],val[N],s[N],tg[N],ans,n,a[N],j;;

int main(){
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=(n<<2);++i)s[i]=tg[i]=0;
		for(i=1;i<=n;++i){
			cin>>a[i];
		}
		ans=ss=0;
		for(i=1;i<=n;++i){
			val[i]=a[i];--a[i];
			cnt[i]=0;
			for(j=i-1;j>0;--j){
				int l=cnt[j]+1;
				while(a[j]/l>=val[j+1]){
					l=a[j]/(a[j]/l)+1;
				}
				if(cnt[j]==l-1)break;
				else{
					ss+=(l-cnt[j]-1)*j;
					cnt[j]=l-1;
					val[j]=(a[j]+1)/l;
				}
			}
			(ans+=ss)%=mod;
		}
		cout<<ans<<"\n";
	}
}