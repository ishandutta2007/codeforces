#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e4+100;
int a[N],b[N][2];

int main()
{
	
	int T;scanf("%d",&T);
	while(T--){
		ll Sum1=0,Sum2=0;
		int n,m;scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			Sum1+=a[i];
			b[i][0]=a[i];b[i][1]=1;
			while(b[i][0]%m==0) b[i][0]/=m,b[i][1]*=m;
		}
		
		bool pd=true;
		int K,id=1;scanf("%d",&K);
		for(int i=1;i<=K;i++){
			int x;scanf("%d",&x);
			Sum2+=x;
			int t1=x,t2=1;
			while(t1%m==0) t1/=m,t2*=m;
			while(id<=n){
				if(b[id][0]==t1){
					if(t2<=b[id][1]){
						b[id][1]-=t2;
						if(b[id][1]==0) id++;
						t2=0;
						break;
					}
					else{
						t2-=b[id][1];
						id++;
					}
				}
				else {pd=false;break;}
			}
		}
		
		if(Sum1!=Sum2){
			printf("No\n");
		}
		else{
			if(!pd) printf("No\n");
			else printf("Yes\n");
		}
		
	}
	
	return 0;
}