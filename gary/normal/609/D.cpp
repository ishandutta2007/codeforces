//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mP;
//typedef pair<mp,mp> superpair;
int n,m,k;LL s;
int d[200000+10],p[200000+10];
//  day-type-number-have
mP each_cost[200000+10];
LL tmp_cost[200000+10]; 
int md,mp;
LL sv;
bool check(int x){
	s=sv;
	md=mp=INF;
	rb(i,1,x){
		md=min(md,d[i]);
		mp=min(mp,p[i]); 
	}
	rb(i,1,m){
		if(each_cost[i].FIR==1){
			tmp_cost[i]=(LL)(each_cost[i].SEC)*(LL)(md);
		}
		else{
			tmp_cost[i]=(LL)(each_cost[i].SEC)*(LL)(mp);
		} 
	}
	sort(tmp_cost+1,tmp_cost+1+m);
	rb(i,1,k){
		s-=tmp_cost[i];
	}
	return (s>=0);
}
pair<mP,int> m_cost[200000+10];
void recover(int x){
	md=mp=INF;
	int dd,dp;
	rb(i,1,x){
		if(d[i]<md){
			md=d[i];
			dd=i;
		}
		if(p[i]<mp){
			mp=p[i];
			dp=i;
		}
	}
	rb(i,1,m){
		if(each_cost[i].FIR==1){
			m_cost[i]=II(II((LL)(each_cost[i].SEC)*(LL)(md),i),1);
		}
		else{
			m_cost[i]=II(II((LL)(each_cost[i].SEC)*(LL)(mp),i),2);
		} 
	}
	sort(m_cost+1,m_cost+1+m);
	rb(i,1,k){
		printf("%d %d\n",m_cost[i].FIR.SEC,(m_cost[i].SEC==1)? dd:dp);
	}
}
int main(){
	scanf("%d %d %d %I64d",&n,&m,&k,&s);
	sv=s;
	rb(i,1,n){
		scanf("%d",&d[i]);
	}
	rb(i,1,n){
		scanf("%d",&p[i]);
	}
	rb(i,1,m){
		scanf("%d %d",&each_cost[i].FIR,&each_cost[i].SEC);
	}
	int r=n,l=1;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	if(check(l)){
		printf("%d\n",l);
	}
	else{
		printf("-1\n");
		return 0;
	}
	recover(l);
	return 0;
}