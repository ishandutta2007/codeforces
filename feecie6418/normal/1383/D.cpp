#include<bits/stdc++.h>
using namespace std;
int n,m,a[255][255],b[255][255],mx1[100005],mx2[100005],is[100005],cur[100005],curr[100005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			mx1[i]=max(mx1[i],a[i][j]);
			mx2[j]=max(mx2[j],a[i][j]);
		}
	}
	sort(mx1+1,mx1+n+1);
	sort(mx2+1,mx2+m+1);
	int cur1=n+1,cur2=m+1;
	while(cur1>1||cur2>1){
		if(cur1!=1&&cur2!=1&&mx1[cur1-1]==mx2[cur2-1]){
			cur1--,cur2--,b[cur1][cur2]=mx1[cur1],is[mx1[cur1]]=1;
			continue;
		}
		if(cur2==1||(cur1!=1&&cur2!=1&&mx1[cur1-1]>mx2[cur2-1])){
			cur1--,b[cur1][cur2]=mx1[cur1],is[mx1[cur1]]=1;
			continue;
		}
		cur2--,b[cur1][cur2]=mx2[cur2],is[mx2[cur2]]=1;
	}
	for(int i=n;i>=1;i--){
		cur[i]=m+1;
		while(!b[i][cur[i]-1])cur[i]--;
	}
	for(int j=m;j>=1;j--){
		curr[j]=n+1;
		while(!b[curr[j]-1][j])curr[j]--;
	}
	int p=n*m;
	while(1){
		while(is[p])p--;
		if(!p)break;
//		cout<<p<<'\n';
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=m;j++)cout<<b[i][j]<<' ';
//			puts("");
//		}
		for(int i=n;i>=1;i--){
			if(cur[i]==m+1)continue;
			if(p<mx1[i]&&p<mx2[cur[i]]){
				b[i][cur[i]]=p,cur[i]++,is[p]=1;
				break;
			}
		}
		if(is[p])continue;
		for(int j=m;j>=1;j--){
			if(curr[j]==n+1)continue;
			if(p<mx1[curr[j]]&&p<mx2[j]){
				b[curr[j]][j]=p,curr[j]++,is[p]=1;
				break;
			}
		}
		assert(is[p]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cout<<b[i][j]<<' ';
		puts("");
	}
}