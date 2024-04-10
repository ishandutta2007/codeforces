#include<bits/stdc++.h>
using namespace std;
const int N=114;
char s[N];
int g[N*2],*f=g+N;
int n;
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;cin>>T;
	while(cin>>n>>s+1){
		memset(g,-1,sizeof g);
		f[0]=0;
		int now=0;
		int l=-1,r=-1;
		for(int i=1;i<=n;++i){
			if(s[i]=='a')++now;
			else --now;
			if(~f[now]){
				l=f[now]+1;
				r=i;
				break;
			}
			f[now]=i;
		}
		cout<<l<<" "<<r<<"\n";
	}
}