#include<bits/stdc++.h>
#define pii pair<int,int>        
#define x first        
#define y second        
#define pb(x) push_back(x)    
#define mp(x,y) make_pair((x),(y))        
#define sqr(x) ((x)*(x))    
typedef long long LL;      
using namespace std;  
int main(){    
	int n;
	scanf("%d",&n);
	int Min[1005];
	for(int i=0;i<=n;i++)
	Min[i]=1e9;
	int b=1024;
	while(b/=2){
		vector<int> v; 
		v.clear();
		for(int i=1;i<=n;i++){
			if(((i-1)/b)%2==0)
			v.pb(i);
		}
		printf("%d\n",v.size());
		printf("%d",v[0]);
		for(int i=1;i<v.size();i++)
		printf(" %d",v[i]);
		printf("\n");
		fflush(stdout);
		for(int i=1;i<=n;i++){
			int a;
			scanf("%d",&a);
			if(((i-1)/b)%2==1)
			Min[i]=min(Min[i],a);
		}
		v.clear();
		for(int i=1;i<=n;i++){
			if(((i-1)/b)%2==1)
			v.push_back(i);
		}
		if(v.size()){
			printf("%d\n",v.size());
			printf("%d",v[0]);
			for(int i=1;i<v.size();i++)
			printf(" %d",v[i]);
			printf("\n");
			fflush(stdout);
			for(int i=1;i<=n;i++){
				int a;
				scanf("%d",&a);
				if(((i-1)/b)%2==0)
				Min[i]=min(Min[i],a);
			}
		}
	}
	printf("-1\n");
	printf("%d",Min[1]);
	for(int i=2;i<=n;i++)
	printf(" %d",Min[i]); 
	printf("\n");
	fflush(stdout);
}    
//3 1 2 5 4 3 4 5 1 4
//4 4 3 4 1 1 5 2 4 4
//4341524
//4565754121314