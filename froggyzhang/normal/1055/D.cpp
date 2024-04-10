#include<bits/stdc++.h>
using namespace std;
#define N 3030
typedef long long ll;
int n,sm[N],l[N],r[N];
string a[N],b[N],S,T;
vector<int> tS;
void init(const string &s,vector<int> &nxt){
	nxt.resize(s.length());
	nxt[0]=-1;
	for(int i=1,j=-1;i<(int)s.length();++i){
		while(~j&&s[j+1]^s[i])j=nxt[j];
		j+=s[j+1]==s[i];
		nxt[i]=j;
	}
}
bool check(int u){
	//a[u].replace(S,T);
	for(int i=0,j=-1;i<(int)a[u].length();++i){
		while(~j&&S[j+1]^a[u][i])j=tS[j];
		j+=S[j+1]==a[u][i];
		if(j==(int)S.length()-1){
			a[u].erase(a[u].begin()+i-j,a[u].begin()+i+1);	
			a[u].insert(i-j,T);
			break;
		}
	}
	return a[u]==b[u];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		cin>>b[i];
	}
	for(int i=1;i<=n;++i){
		if(a[i]==b[i])sm[i]=1;
	}
	for(int i=1;i<=n;++i){
		l[i]=1e9;
		if(!sm[i]){
			for(int j=0;j<(int)a[i].length();++j){
				if(a[i][j]^b[i][j]){
					l[i]=min(l[i],j),r[i]=max(r[i],j);
				}
			}
		}
	}
	int u=1;
	while(sm[u])++u;
	while(true){
		bool ok=true;
		for(int i=1;i<=n;++i){
			if(sm[i])continue;
			if(!l[i]||a[i][l[i]-1]^a[u][l[u]-1]||b[i][l[i]-1]^b[u][l[u]-1]){
				ok=false;break;
			}
		}
		if(ok){
			for(int i=1;i<=n;++i)--l[i];
		}
		else break;
	}
	while(true){
		bool ok=true;
		for(int i=1;i<=n;++i){
			if(sm[i])continue;
			if(r[i]==(int)a[i].length()-1||a[i][r[i]+1]^a[u][r[u]+1]||b[i][r[i]+1]^b[u][r[u]+1]){
				ok=false;break;
			}
		}
		if(ok){
			for(int i=1;i<=n;++i)++r[i];
		}
		else break;
	}
	S=a[u].substr(l[u],r[u]-l[u]+1);
	T=b[u].substr(l[u],r[u]-l[u]+1);
	init(S,tS);
	for(int i=1;i<=n;++i){
		if(!check(i)){
			cout<<"NO\n";
			return 0;		
		}
	}
	cout<<"YES\n";
	cout<<S<<'\n'<<T<<'\n';
	return 0;
}