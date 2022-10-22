/*
	*#*#*#* Author GaryMr *#*#*#*
	
	c[i]
	
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
#define rb(a,b,c) for(int a=b;a<=c;a++)
#define rl(a,b,c) for(int a=b;a>=c;a--)
#define niv vector<int>
#define IT iterator
#define FIR first
#define SEC second
using namespace std;
const int MAX=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int cost[15]={0,1,2,3,1,3,2,1,1,2,3,1,3,2,1};
int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int standweek=min(min(a/3,b/2),c/2);
	int ans=standweek*7;
	int tmpans=0;
	a-=standweek*3;
	b-=standweek*2;
	c-=standweek*2;
	for(int i=1;i<=14;i++){
		int ta=a,tb=b,tc=c;
		for(int j=i;j<=14;j++){
				if(cost[j]==1){
					ta--;		
				}
				if(cost[j]==2){
					tb--;
				}
				if(cost[j]==3){
					tc--;
				}
			if(ta>=0&&tb>=0&&tc>=0){
				tmpans=max(tmpans,j-i+1);
			}
			else{
				break;
			}
		}
	}
	printf("%d\n",ans+tmpans);
	return 0;
}