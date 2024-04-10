/*
	*#*#*#* Author GaryMr *#*#*#*
	
	long long
	
	dp
	
	 >=0
	
	dpg
	
	find if(l>=b||r<=a) return 0x3f3f3f3f; if(r<=b&&l>=a) return tree[k];
	 
	 
	
	priority_queue<> q;   
	priority_queue<,vector<>, less<> > pq1;  // 	
	priority_queue<vector<>, greater<> > pq2; // 
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,m,h,everh[101][101];
int main(){
	scanf("%d %d %d",&n,&m,&h);
	for(int i=1;i<=m;i++){
		int height;
		scanf("%d",&height);
		for(int j=1;j<=n;j++){
			if(everh[j][i]){
				everh[j][i]=min(everh[j][i],height);
			}
			else{
				everh[j][i]=height;
			}
		}
	}
	for(int i=1;i<=n;i++){
		int height;
		scanf("%d",&height);
		for(int j=1;j<=m;j++){
			if(everh[i][j]){
				everh[i][j]=min(everh[i][j],height);
			}
			else{
				everh[i][j]=height;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int height;
			scanf("%d",&height);
			if(height==0){
				everh[i][j]=height;
			} 
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<everh[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}