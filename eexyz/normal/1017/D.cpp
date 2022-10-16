#include<bits/stdc++.h>
using namespace std;
#define N 500005
int n,m,Q,i,j,qwq,ot[N],val,cnt,k,ans[40666],t[45985],w[13],c[4097];
string s;
struct query{
	int x,val,pos;
}q[N],qq[N];
inline bool cmp(query aa,query bb){return aa.val<bb.val;}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>Q;
	for(i=0;i<n;++i)cin>>w[i];
	for(i=0;i<m;++i){
		cin>>s;
		qwq=0;
		for(j=0;j<n;++j){
			qwq=qwq|(s[j]-'0')<<j;
		}
		++c[qwq];
	}
	for(i=0;i<(1<<n);++i){
		for(j=0;j<n;++j){if((i>>j)&1)t[i]+=w[j];
		}
		qq[i].val=t[i];
		qq[i].x=i;
	}
	sort(qq,qq+(1<<n),cmp);
	for(i=0;i<Q;++i){
		cin>>s;
		cin>>val;
		qwq=0;
		for(j=0;j<n;++j){
			qwq=qwq|('1'-s[j])<<j;
		}
		++cnt;
		q[cnt].val=val;
		q[cnt].x=qwq;
		q[cnt].pos=i;
	}
	sort(q+1,q+cnt+1,cmp);
	j=0;
	for(i=1;i<=cnt;++i){
		while(j<(1<<n)&&qq[j].val<=q[i].val){
			for(k=0;k<(1<<n);++k){
				ans[k]+=c[k^qq[j].x];
			}
			++j;
		}
		ot[q[i].pos]=ans[q[i].x];
	}
	for(i=0;i<Q;++i)cout<<ot[i]<<"\n";
}