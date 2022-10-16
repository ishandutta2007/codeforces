#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
#define py cout<<"YES\n"
#define pn cout<<"NO\n"
#define ll long long
int T,i,j,n,p[N],s[N],cnt,d,c[N<<1],b[N],a[N],x,y,pos,e;
ll ans;
bool is[N];
void calc(int n){
	int i;
	for(i=1;i<=n;++i){
		if(b[i]==1)s[i]=0;
		else if(is[b[i]])s[i]=2;
		else s[i]=1;
		s[i]+=s[i-1];
	}
	for(i=0;i<=n;++i){
		if(s[i])ans+=c[s[i]-1];
		++c[s[i]];
	}
	for(i=0;i<=n;++i)--c[s[i]];
}
int main(){
	ios::sync_with_stdio(0);
	cin>>T;
	for(i=2;i<=1000000;++i){
		if(!is[i])p[++cnt]=i;
		for(j=1;(d=i*p[j])<=1000000;++j){
			is[d]=1;
			if(i%p[j]==0)break;
		}
	}
	while(T--){
		cin>>n>>e;
		for(i=1;i<=n;++i)cin>>a[i];
		ans=0;
		for(i=1;i<=e;++i){
			cnt=0;
			for(j=i;j<=n;j+=e){
				b[++cnt]=a[j];
				if(a[j]>1&&!is[a[j]])--ans;
			}
			calc(cnt);
		}
		cout<<ans<<"\n";
	}
	return 0;
}