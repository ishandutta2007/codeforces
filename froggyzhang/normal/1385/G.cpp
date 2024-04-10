#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define N 200020
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
int T,n,a[2][N],cnt[N],vis[N];
pair<int,int> pos[2][N];
vector<pair<int,int> > vec[N];
int MYHMD(string s,vector<int> &p,vector<int> &myhmd){
	int tot=0;
	for(int i=0;i<(int)s.length();++i){
		if(s[i]=='0'){
			++tot;
			myhmd.push_back(p[i]);
			if(i+1<(int)s.length())s[i+1]=((s[i+1]-'0')^1)+'0';
		}
	}
	return tot;
}
void calc(string &s,vector<int> &p,vector<int> &tmp){
	for(int i=0;i<(int)s.length();++i){
		if(s[i]=='1'){
			if(i&1){
				rotate(s.begin(),s.begin()+i,s.end());
				rotate(p.begin(),p.begin()+i,p.end());
				break;
			}
		}
	}
	vector<int> wzp,zyy;
	int ans1=MYHMD(s,p,wzp);
	int gu=0;
	for(int i=(int)s.length()-1;i>=-1;--i){
		if(i>=0&&s[i]=='0')++gu;
		else{
			if(gu&1){
				rotate(s.begin(),s.begin()+i,s.end());
				rotate(p.begin(),p.begin()+i,p.end());
				break;
			}
			gu=0;
		}
	}
	int ans2=MYHMD(s,p,zyy);
	if(ans1<=ans2){
		for(auto x:wzp)tmp.push_back(x);
	}
	else{
		for(auto x:zyy)tmp.push_back(x);
	}
}
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		cnt[i]=vis[i]=0;
		vec[i].clear();
	}
	for(int i=0;i<2;++i){
		for(int j=1;j<=n;++j){
			a[i][j]=read();
			++cnt[a[i][j]];
			vec[a[i][j]].emplace_back(i,j);
		}
	}
	for(int i=1;i<=n;++i){
		if(cnt[i]^2){
			printf("-1\n");
			return;
		}
		pos[vec[i][0].first][vec[i][0].second]=vec[i][1];
		pos[vec[i][1].first][vec[i][1].second]=vec[i][0];
	}
	vector<int> ans;
	vector<int> p;
	for(int i=1;i<=n;++i){
		if(vis[i])continue;
		string qwq="";
		int t=0,k=i;
		p.clear();
		while("MYH AK IOI!"){
			if(vis[k])break;
			vis[k]=1;
			auto nw=pos[t][k];
			int nt=nw.first,nk=nw.second;
			qwq+=(t^nt)+'0';
			t=nt^1,k=nk;
			p.push_back(nk);
		}
		calc(qwq,p,ans);
	}
	printf("%d\n",(int)ans.size());
	for(auto x:ans){
		printf("%d ",x);
	}
	printf("\n");
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}