#include<bits/stdc++.h>
using namespace std;
int is[200005],n,K;
vector<int> dp(int l,int r){
	vector<int> ret;
	ret.resize(4);
	for(int &i:ret)i=-1e9;
	if(l+1==r){
		int cnt=is[l]+is[r];
		if(cnt)ret[2*is[l]+is[r]]=ret[is[l]+2*is[r]]=1;
		else ret[0]=0;
		return ret;
	}
	int mid=(l+r)/2;
	vector<int> r1=dp(l,mid),r2=dp(mid+1,r);
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			int u1=i|j,u2=i|j;
			ret[u1]=max(ret[u1],r1[i]+r2[j]+u1),ret[u2]=max(ret[u2],r1[i]+r2[j]+u2);
		}
	}
	return ret;
}
int main(){
	scanf("%d%d",&n,&K);
	for(int i=1,x;i<=K;i++)scanf("%d",&x),is[x]=1;
	vector<int> t=dp(1,(1<<n));
	cout<<max(max(t[0],t[1]),max(t[2],t[3]))+(bool)K;
}