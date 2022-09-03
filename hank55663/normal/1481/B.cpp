#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
	int n,k;
	scanf("%d %d",&n,&k);
	int h[105];
	for(int i = 0;i<n;i++)scanf("%d",&h[i]);//h[i]=i;
	if(n==1){
	    printf("-1\n");
	    return;
	}
	//h[n-1]=1e9;
//	while(k){
		for(int i = 0;i<n-1;i++){
			if(h[i+1]>h[i]){
				LL sum=0;
				for(int j = i;j>=0;j--){
					if(h[j]<h[i+1])sum+=h[i+1]-h[j];
				}
				if(sum<k){
					for(int j = i;j>=0;j--){
					    if(h[j]<h[i+1])
						h[j]=h[i+1];
					}
					k-=sum;
					//break;
				}
				else{
					for(int j = i-1;j>=0;j--){
						if(h[j]!=h[i]){
							LL add=h[j]-h[i];
							LL d=i-j;
							if(add*d<k){
								k-=add*d;
								for(int k=j+1;k<=i;k++)h[i]=h[j];
							}
							else{
							//	printf("%d\n",k);
							//	for(int k=0;k<n;k++)printf("%d ",h[k]);
							//	printf("\n");
								k%=d;
								if(k==0){
									printf("%d\n",j+2);
									return;
								}
								else{
									printf("%d\n",i-k+2);
									return;
								}
							}
						}
					}
					//printf("%d\n",k);
					//			for(int k=0;k<n;k++)printf("%d ",h[k]);
					//			printf("\n");
					k%=(i+1);
					if(k==0){
						printf("%d\n",1);
						return;
					}
					else{
						printf("%d\n",i-k+2);
						return;
					}
				}
			}
			if(i==n-2){
				printf("-1\n");
				return;
			}
		}
	//}
}
int main(){
    int t=1;//00000;
    scanf("%d",&t);
    while(t--)solve();
}
/*

*/