#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7,N=1000000;
int n,a[100005],mn[1000005],vst[1000005],fin[30],m,cho[100005],nd[1000005],b[30];
vector<int> pk[1000005];
vector<pr> fac[100005];
vector<vector<int>> ans;
int main(){
	for(int i=2;i<=N;i++){
		if(vst[i])continue;
		mn[i]=i;
		for(int j=i+i;j<=N;j+=i){
			if(!mn[j])mn[j]=i;
			vst[j]=1;
		}
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		int x=a[i];
		map<int,int> mp;
		while(x>1)mp[mn[x]]++,x/=mn[x];
		for(auto j:mp){
			fac[i].push_back(j);
			pk[j.first].push_back(j.second);
		}
	}
	ll ndg=1;
	for(int i=2;i<=N;i++){
		if(pk[i].size()<n-1)continue;
		sort(pk[i].begin(),pk[i].end());
		int mn1=pk[i][0];
		int mn2=(pk[i].size()==n?pk[i][1]:0);
		nd[i]=mn1+mn2;
		for(int j=1;j<=mn1+mn2;j++)ndg*=i;
		for(int j=1;j<=n;j++){
			bool has=0;
			for(auto k:fac[j]){
				if(k.first==i)has=1;
				if(k.first==i&&k.second==mn1){
					mn1=-1,cho[j]=1;
					break;
				}
				if(k.first==i&&k.second==mn2){
					mn2=-1,cho[j]=1;
					break;
				}
			}
			if(!has&&mn2==0)mn2=-1,cho[j]=1;
		}
		//cout<<mn1<<' '<<mn2<<'\n';
	}
	if(ndg==1)return puts("0"),0;
	int u=0;
	for(int i=1;i<=n;i++)if(cho[i])b[++u]=i;//,cout<<"inb "<<i<<'\n';
	ll g=0;
	for(int i=1;i<=u;i++)for(int j=i+1;j<=u;j++)g=gcd(g,1ll*a[b[i]]*a[b[j]]);
	//cout<<g<<'\n';
	for(int i=2;i<=N;i++){
		if(vst[i]||g%i||nd[i])continue;//nd 
		int t1=0,t2=0;
		for(int j=1;j<=n;j++){
			if(a[j]%i==0)continue;
			bool has=0;
			if(!has&&t1==0)t1=-1,cho[j]=1;
			else if(!has&&t2==0)t2=-1,cho[j]=1;
		}
	}
	u=0;
	for(int i=1;i<=n;i++)if(cho[i])b[++u]=i;
	for(int i=0;i<(1<<u);i++){
		if(__builtin_popcount(i)>14)continue;
		ll gg=0;
		for(int k=0;k<u;k++){
			if(!(i&(1<<k)))continue;
			for(int l=k+1;l<u;l++){
				if(i&(1<<l))gg=gcd(gg,1ll*a[b[k+1]]*a[b[l+1]]);//,cout<<1ll*a[b[k+1]]*a[b[l+1]]<<'\n';
			}
		}
		if(gg==ndg){
			for(int k=0;k<u;k++)if(i&(1<<k))fin[++m]=b[k+1];
			break;
		}
	}
	for(int i=1;i<(1<<m);i++){
		int k=__builtin_popcount(i);
		int s=(k%2?-1:1)*(k-2);
		if(s<0){
			for(int j=1;j<=-s;j++){
				vector<int> t;
				t.push_back(1);
				for(int k=0;k<m;k++)if(i&(1<<k))t.push_back(fin[k+1]);
				ans.push_back(t);
			}
		}
		else {
			for(int j=1;j<=s;j++){
				vector<int> t;
				t.push_back(0);
				for(int k=0;k<m;k++)if(i&(1<<k))t.push_back(fin[k+1]);
				ans.push_back(t);
			}
		}
	}
	cout<<ans.size()<<'\n';
	for(auto i:ans){
		cout<<i[0]<<' '<<i.size()-1<<' ';
		for(int j=1;j<i.size();j++)cout<<i[j]<<' ';
		puts("");
	}
}//