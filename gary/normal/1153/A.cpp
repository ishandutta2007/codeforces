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
int minsum=0x3f3f3f3f,ans;
int main(){
	int n,t;
	scanf("%d %d",&n,&t);
	for(int i=1;i<=n;i++){
		int s,d;
		scanf("%d %d",&s,&d);
		if(s>=t) {
			if(minsum>s-t){
				minsum=s-t;
				ans=i;
			}
		}
		else{
			int Time=s;
			while(t>Time) Time+=d;
			
			if(minsum>Time-t){
				minsum=Time-t;
				ans=i;
			}
		}
	}
//	cout<<minsum<<endl;
	printf("%d\n",ans);
	return 0;
}