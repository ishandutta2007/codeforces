#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
LL dis(const pii &a,const pii &b){
	return sqr((LL)b.x-a.x)+sqr((LL)b.y-a.y);
}
LL dot(const pii &a,const pii &b,const pii &c){
	LL x1=a.x-b.x,y1=a.y-b.y,x2=c.x-b.x,y2=c.y-b.y;
	return x1*x2+y1*y2;
}
vector<int> f;
void KMP(vector<LL> a){
	int j=-1;
	f.pb(j);
	for(int i=1;i<a.size();i++){
		while(j!=-1&&a[i]!=a[j+1])j=f[j];
		if(a[i]==a[j+1])j++;
		f.pb(j);
	}
}
int main(){
	int n[2];
	scanf("%d %d",&n[0],&n[1]);
	pii p[2][100005];
	pll ans[2][100005];
	int Si[2];
	for(int j=0;j<2;j++){
		for(int i=0;i<n[j];i++){
			int x,y;
			scanf("%d %d",&x,&y);
			p[j][i]=mp(x,y);
		}
		sort(p[j],p[j]+n[j]);
		ans[j][0]=p[j][0];
		int k=0;
		int now=0;
		for(int t=0;t<2;t++){
			for(int i=1;i<n[j];i++){
				while(now!=k&&(p[j][i].y-ans[j][now-1].y)*(ans[j][now].x-ans[j][now-1].x)<=(p[j][i].x-ans[j][now-1].x)*(ans[j][now].y-ans[j][now-1].y)){
					now--;
				} 
				ans[j][++now]=p[j][i];
			}
			k=now;
			Si[j]=k;
			reverse(p[j],p[j]+n[j]);
		}
	}
	vector<LL> v[2];
	for(int i=0;i<2;i++){
		for(int j=0;j<Si[i];j++){
			v[i].pb(dis(ans[i][j],ans[i][(j+1)%Si[i]]));
			v[i].pb(dot(ans[i][j],ans[i][(j+1)%Si[i]],ans[i][(j+2)%Si[i]]));
		}
	}
	if(v[0].size()!=v[1].size()){
		printf("NO\n");
		return 0;
	}
	int Size=v[0].size();
	for(int i=0;i<Size;i++){
		v[0].pb(v[0][i]);
	}
	/*
	for(auto it:v[0])
		printf("%lld ",it);
	printf("\n");
	for(auto it:v[1])
		printf("%lld ",it);
	printf("\n");*/
	KMP(v[1]);
	int j=-1;
	int ok=0;
	for(int i=0;i<v[0].size();i++){
		while(j!=-1&&v[0][i]!=v[1][j+1])j=f[j];
		if(v[0][i]==v[1][j+1])j++;
		if(j==v[1].size()-1){
			if(i%2){
				ok=1;
				break;
			}
		//	printf("%d %d",i,)
			j=f[j];
		}
	//	printf("%d ",j);
	}
	//printf("\n");
	if(ok)
		printf("YES\n");
	else
		printf("NO\n");
}