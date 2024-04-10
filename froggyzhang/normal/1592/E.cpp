#include<bits/stdc++.h>
using namespace std;
#define N 2000100
const int inf=0x3f3f3f3f;
typedef long long ll;
int n,a[N],s[N];
int mn[N][2];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	int ans=0;
	memset(mn,0x3f,sizeof(mn));	
	for(int t=20,jb=0;t>=0;--t){
		for(int i=1,j=1;i<=n;i=j){
			if(!(a[i]>>t&1)){
				++j;continue;
			}
			while(j<=n&&a[j]>>t&1)++j;
			#define update(x,y) x=min(x,y)
			for(int k=i;k<j;++k){
				update(mn[s[k-1]&jb][(k-1)&1],k-1);
				ans=max(ans,k-mn[s[k]&jb][k&1]);
			}
			for(int k=i;k<j;++k){
				mn[s[k-1]&jb][0]=mn[s[k-1]&jb][1]=inf;
			}
		}
		jb|=1<<t;
	}
	cout<<ans<<'\n';
	return 0;
}