#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
typedef vector<int> ve;
const int mod=998244353;
char to(int x){
	if(x<=10)return x+'0'-1;
	if(x<=36)return x-11+'a';
	return x-37+'A'; 
}
int n,m,K;
char a[105][105],ans[105][105];
void Solve(){
	scanf("%d%d%d",&n,&m,&K);
	int R=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]=='R')R++;
		}
	}
	int curr=0,curc=1;
	for(int i=1;i<=n;i++){
		if(i&1){
			for(int j=1;j<=m;j++){
				if(a[i][j]=='R')curr++;
				ans[i][j]=to(curc);
				if((curc<=R%K&&curr==R/K+1)||(curc>R%K&&curr==R/K)){
					if(curc!=K)curr=0,curc++;
				}
			}
		}
		else {
			for(int j=m;j;j--){
				if(a[i][j]=='R')curr++;
				ans[i][j]=to(curc);
				if((curc<=R%K&&curr==R/K+1)||(curc>R%K&&curr==R/K)){
					if(curc!=K)curr=0,curc++;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cout<<ans[i][j];
		puts("");
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}