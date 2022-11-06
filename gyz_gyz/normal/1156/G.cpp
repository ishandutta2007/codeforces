#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define pb push_back
#define gc getchar()
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mo=1e9+7;
int tot,l[N],r[N];string is[N];bool v[N];char op[N];
bool ic(char c){
	return (c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9');
}
bool opr(char c){
	return (c=='$')||(c=='^')||(c=='#')||(c=='&');
}
void ins(string &s){++s[3];
	dep(i,3,1)if(s[i]>'z')++s[i-1],s[i]='a';else return;
}
void dfs(int x){
	if(v[x])return;v[x]=1;
	if(l[x])dfs(l[x]);
	if(r[x])dfs(r[x]);
}
typedef pair<pair<int,int>,char>piic;
int main(){int n;
	cin>>n;map<string,int>id;
	map<piic,int>p;
	rep(i,1,n){string a,b,c;
		char C=gc;while(!ic(C))C=gc;
		for(;C!='=';C=gc)a+=C;
		for(C=gc;ic(C);C=gc)b+=C;
		if(!id.count(b)){
			id[b]=++tot;is[tot]=b;
		}
		if(opr(C)){char OP=C;
			for(C=gc;ic(C);C=gc)c+=C;
			if(!id.count(c)){
				id[c]=++tot;is[tot]=c;
			}
			piic pt={{id[b],id[c]},OP};
			if(p.count(pt))id[a]=p[pt];else{
				p[pt]=++tot;l[tot]=id[b];r[tot]=id[c];
				op[tot]=OP;id[a]=tot;
			}
		}else id[a]=id[b];
	}
	if(!id.count("res")||is[id["res"]]=="res")return printf("0\n"),0;
	if(!is[id["res"]].empty())
		return cout<<"1\nres="<<is[id["res"]]<<'\n',0;
	is[id["res"]]="res";dfs(id["res"]);
	set<string>vb;int ans=1;
	rep(i,1,tot)if(v[i]){
		if(!is[i].empty())vb.insert(is[i]);else ++ans;
	}
	string nw="aaaa";
	while(vb.count(nw))ins(nw);
	cout<<ans<<'\n';
	rep(i,1,tot)if(v[i]&&l[i]){
		if(is[i].empty()){
			is[i]=nw;ins(nw);
		}
		cout<<is[i]<<'='<<is[l[i]];
		if(op[i])cout<<op[i]<<is[r[i]];cout<<'\n';
	}
}