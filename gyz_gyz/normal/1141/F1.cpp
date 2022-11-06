#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define pb push_back
#define fr first
#define sc second
#define N 1510
using namespace std;
typedef pair<int,int>pii;
int n,ans,a[N];map<int,map<int,int>>p;
vector<pii>v;
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n){int x=0;
		rep(j,i,n){x+=a[j];
			if(p[x].count(i))p[x][i]=min(p[x][i],j);
			else p[x][i]=j;
		}
	}
	for(auto s:p){
		pii t={0,0};int w=0;vector<pii>vi;
		for(auto i:s.sc){
			if(i.fr>t.sc){
				if(t.sc)vi.pb(t);++w;t=i;
			}else if(i.sc<t.sc)t=i;
		}vi.pb(t);
		if(w>ans)ans=w,v=vi;
	}
	printf("%d\n",ans);
	for(auto i:v)printf("%d %d\n",i.fr,i.sc);
}