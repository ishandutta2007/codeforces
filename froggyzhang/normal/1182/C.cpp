#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
#define N 100100
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
string s[N];
int n,p[N],m,cnt[1000100],vis[N];
vector<int> vec[1000100][5];
vector<pair<int,int> > f,g;
inline bool check(int x){
	int A=0,B=0;
	for(int u=1;u<=m;++u){
		int i=p[u];
		A+=cnt[i]>>1;
		for(int j=0;j<5;++j){
			B+=(int)vec[i][j].size()>>1;
		}
	}
	return A>=(x<<1)&&B>=x;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		cin>>s[i];
	}
	for(int i=1;i<=n;++i){
		int tot=0;
		int las=-1;
		for(int j=0;j<(int)s[i].length();++j){
			if(s[i][j]=='a'||s[i][j]=='e'||s[i][j]=='o'||s[i][j]=='i'||s[i][j]=='u'){
				++tot;
				if(s[i][j]=='a'){
					las=0;
				}
				else if(s[i][j]=='e'){
					las=1;
				}
				else if(s[i][j]=='i'){
					las=2;
				}
				else if(s[i][j]=='o'){
					las=3;
				}
				else{
					las=4;
				}
			}
		}
		vec[tot][las].push_back(i);
		p[++m]=tot;
		++cnt[tot];
	}
	sort(p+1,p+m+1);
	m=unique(p+1,p+m+1)-p-1;
	int l=0,r=n/4+1,ans=0;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	printf("%d\n",ans);
	for(int u=1;u<=m;++u){
		int i=p[u];
		if(g.size()==ans)break;
		for(int j=0;j<5;++j){
			if(g.size()==ans)break;
			for(int k=0;k+1<(int)vec[i][j].size();k+=2){
				g.push_back(make_pair(vec[i][j][k],vec[i][j][k+1]));
				vis[vec[i][j][k]]=vis[vec[i][j][k+1]]=1;
				if(g.size()==ans)break;
			}
		}
	}
	for(int u=1;u<=m;++u){
		int i=p[u];
		vector<int> tmp;
		if(f.size()==ans)break;
		for(int j=0;j<5;++j){
			for(int k=0;k<(int)vec[i][j].size();++k){
				if(!vis[vec[i][j][k]]){
					tmp.push_back(vec[i][j][k]);
				}
			}
		}
		for(int i=0;i+1<tmp.size();i+=2){
			if(f.size()==ans)break;
			f.push_back(make_pair(tmp[i],tmp[i+1]));
		}
	}
	for(int i=0;i<ans;++i){
		cout<<s[f[i].first]<<" "<<s[g[i].first]<<endl;
		cout<<s[f[i].second]<<" "<<s[g[i].second]<<endl;
	}
	return 0;
}