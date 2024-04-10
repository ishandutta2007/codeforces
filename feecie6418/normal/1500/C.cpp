#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int base1=233,base2=2011,mod1=1e9+7,mod2=1e9+9;
vector<int> a[1505],b[1505];
int n,m,K,id[1505],hsh1[1505],hsh2[1505],ans[1505],lst[1505][1505],cur1[1505],cur2[1505],used[1505];
bitset<1505> can[1505];
map<pair<int,int>,vector<int> > mp;
bool cmp(const vector<int> &a,const vector<int> &b){
	return a[K]<b[K];
}
void Sort(int x){
	//cerr<<x<<endl;
	K=x,stable_sort(a+1,a+n+1,cmp);
}
int main(){
	srand(time(0));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		a[i].resize(m);
		for(int j=0;j<m;j++)scanf("%d",&a[i][j]),hsh1[i]=(1ll*hsh1[i]*base1+a[i][j])%mod1,hsh2[i]=(1ll*hsh2[i]*base2+a[i][j])%mod2;
		mp[make_pair(hsh1[i],hsh2[i])].push_back(i);
	}
	for(int i=1;i<=n;i++){
		b[i].resize(m);
		for(int j=0;j<m;j++)scanf("%d",&b[i][j]);
	}
	for(int j=0;j<m;j++){
		for(int i=2;i<=n;i++)if(b[i][j]>=b[i-1][j])can[i][j]=1;
	}
	for(int i=n;i>=1;i--){
		int h1=0,h2=0;
		for(int j=0;j<m;j++)h1=(1ll*h1*base1+b[i][j])%mod1,h2=(1ll*h2*base2+b[i][j])%mod2;
		if(!mp[make_pair(h1,h2)].size())return puts("-1"),0;
		id[i]=mp[make_pair(h1,h2)].back();
		mp[make_pair(h1,h2)].pop_back();
	}
	while(1){
		bitset<1505> tmp;
		for(int i=0;i<m;i++)if(!used[i])tmp[i]=1;
		for(int i=1;i<=n;i++){
			if(i==1||cur1[i]!=cur1[i-1]||cur2[i]!=cur2[i-1])continue;
			tmp&=can[i];
		}
		//cout<<"A:"<<tmp.count()<<endl;
		if(!tmp.count())break;
		int pos=0;
		for(int i=0;i<m;i++)if(tmp[i]){pos=i;break;}
		used[pos]=1,ans[++ans[0]]=pos;
		for(int i=1;i<=n;i++)cur1[i]=(1ll*cur1[i]*base1+b[i][pos])%mod1,cur2[i]=(1ll*cur2[i]*base2+b[i][pos])%mod2;//,cout<<i<<' '<<cur1[i]<<' '<<cur2[i]<<'\n';
	}
	for(int i=ans[0];i;i--)Sort(ans[i]);
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<m;j++)cout<<a[i][j]<<' ';
//		puts("");
//	}
	for(int i=1;i<=n;i++)for(int j=0;j<m;j++)if(a[i][j]!=b[i][j])return puts("-1"),0;
	cout<<ans[0]<<'\n';
	for(int i=ans[0];i;i--)cout<<ans[i]+1<<' ';
	return 0;
}