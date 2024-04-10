#include<bits/stdc++.h>
using namespace std;
int n,col[1005],st[1005],top,is[1005],p[1005];
//int X[1000005],Y[1000005],m,cnt=0;
vector<int> g[1005];
map<vector<int>,int> mp;
int Get(vector<int> x){
	if(!x.size())return 0;
//	cnt++;
	sort(x.begin(),x.end());
	if(mp.count(x))return mp[x];
	cout<<"? "<<x.size()<<endl;
	for(int i:x)cout<<i<<' ';
	cout<<endl;
	int s;
	cin>>s;
//	int s=0,in[605]={0};
//	for(int i:x)in[i]=1;
//	for(int i=1;i<=m;i++)if(in[X[i]]&&in[Y[i]])s++;
//	if(x.size()==x.back()-x.front()+1){
//		f[x.front()][x.back()]=s;
//	}
	return mp[x]=s;
}
vector<int> rg(int l,int r){
	vector<int> o;
	for(int i=l;i<=r;i++)o.push_back(p[i]);
	return o;
}
void dfs(int x,int c){
	col[x]=c;
	for(int y:g[x])if(!col[y])dfs(y,3-c);
}
void dfs2(int x,int fa,int to){
	st[++top]=x;
	if(x==to){
		cout<<"N "<<top<<endl;
		for(int i=1;i<=top;i++)cout<<st[i]<<' ';
		cout<<endl;
		exit(0);
	}
	for(int y:g[x])if(y^fa)dfs2(y,x,to);
	top--;
}
void FindE(vector<int> x){
	int l=0,r=x.size()-1,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		vector<int> o;
		for(int i=0;i<=mid;i++)o.push_back(x[i]);
		if(Get(o))r=mid-1,ans=mid;
		else l=mid+1;
	}
	for(int i=0;i<ans;i++){
		if(Get({x[i],x[ans]})){
			dfs2(x[i],0,x[ans]);
		}
	}
} 
int main(){
	cin>>n;
	//m=n-1;
	//for(int i=1;i<n;i++)X[i]=i+1,Y[i]=rand()%i+1;
	is[1]=1;
	for(int i=2;i<=n;i++){
		int l=1,r=i-1,ans=0,ts=0;
		for(int j=1;j<=n;j++)if(is[j])p[++ts]=j;
		for(int j=1;j<=n;j++)if(!is[j])p[++ts]=j;
		int R=Get(rg(i,n)),U=0;
		while(l<=r){
			int mid=(l+r)/2,w;
			int t=Get(rg(mid,n))-R-(w=Get(rg(mid,i-1)));
			if(t)l=mid+1,ans=mid,U=w;
			else r=mid-1;
		}
		int x=ans;
		l=i,r=n,ans=0,R=U;
		while(l<=r){
			int mid=(l+r)/2;
			int t=Get(rg(x,mid))-R-Get(rg(i,mid));
			if(t)r=mid-1,ans=mid;
			else l=mid+1;
		}
		g[p[x]].push_back(p[ans]);
		g[p[ans]].push_back(p[x]);
		is[p[ans]]=1;
		//cerr<<i<<' '<<cnt<<'\n';
		//cout<<"I:"<<i<<' '<<x<<' '<<ans<<'\n';
	}
	//exit(0);
	dfs(1,1);
	vector<int> t;
	for(int i=1;i<=n;i++)if(col[i]==1)t.push_back(i);
	if(Get(t))FindE(t);
	t.clear();
	for(int i=1;i<=n;i++)if(col[i]==2)t.push_back(i);
	if(Get(t))FindE(t);
	cout<<"Y"<<' '<<t.size()<<endl;
	for(int i:t)cout<<i<<' ';
	cout<<endl;
}