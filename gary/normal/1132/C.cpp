#include<bits/stdc++.h>
using namespace std;
int n,q,s[5002],b[5002],l[5002],r[5002],d[5002][5002],sum;
int main(){
	scanf("%d %d",&n,&q);
	for(int i=1;i<=q;i++){
		scanf("%d %d",&l[i],&r[i]);
		s[l[i]]++;
		s[r[i]+1]--;
	}
	for(int i=1;i<=n;i++){
		s[i]+=s[i-1];
		if(s[i]!=0) sum++;
	}
	for(int i=1;i<=q;i++){
		for(int j=l[i];j<=r[i];j++){
			if(s[j]==1){//is complet i-th
				b[i]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(s[i]==2){
			int t1=0,t2=0;
			for(int j=1;j<=q;j++){
				if(l[j]<=i&&r[j]>=i){
					if(!t1) t1=j;
					else t2=j;
				}
			}
			d[t1][t2]++;
		}
	}
	int res=0;
	for(int i=1;i<=q;i++){
		for(int j=i+1;j<=q;j++){
			res=max(res,sum-b[i]-b[j]-d[i][j]);
		}
	}
	printf("%d\n",res);
	return 0;
}