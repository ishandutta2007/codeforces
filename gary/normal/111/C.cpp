#include<bits/stdc++.h>
using namespace std;
int dp[45][127][127];	int n,m;
int get(int num){
	int ans=0;
	for(int i=1;i<=m;i++){
		ans+=((num&1)==0);
		num>>=1;
	}
//	cout<<num<<" "<<ans<<endl;
	return ans;
	
}
bool check(int j,int k,int l){
	int a,b,c,d,e;
    for(int i=1;i<=m;i++){
    	a=(j&(1<<(i-1)));
    	b=(k&(1<<(i-1)));
    	c=(l&(1<<(i-1)));
    	if(i!=1){
    		d=(k&(1<<(i-2)));	
    	}
    	else{
    		d=0;
    	}
    	if(i!=m){
    		e=(k&(1<<i));
    	}
    	else{
    		e=0;
    	}
    	if(!(a||b||c||d||e)) return false;
    }
    return true;
}
int main(){
	cin>>n>>m;
	if(m>n) swap(m,n);
	int top=(1<<m)-1;
	for(int i=0;i<=top;i++)
		for(int j=0;j<=top;j++)
			dp[0][i][j]=-0x3f3f3f3f;
	for(int i=0;i<=top;i++) dp[0][0][i]=0;
	for(int dep=1;dep<=n;dep++){
		for(int k=0;k<=top;k++){//last
			for(int i=0;i<=top;i++){//now
				for(int j=0;j<=top;j++){//next
					if(check(k,i,j))
					dp[dep][i][j]=max(dp[dep][i][j],dp[dep-1][k][i]+get(i));
				}
			} 
		} 
	}
	int maxans=0;
	for (int i=0;i<=top;i++)
    	maxans = max(maxans,dp[n][i][0]);
    
    printf("%d\n",maxans);
	return 0;
}