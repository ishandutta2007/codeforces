#include<bits/stdc++.h>
using namespace std;
const int N=3e3+10;
#define res register int
#define gc getchar
inline int read(){
	res s=0,w=1,ch=gc();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=gc();
	}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
	return s*w;
}
inline void swap(res &x,res &y){
	x^=y^=x^=y;
}
int n,d;
vector<int> G[N];
char str[N];
#define pc __builtin_popcount
#define pb push_back
vector<int> A[N];
int a[N];
int S[N],T[N];
int L[N],R[N];
bool match(res x){
	S[x]=1;
	for(auto tox:G[x]){
		if(!T[tox]){
			T[tox]=1;
			if(!L[tox]||match(L[tox])){L[tox]=x,R[x]=tox;return 1;}
		}
	}
	return 0;
}
inline int getone(const res &x){
	for(res i=d;~i;i--){
		if((x>>i)&1)return i;
	}
	return 0;
}
vector<int> ans;
void dfs(res x){
	res tox=R[x];
	if(!tox){ans.pb(0);return;}
	for(res v=a[x]^a[tox],i=getone(v);v;v-=1<<i,i=getone(v))
		ans.pb(d-i);
	dfs(tox);
}
int main(){
	d=read(),n=read();
	for(res i=1;i<=n;i++){
		scanf("%s",str+1);
		res x=0;
		for(res j=1;j<=d;j++){
			x=x<<1|(str[j]-'0');
		}
		A[pc(x)].pb(i),a[i]=x;
	}
	for(res i=d;i;i--){
		for(auto x:A[i]){
			for(res j=i-1;j;j--){
				for(auto y:A[j]){
					if((a[x]&a[y])==a[y]){
						G[y].pb(x);
					}
				}
			}
		}
	}
	res ret=0;
	for(res i=d;i;i--){
		for(auto x:A[i]){
			for(res j=1;j<=n;j++)T[j]=0;
			ret+=match(x);
		}
	}
	for(res D=d;D;D--){
		for(auto x:A[D]){
			if(L[x])continue;
			for(res v=a[x],i=getone(v);v;v-=1<<i,i=getone(v)){
				ans.pb(d-i);
			}
			dfs(x);
		}
	}
	printf("%d\n",int(ans.size()-1));
	for(res sz=int(ans.size()-1),i=0;i<sz;i++){
		res x=ans[i];
		if(!x)putchar('R');
		else printf("%d",x-1);
		putchar(' ');
	}
	puts("");
	return 0;
}