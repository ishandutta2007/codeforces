#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
int n,m,a[100005],s[100005],b[100005];
//s[b[i]]:b[i] 
void Solve(){
	scanf("%d%d",&n,&m);
	map<int,int> cnt;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),cnt[a[i]]++;
	int ans=1e9;
	for(pr i:cnt)s[i.second]++;
	int K=0;
	for(int i=1;i<=n;i++)if(s[i])b[++K]=i;
	for(int i=0,cntspace=0;i<=n;i++){
		if(cntspace>m)continue;
		//bcntspace
		int left=m,dec=0,all=0;
		for(int j=1;j<=K;j++)all+=s[b[j]];
		for(int j=1;j<=K&&left;j++){
			int x=s[b[j]]*b[j];
			if(x<=left)left-=x,dec+=s[b[j]];
			else {
				dec+=left/b[j];
				break;
			}
		}
		ans=min(ans,all-dec+(i==0&&all-dec==0));
		if(!cnt[i])cntspace++;
		if(cnt[i])s[cnt[i]]--;
	}
	cout<<ans<<'\n';
	for(int i=0;i<=n;i++)a[i]=b[i]=s[i]=0;
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}