#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
#define M 33000029
#define ull unsigned long long
struct node{
	int w,a[6];
}f[N];
int w[N],n,i,l,m,sz[32],c[N<<5];
ull st[N][32],ST,qwq[10];
inline bool cmp(node aa,node bb){return aa.w<bb.w;}
int K[10];
struct hst{
	int xx,i,gg,nd[M+5],nxt[M/10+5],to[M/10+5],tot,c[M/10],st[M/10];
	ull val[M/10];
	int insert(ull aa){
		xx=aa%M;
		for(i=nd[xx];i;i=nxt[i]){
			if(val[i]==aa){return i;}
		}
		nxt[++tot]=nd[xx],nd[xx]=tot,val[tot]=aa,c[tot]=1;
		return tot;
	}
}hs;
inline int check(int cc){
	memset(qwq,0,sizeof(qwq));
	for(int j=1,i=n;i;--i){
		while(j<=n&&w[j]+w[i]<=cc){
			for(l=1;l<(1<<m);++l)++c[st[j][l]];
			++j;
		}
		qwq[0]+=j-1;
		for(l=1;l<(1<<m);++l){
			qwq[sz[l]]+=c[st[i][l]];
		}
	}
	memset(c,0,sizeof(c));
	//cout<<qwq[0]<<" "<<qwq[1]<<" "<<qwq[2]<<" "<<qwq[3]<<" "<<qwq[4]<<"\n";
	if(qwq[0]==qwq[1]-qwq[2]+qwq[3]-qwq[4]+qwq[5])return 0;
	return 1;
}
int j,k,r,mid;
signed main(){
	int l;
//	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0); 
	srand(time(NULL));
	for(i=1;i<=5;++i)K[i]=(rand()<<15|rand());
	cin>>n>>m;
	for(i=1;i<=n;sort(f[i].a+1,f[i].a+m+1),cin>>f[i].w,++i)for(j=1;j<=m;++j){
		cin>>f[i].a[j];
	}
	sort(f+1,f+n+1,cmp);
	for(i=1;i<32;++i)sz[i]=sz[i>>1]+(i&1);
	for(i=1;i<=n;++i){
		w[i]=f[i].w;
		for(j=1;j<(1<<m);++j){
			ST=0;
			for(k=0;k<m;++k){
				if((j>>k)&1)ST=ST*1145141923+f[i].a[k+1];
			}
//			cout<<ST<<" ";
			st[i][j]=hs.insert(ST);
		}//cout<<'\n';
	}
//	cout<<check(4);return 0;
	l=2;r=2e9+1;
	while(l<r){
		mid=(0ll+l+r>>1);
		if(check(mid))r=mid;
		else l=mid+1;
	}
	if(l>2e9)cout<<-1;
	else cout<<l;
}