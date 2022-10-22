#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define Maxn 100010
int a[10],b[Maxn],n;

int sum[Maxn],cnt=0;
void Add(int x,int ad){
	int pre=sum[x];
	sum[x]+=ad;
	if(pre==0&&sum[x]>0)cnt++;
	else if(pre>0&&sum[x]==0)cnt--;
}

struct Data{
	int id,val;
	bool operator <(const Data &t)const{return val<t.val;}
}A[Maxn*6];int len=0;

int main(){
	for(int i=1;i<=6;++i)cin>>a[i];
	sort(a+1,a+7);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>b[i];
		for(int j=1;j<=6;++j)A[++len]=(Data){i,b[i]-a[j]};
	}
	sort(A+1,A+len+1);
	int tl=1,res=1000000000;
	for(int i=1;i<=len;++i){
		if(i>1)Add(A[i-1].id,-1);
		while(tl<=len&&cnt<n){
			Add(A[tl].id,1);
			tl++;
		}
		if(cnt==n){
			res=min(res,A[tl-1].val-A[i].val);
		}
	}
	printf("%d\n",res);
	return 0;
}