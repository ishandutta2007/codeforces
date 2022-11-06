#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int k,n,m,Max[100005],opt[100005],x[100005],y[100005],tot,ans[100005];
long long a[100005];vector<int>v[100005];
bool cmp1(const int&a,const int&b){return y[a]>y[b];}
bool cmp2(const int&a,const int&b){return opt[a]<opt[b];}
struct node{
	long long x,y;int id;
	bool operator<(const node&a){
		return 1.0*x/y>1.0*a.x/a.y;
	}
}q[100005];
int main(){
	k=read();n=read();m=read();
	for(int i=1;i<=k;++i)a[i]=read();
	for(int i=1;i<=n;++i){
		opt[i]=read();x[i]=read();y[i]=read();
		if(opt[i]==1){
			if(y[i]>a[x[i]]&&y[i]>y[Max[x[i]]]){
				Max[x[i]]=i;
			}
		}
		if(opt[i]==2){
			v[x[i]].push_back(i); 
		}
		if(opt[i]==3){
			q[++tot]=(node){y[i],1,i};
		}
	}
	for(int i=1;i<=k;++i){
		if(Max[i]){
			y[Max[i]]-=a[i];
			v[i].push_back(Max[i]); 
		}
		if(v[i].size()){
			sort(v[i].begin(),v[i].end(),cmp1);
			for(int j:v[i]){
				q[++tot]=(node){a[i]+y[j],a[i],j};a[i]+=y[j];
			}
		}
	}
	sort(q+1,q+tot+1);
	for(int i=1;i<=min(m,tot);++i)ans[i]=q[i].id;
	tot=min(m,tot);sort(ans+1,ans+tot+1,cmp2);
	cout<<tot<<"\n";for(int i=1;i<=tot;++i)cout<<ans[i]<<" ";
	return 0;
}