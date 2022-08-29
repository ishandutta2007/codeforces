#include<cstdio>
#include<algorithm>
#include<vector>
#define re register
using namespace std;
int n,m,k,cnt;
struct node{
	double val;
	int id,opt;
	bool operator <(const node a)const{return val>a.val;}
}b[100002],ans[100002];
vector<node>v[100002];
long long a[100002];
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
inline bool cmp(re node x,re node y){return x.opt<y.opt;}
int main(){
	n=read(),m=read(),k=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=1,x,y,z;i<=m;++i){
		x=read(),y=read(),z=read();
		if(x==1&&z>b[y].val)b[y]=(node){z,i,1};
		else if(x==2)v[y].push_back((node){z,i,2});
		else if(x==3)ans[++cnt]=(node){z,i,3};
	}
	for(re int i=1;i<=n;++i)if(b[i].id&&b[i].val>a[i])v[i].push_back((node){b[i].val-a[i],b[i].id,1});
	for(re int i=1;i<=n;++i){
		sort(v[i].begin(),v[i].end());
		for(re int j=0;j<v[i].size();++j){
			ans[++cnt]=(node){1.0l*(a[i]+v[i][j].val)/a[i],v[i][j].id,v[i][j].opt};
			a[i]+=v[i][j].val;
		}
	}
	sort(ans+1,ans+cnt+1),k=min(k,cnt),sort(ans+1,ans+k+1,cmp);
	printf("%d\n",k);
	for(re int i=1;i<=k;++i)printf("%d ",ans[i].id);
}