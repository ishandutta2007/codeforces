#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,m;
#define Maxn 200010
#define cout cerr
#define FR first
#define SE second
int valx[Maxn],lenx;
int x[Maxn],y[Maxn];
vector<int> vec[Maxn];
vector<pii> hh[Maxn];
bool ans[Maxn];//1:L
int calc(int t){return lower_bound(valx+1,valx+lenx+1,t)-valx;}

set<int> S;int at=-1;
set<int>::iterator it;
void move(int t){
	while(t&&S.size()){
		it=S.begin();
		int c=(*it)-at-1;
		if(c<=t){
			t-=c;
			at=(*it);
			S.erase(it);
		}else{
			at+=t;
			t=0;
		}
	}
	at+=t;
}

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int main(){
	rd(n);rd(m);
	bool flag=false;
	for(register int i=1;i<=n;++i){
		rd(x[i]);rd(y[i]);
		valx[++lenx]=x[i];
		if(x[i]==0&&y[i]==0)flag=true;
	}
	if(!flag){
		x[++n]=0;y[n]=0;
		valx[++lenx]=0;
	}
	for(int i=n+1;i<=n+m;++i){
		rd(x[i]);rd(y[i]);
		valx[++lenx]=x[i];
	}
	sort(valx+1,valx+lenx+1);
	lenx=unique(valx+1,valx+lenx+1)-valx-1;
	for(int i=1;i<=n;++i){
		x[i]=calc(x[i]);
		vec[x[i]].push_back(y[i]);
	}
	for(int i=n+1;i<=n+m;++i){
		x[i]=calc(x[i]);
		hh[x[i]].push_back(pii(y[i],i-n));
	}
	for(int i=1;i<=lenx;++i){
		if(i>1)move(valx[i]-valx[i-1]-1);
		int mn=2000000000;
		for(int j=0;j<vec[i].size();++j){
			mn=min(mn,vec[i][j]);
			if(vec[i][j]>at)S.insert(vec[i][j]);
		}
		bool flag=false;
		while(S.size()){
			it=S.begin();
			if((*it)>at+1){
				flag=true;
				if(at+1<mn){
					vec[i].push_back(at+1);
					at++;
				}
				break;
			}
			at++;
			S.erase(it);
		}
		if(!flag){
			if(at+1<mn){
				vec[i].push_back(at+1);
				at++;
			}
		}
		sort(vec[i].begin(),vec[i].end());
		for(int j=0;j<hh[i].size();++j){
			int t=lower_bound(vec[i].begin(),vec[i].end(),hh[i][j].FR)-vec[i].begin();
			if(t<vec[i].size()&&vec[i][t]==hh[i][j].FR)ans[hh[i][j].SE]=true;
		}
	}
	for(int i=1;i<=m;++i)
		if(ans[i])puts("LOSE");
		else puts("WIN");
	return 0;
}