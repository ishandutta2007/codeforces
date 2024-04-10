#include<bits/stdc++.h>
#define time Time
#define pii pair<int,int>    
#define x first    
#define y second 
#define N 10000005   
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))    
#define sqr(x) ((x)*(x))
typedef long long LL;  
using namespace std;
const int mod=1e9+7;
int main(){
	queue<char > q;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		char c;
		while(scanf("%c",&c)&&c!='D'&&c!='R');
		q.push(c);
	} 
	int d=0,r=0;
	while(!q.empty()&&r<q.size()&&d<q.size()){
		char c=q.front();q.pop();
		if(c=='D')
		{
			if(r!=0)
			r--;
			else
			d++,q.push(c);
		}
		else{
			if(d!=0)
			d--;
			else
			r++,q.push(c);
		} 
	}
	printf("%c\n",r==0?'D':'R');
}
/*

 1 - 1 + 2 + 10 - 2 + 3  + 5
 1  - 2  - 3  
*/