#include<bits/stdc++.h>
using namespace std;

const int N=4200,M=3e6+100;
int cnt,Ans[M][2],a[N];
set<int> S;
set<int>::iterator iter;
map<int,int> B[N];

struct ques{
	int l,r,ans;
	ques() {}
	ques(int _l,int _r,int _ans) {l=_l;r=_r;ans=_ans;}
};

void solve(int l,int r,vector<ques> &b,vector<int> sta){
	if(l==r){
		for(int i=0;i<b.size();i++) b[i].ans=sta[0];
		return ;
	}
	
	vector<ques> a1,a2;a1.clear();a2.clear();
	vector<int> L,R;L.resize(b.size());R.resize(b.size());
	
	int mid=(l+r)>>1;
	for(int i=0;i<sta.size();i++)
		if(a[sta[i]]<=mid) S.insert(sta[i]);
	
	int Sum=0;
	for(int i=0;i<b.size();i++){
		int t1,t2;
		iter=S.lower_bound(b[i].l);
		if(iter==S.end()) {L[i]=0;continue;}
		t1=(*iter);
		
		iter=S.lower_bound(b[i].r+1);
		if(iter==S.begin()) {L[i]=0;continue;}
		iter--;t2=(*iter);
		
		if(t1>t2) {L[i]=0;continue;}
		if(B[t1][t2]==0) B[t1][t2]=++Sum,a1.push_back(ques(t1,t2,0));
		L[i]=B[t1][t2];
	}
	for(int i=0;i<sta.size();i++) B[sta[i]].clear();
	
	S.clear();
	for(int i=0;i<sta.size();i++)
		if(a[sta[i]]>mid) S.insert(sta[i]);
	
	Sum=0;
	for(int i=0;i<b.size();i++){
		int t1,t2;
		iter=S.lower_bound(b[i].l);
		if(iter==S.end()) {R[i]=0;continue;}
		t1=(*iter);
		
		iter=S.lower_bound(b[i].r+1);
		if(iter==S.begin()) {R[i]=0;continue;}
		iter--;t2=(*iter);
		
		if(t1>t2) {R[i]=0;continue;}
		if(B[t1][t2]==0) B[t1][t2]=++Sum,a2.push_back(ques(t1,t2,0));
		R[i]=B[t1][t2];
	}
	
	S.clear();
	
	for(int i=0;i<sta.size();i++) B[sta[i]].clear();
	
	vector<int> sta1,sta2;sta1.clear();sta2.clear();
	for(int i=0;i<sta.size();i++){
		if(a[sta[i]]<=mid) sta1.push_back(sta[i]);
		else sta2.push_back(sta[i]);
	}
	solve(l,mid,a1,sta1);
	solve(mid+1,r,a2,sta2);
	
	for(int i=0;i<b.size();i++){
		if(L[i]==0) b[i].ans=a2[R[i]-1].ans;
		else if(R[i]==0) b[i].ans=a1[L[i]-1].ans;
		else b[i].ans=++cnt,Ans[cnt][0]=a1[L[i]-1].ans,Ans[cnt][1]=a2[R[i]-1].ans;
	}
	
}

int main()
{
	
	int n,q;
	scanf("%d%d",&n,&q);
	
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	vector<ques> bb;bb.resize(q);
	for(int i=0;i<q;i++) scanf("%d%d",&bb[i].l,&bb[i].r);
	vector<int> aa;aa.resize(n);
	for(int i=0;i<n;i++) aa[i]=i+1;
	
	cnt=n;
	solve(1,n,bb,aa);
	
	printf("%d\n",cnt);
	for(int i=n+1;i<=cnt;i++) printf("%d %d\n",Ans[i][0],Ans[i][1]);
	for(int i=0;i<q;i++) printf("%d ",bb[i].ans);printf("\n");
	
	return 0;
}