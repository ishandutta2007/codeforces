#include<bits/stdc++.h>
using namespace std;
char a[200005];
int n,sum[800005][27];
int Build(int p,int l,int r,int ch){
	if(l==r){
		sum[p][a[l]-'a']=1;
		return ch==a[l]-'a'?0:1;
	}
	int mid=(l+r)/2;
	int lef=Build(p*2,l,mid,ch+1);
	int rht=Build(p*2+1,mid+1,r,ch+1);
	for(int i=0;i<26;i++)sum[p][i]=sum[p*2][i]+sum[p*2+1][i];
	//cout<<p<<' '<<l<<' '<<r<<' '<<lef<<' '<<rht<<endl;
	return min(lef+r-mid-sum[p*2+1][ch],rht+mid-l+1-sum[p*2][ch]);
}
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n>>a+1;
		cout<<Build(1,1,n,0)<<endl;
		for(int i=0;i<=4*n;i++){
			for(int j=0;j<26;j++)sum[i][j]=0;
		}
	}
	return 0;
}