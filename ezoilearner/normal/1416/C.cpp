#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,bool> pib;
const int T=30;
int n;
#define Maxn 300010
#define V 5000010
#define cout cerr
#define FR first
#define SE second
int a[Maxn];
vector<pib> vec[V];int root,cnt=0;
int son[V][2];

void Insert(int &k,int at,int pos){
	if(!k)k=++cnt;
	if(at==-1)return;
	if(a[pos]&(1<<at)){
		vec[k].push_back(pib(pos,1));
		Insert(son[k][1],at-1,pos);
	}else{
		vec[k].push_back(pib(pos,0));
		Insert(son[k][0],at-1,pos);
	}
}
ll res[T][2];
void Dfs(int k,int at){
	if(at==-1)return;
	if(son[k][0])Dfs(son[k][0],at-1);
	if(son[k][1])Dfs(son[k][1],at-1);
	int t=0;ll tmp=0;
	for(int i=0;i<vec[k].size();++i)
		if(!vec[k][i].SE)tmp+=t;
		else t++;
	res[at][0]+=tmp;
	res[at][1]+=1ll*t*(vec[k].size()-t)-tmp;
}

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int main(){
	rd(n);
	for(int i=1;i<=n;++i){
		rd(a[i]);
		Insert(root,T-1,i);
	}
	Dfs(root,T-1);
	ll Ans=0;int ans=0;
	for(int i=T-1;i>=0;--i){
		Ans+=min(res[i][0],res[i][1]);
		if(res[i][0]>res[i][1])ans|=(1<<i);
	}
	printf("%lld %d\n",Ans,ans);
	return 0;
}