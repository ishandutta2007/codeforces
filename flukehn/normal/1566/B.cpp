#include<bits/stdc++.h>
using namespace std;
char s[100011];
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;cin>>T;
	while(cin>>s){
		int n=strlen(s);
		int tot=0;
		for(int i=0;i<n;++i){
			if(s[i]=='0' && (!i||s[i-1]!='0') )++tot;
		}
		int ans=2;
		if(!tot)ans=0;
		else if(tot==1)ans=1;
		cout<<ans<<"\n";
	}

}