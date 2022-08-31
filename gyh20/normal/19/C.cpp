#include<bits/stdc++.h>
using namespace std;
const int M=131;
int a[100002],rmp[100002],n,cnt,ans;
unsigned int h[100002],p[100002];
vector<int>v[100002];
vector<pair<int,int> >del;
map<int,int>mp; 
inline bool cmp(int x,int y){
	int xe=y-1,ye=2*y-x-1;
	if(ye>n)return 0;
	int hx=h[xe]-h[x-1]*p[y-x],hy=h[ye]-h[y-1]*p[y-x];	
	return hx==hy;		
}
inline int read(){
	int t=0;char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
} 
int main(){
	p[0]=1;n=read();
	for(int i=1;i<=n;++i){
		int x=read();
		if(mp.find(x)!=mp.end())a[i]=mp[x];
		else{
			mp[x]=++cnt;
			a[i]=cnt;
			rmp[cnt]=x;
		}
		p[i]=p[i-1]*M;
		v[a[i]].push_back(i);
		h[i]=h[i-1]*M+a[i];
	}
	for(int i=1;i<=cnt;++i)
		for(int j=0;j<v[i].size();++j)
			for(int k=j+1;k<v[i].size();++k)
				if(cmp(v[i][j],v[i][k]))del.push_back(make_pair(v[i][k]-v[i][j],v[i][j]));
	sort(del.begin(),del.end());
	for(int i=0;i<del.size();++i)if(del[i].second>ans)ans=del[i].second+del[i].first-1;
	printf("%d\n",n-ans);
	for(int i=ans+1;i<=n;++i)printf("%d ",rmp[a[i]]);
}