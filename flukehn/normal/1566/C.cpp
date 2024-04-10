#include<bits/stdc++.h>
using namespace std;
const int N=1e5+11;
char s[100011],t[N];
int n;
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;cin>>T;
	while(cin>>n>>s>>t){
		int ans=0,now=0;// now=0 {} now=1 {0} now=2 {1}
		for(int i=0;i<n;++i){
			int w=(1<<(s[i]-'0')) | (1<<t[i]-'0');
			if(w==3){//{0,1}
				ans+=(now==1);
				ans+=2;
				now=0;
			}else if(w==1){//{0}
				if(!now)now=1;
				else if(now==1)++ans;
				else{
					ans+=2;
					now=0;
				}
			}else{//{1}
				//assert(w==2);
				if(!now)now=2;
				else if(now==1){
					ans+=2;
					now=0;
				}else{
					//pass
				}
			}
		}
		ans+=(now==1);
		cout<<ans<<"\n";
	}

}