#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1,mod=1e9+7;
int t,n,a[N],b[N],c[N],fa[N],fb[N],ans;
bool book[N];
#define fi for(int i=1;i<=n;i++)
void dfs(int x){
	if(book[x])return;
	book[x]=1;
	dfs(b[fa[x]]);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		ans=1;
		cin>>n;
		fi book[i]=0;
		fi cin>>a[i],fa[a[i]]=i;
		fi cin>>b[i],fb[b[i]]=i;
		fi {cin>>c[i];if(c[i])dfs(c[i]);}
		fi{
			if(!book[i]){
				if(fa[i]==fb[i])continue;
				dfs(i);
				ans*=2;
				ans%=mod;
			}
		}
		cout<<ans<<endl;
	}
	
}