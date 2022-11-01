#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,l[N],a[N][3];
string s[N];
bool v2[26][26],v3[26][26][26];
void Solve(){
	cin>>n;
	memset(v2,0,sizeof(v2));
	memset(v3,0,sizeof(v3));
	int ok=0;
	for(int i=1;i<=n;++i){
		cin>>s[i];
		l[i]=s[i].length();
		for(int j=0;j<l[i];++j){
			a[i][j]=s[i][j]-'a';
		}
		string t=s[i];
		reverse(t.begin(),t.end());
		if(s[i]==t){
			ok=1;
		}
	}
	for(int i=1;i<=n;++i){
		if(l[i]==2){
			if(v2[a[i][1]][a[i][0]])ok=1;
			for(int j=0;j<26;++j){
				if(v3[a[i][1]][a[i][0]][j])ok=1;
			}
			v2[a[i][0]][a[i][1]]=1;
		}
		if(l[i]==3){
			if(v2[a[i][2]][a[i][1]]||v3[a[i][2]][a[i][1]][a[i][0]])ok=1;
			v3[a[i][0]][a[i][1]][a[i][2]]=1;
		}
	}
	cout<<(ok?"YES\n":"NO\n");
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}