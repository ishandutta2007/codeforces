#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7;
int n,a[100005],used[100005],c[100005],f[100005],d2[100005];
vector<vector<int>> u;
vector<int> v2[100005];
void U(int x,int y){
	while(x<=n)c[x]=max(c[x],y),x+=x&-x;
}
int Q(int x){
	int r=0;
	while(x)r=max(r,c[x]),x-=x&-x;
	return r;
}
vector<int> Solve1(){// 
	int len=0,mxp=0;
	for(int i=1;i<=n;i++)c[i]=0;
	for(int i=1;i<=n;i++){
		if(used[a[i]])continue;
		int w=Q(a[i]-1);
		w++,f[i]=w;
		U(a[i],f[i]);
		if(f[i]>len)len=f[i],mxp=i;
	}
	int lst=0;
	vector<int> ret;
	while(mxp){
		ret.push_back(a[mxp]),lst=a[mxp];
		len--,mxp--;
		while(mxp&&(used[a[mxp]]||f[mxp]!=len||a[mxp]>lst))mxp--;
	}
	reverse(ret.begin(),ret.end());
	return ret;
}
void Solve2(){// 
	int len=0;
	for(int i=1;i<=n;i++){
		if(used[a[i]])continue;
		int x=lower_bound(d2+1,d2+len+1,a[i])-d2;
		if(x==len+1){
			d2[len+1]=a[i];
			v2[len+1].push_back(a[i]);
			len++;
		}
		else v2[x].push_back(a[i]),d2[x]=a[i];
	}
	for(int i=1;i<=len;i++)u.push_back(v2[i]);
}
int getv(int n){
	int m=1;
	while((m+1)*(m+2)/2<=n)m++;
	return m;
}
void Solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	u.clear();
	int cur=n;
	while(cur){
		vector<int> t=Solve1();
		if(getv(cur)<t.size()){
			u.push_back(t);
			for(int i:t)used[i]=1;
			cur-=t.size();
			continue;
		}
		Solve2();
		break;
	}
	cout<<u.size()<<'\n';
	for(auto i:u){
		cout<<i.size()<<' ';
		for(auto j:i)cout<<j<<' ';
		puts("");
	}
	for(int i=1;i<=n;i++)used[i]=0,v2[i].clear();
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}