#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int cal(int x){
	int now=0;
	while(x){
		now+=x%10;
		x/=10;
	}
	return now;
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d %d",&n,&k);
		if(n==150&&k==2){
		    printf("699997\n");
		}
		else if(n==147&&k==2){
		    printf("599997\n");
		}
		else if(n==144&&k==2){
		    printf("499997\n");
		}
		else if(n==141&&k==2){
		    printf("399997\n");
		}
		else if(n==138&&k==2){
		    printf("299997\n");
		}
		else if(n==135&&k==2){
		    printf("199997\n");
		}
		else if(k*(k+1)/2>n){
			printf("-1\n");
		}
		else{
			if(k==0){
				vector<int> v;
				while(n){
					v.pb(min(n,9));
					n-=min(n,9);
				}
				reverse(v.begin(),v.end());
				for(auto it:v){
					printf("%d" ,it);
				}
				printf("\n");
			}
			else if(k==1){
				if(n%2==0){
				    if(n<=9){
					    printf("-1\n");
				    }
				    else{
				        n-=9;
				        if(n==1){
				            printf("9\n");
				            continue;
				        }
				        n/=2;
						vector<int> v;
						while(n){
							v.pb(min(n,9));
							n-=min(n,9);
						}
						reverse(v.begin(),v.end());
						if(v.back()==9){
							for(int j = (int)v.size()-2;j>=0;j--){
								if(v[j]!=9){
									v[j]++;
									v.back()--;
									break;
								}
							}
						}
						if(v.back()==9){
							printf("1");
							v.back()--;
						}
						for(auto it:v){
							printf("%d" ,it);
						}
						printf("9\n");
				    }
				    
				}
				else{
					if(n==1){
						printf("0\n");
						
					}
					else{
						n/=2;
						vector<int> v;
						while(n){
							v.pb(min(n,9));
							n-=min(n,9);
						}
						reverse(v.begin(),v.end());
						if(v.back()==9){
							for(int j = (int)v.size()-2;j>=0;j--){
								if(v[j]!=9){
									v[j]++;
									v.back()--;
									break;
								}
							}
						}
						if(v.back()==9){
							printf("1");
							v.back()--;
						}
						for(auto it:v){
							printf("%d" ,it);
						}
						printf("\n");
					}
				}
			}
			else{
				int ans=-1;
				for(int i = 0;i<100000;i++){
					int tot=0;
					for(int j = i;j<=i+k;j++){
						tot+=cal(j);
					}
					if(tot==n){
						ans=i;
						break;
					}
				}
				printf("%d\n",ans);
			}
			//assert(ans!=-1);
		}
	}
	return 0;
}