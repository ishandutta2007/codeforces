/*qwq*/
#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
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
int n,a[N],b[N],ban[N],tot;
char s[N];
vector<int> ans;
bool Find(int x){
	if(ban[x])return false;
	if(x==0){
		for(int i=0;i<=tot;++i){
			if(a[i]^1)return false;
		}
		for(int i=1;i<=tot;++i)ans.push_back(b[i]);
		return true;
	}
	if(x==1){
		for(int i=0;i<=tot;++i){
			if(a[i]&1)return false;
		}
		for(int i=0;i<=tot;++i){
			if(i){
				ans.push_back(b[i]+1);
			}
			for(int j=1;j<a[i]/2;++j){
				ans.push_back(1);
			}
		}
		return true;
	}
	for(int i=0;i<=tot;++i){
		if(i){
			ans.push_back(b[i]+x);	
		}	
		if((a[i]-x)&1){
			for(int j=1;j<=(a[i]-x)/2;++j)ans.push_back(1);	
		}
		else{
			for(int j=1;j<=(a[i]-x)/2-2;++j)ans.push_back(1);
			ans.push_back(2);
		}
	}
	return true;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	s[0]=s[n+1]='_';
	s[n+2]='#';
	for(int i=0,las=-1;i<=n+1;++i){
		if(s[i]=='_'&&s[i+1]=='#')a[tot]=i-las,las=i;
		if(s[i]=='#'&&s[i+1]=='_')++tot,b[tot]=i-las,las=i;
	}
	if(!tot)return !printf("0\n\n");
	int mn=n+1;
	for(int i=0;i<=tot;++i){
		if(a[i]>=2)ban[a[i]-2]=1;
		mn=min(mn,a[i]);	
	}
	for(int i=mn;i<=n;++i)ban[i]=1;
	if(Find(0)){
		
	}
	else if(Find(1)){
		
	}
	else{
		bool ok=false;
		for(int i=2;i<=n;++i){
			if(!ban[i]){
				Find(i);
				ok=true;
				break;
			}
		}
		if(!ok)return !printf("-1\n");
	}
	printf("%d\n",(int)ans.size());
	for(auto x:ans)printf("%d ",x);
	printf("\n");
	return 0;
}