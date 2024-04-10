#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define N 200005
#define M
#define pi 3.14159265359
using namespace std;
typedef long long LL;
const LL mod =2147483647;
vector<int> v[200005];
LL tot=0;
int n;
LL totmod[5];
struct mod5{
	int a[5];
	mod5(){
		memset(a,0,sizeof(a));
	}
};
LL dfs(int a,int f){
	LL sum=1;
	for(int i=0;i<v[a].size();i++)
	if(v[a][i]!=f){
		sum+=dfs(v[a][i],a);
	}
	tot+=sum*(n-sum);
	return sum; 
}
mod5 dfs2(int a,int f,int k){
	LL MOD[5];
	memset(MOD,0,sizeof(MOD));
	MOD[0]=1;
	for(vector<int>::iterator  it=v[a].begin();it!=v[a].end();it++){
		if(*it!=f){
			mod5 m=dfs2(*it,a,k);  
			for(int i=0;i<k;i++)
				for(int j=0;j<k;j++){
					totmod[(i+j)%k]+=MOD[i]*m.a[j];
			}
			for(int i=0;i<k;i++){
				MOD[i]+=m.a[i];
			}
		} 
	}
	for(int i=k-1;i>0;i--)
	swap(MOD[i-1],MOD[i]); 
	mod5 m;
	for(int i=0;i<k;i++)
	m.a[i]=MOD[i];
	return m;
}
main(){
	int k;
	while(scanf("%d %d",&n,&k)!=EOF){
		memset(totmod,0,sizeof(totmod));
		for(int i=0;i<n-1;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			v[a].pb(b);
			v[b].pb(a);
		}
		dfs(1,0);
		dfs2(1,0,k);
		for(int i=1;i<k;i++){
			tot-=i*totmod[i];
		}
		//printf("%d %d\n",totmod[0],totmod[1]);
		tot/=k;
		for(int i=1;i<k;i++)
		tot+=totmod[i];
		printf("%I64d\n",tot);
	}
}