#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<string,string>pss;
const int N=1e6+10;
const int mo=1e9+7;
const ll Inf=1e18;
int mrk[200];
int main(){int n,ans=0;
	mrk['a']=1;mrk['e']=2;mrk['i']=3;mrk['o']=4;mrk['u']=5;
	scanf("%d",&n);vector<pss>v;map<int,queue<string>[5]>mp;
	rep(i,1,n){string s;
		cin>>s;int ct=0,ls;
		for(auto j:s)if(mrk[j])++ct,ls=mrk[j];
		mp[ct][ls-1].push(s);
	}
	for(auto &q:mp)rep(i,0,4){
		while(q.sc[i].size()>1){pss s;
			s.fr=q.sc[i].front();q.sc[i].pop();
			s.sc=q.sc[i].front();q.sc[i].pop();
			++ans;v.pb(s);
		}
	}
	for(auto &q:mp){pss s;
		rep(i,0,4)if(!q.sc[i].empty()){
			if(s.fr.empty())s.fr=q.sc[i].front();else{
				s.sc=q.sc[i].front();v.pb(s);s={"",""};
			}
		}
	}int m=v.size();
	ans=min(ans,m/2);
	printf("%d\n",ans);
	rep(i,1,ans)cout<<v[m-i].fr<<' '<<v[i-1].fr<<'\n'<<v[m-i].sc<<' '<<v[i-1].sc<<'\n';
}