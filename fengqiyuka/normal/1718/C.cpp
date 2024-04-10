#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e5+100;
int a[N],sta[N],tot,g[N];ll b[25][N];
multiset<ll> S[25];
multiset<ll>::iterator iter;

void Change(int x,int c){
	for(int i=1;i<=tot;i++){
		iter=S[i].find(b[i][x%sta[i]]);
		S[i].erase(iter);
		b[i][x%sta[i]]+=(c-a[x]);
		S[i].insert(b[i][x%sta[i]]);
	}
	a[x]=c;
}
void print(){
	ll Ans=0;
	for(int i=1;i<=tot;i++){
		iter=S[i].end();iter--;
		Ans=std::max(Ans,(*iter)*sta[i]);
	}
	printf("%lld\n",Ans);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n,q;scanf("%d%d",&n,&q);
		for(int i=0;i<n;i++) scanf("%d",&g[i]),a[i]=0;
		int t=sqrt(n),e=n;tot=0;
		for(int i=2;i<=t;i++){
			if(e%i==0){
				sta[++tot]=n/i;
				while(e%i==0) e/=i;
			}
		}
		if(e>1) sta[++tot]=n/e;
		
		for(int i=1;i<=tot;i++){
			S[i].clear();
			for(int j=1;j<=sta[i];j++) S[i].insert(0),b[i][j-1]=0;
		}
		for(int i=0;i<n;i++) Change(i,g[i]);
		
		print();
		for(int i=1;i<=q;i++){
			int x,c;
			scanf("%d%d",&x,&c);
			Change(x-1,c);
			print();
		}
	}
	
	return 0;
}